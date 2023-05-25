#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){

	//alokacija filmova
	int maxFilms = 10;
	FILM* filmovi = malloc(maxFilms * sizeof(FILM));
	if (filmovi == NULL)
	{
		printf("Alokacija ne uspjela");
		return 1;
	}
    int brojacFilmova = 0;

	//inicializiranje filmovi.txt
    FILE *fileFilmovi = fopen("filmovi.txt", "r");
    if (fileFilmovi != NULL)
    {
        while (fscanf(fileFilmovi, "%[^,],%d,%[^\n]\n", filmovi[brojacFilmova].ime, &filmovi[brojacFilmova].godina, filmovi[brojacFilmova].zanr) != EOF)
        {
            brojacFilmova++;
        }
		fclose(fileFilmovi);
    }else{
        printf("Nemoguce otvoriti file.");
    }
    
    int odabir;

	printf("BAZA PODATAKA KINA -- FILMOVI\n\n");
//8
    do
    {
		//izbornik -----------------------------------------

		printf("\nOdaberite opcu koju zelite: \n");
		printf("1. Ispis trenutno dostupnih filmova. \n");
		printf("2. Dodavanje filma. \n");
		printf("3. Brisanje filma. \n");
		printf("4. Sortiranje filmova po godinama izdanja. \n");
		printf("5. Sortiranje filmova po zanru. \n");
		printf("6. Izaberite za zatvaranje programa. \n\n");
		printf("Izbor: ");

		//odabir -----------------------------------------------

        scanf_s("%d", &odabir);
        switch (odabir)
    {
        case 1:
            ispisFilmova(filmovi, brojacFilmova);
        break;

        case 2:
            dodajFilm(filmovi, &brojacFilmova, maxFilms);
        break;

        case 3:
            brisiFilm(filmovi, &brojacFilmova, maxFilms);
        break;

        case 4:
			sortGodina(filmovi, brojacFilmova);
        break;

        case 5:
			sortZanr(filmovi, brojacFilmova);
        break;

        case 6:
			close(filmovi);
        break;

        default:
            printf("Krivi unos -- unesite brojeve 1-6\n");
    }

    } while (odabir != 6);


    return 0;
}
