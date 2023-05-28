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
		printf("Alokacija nije uspjela");
		return 1;
	}
    int brojacFilmova = 0;

	//inicializiranje filmovi.txt 
    FILE *fileFilmovi = fopen("E:\\Kino\\kino\\filmovi.txt", "r"); //moro stavit cijelu adresu vs code nije htio drugacije
    if (fileFilmovi != NULL)
    {
        while (fscanf(fileFilmovi, "%[^,],%d,%[^\n]\n", filmovi[brojacFilmova].ime, &filmovi[brojacFilmova].godina, filmovi[brojacFilmova].zanr) != EOF) //pise u filmovi struct redosljedom ime>godina>zanr -- to sve radi dok ne dode do EOF(end of file)
        {
            brojacFilmova++;
        }
		fclose(fileFilmovi);
    }else{
        printf("Nemoguce otvoriti file.");
    }
    
    int odabir;
    
	printf("BAZA PODATAKA KINA -- FILMOVI\n\n");

    do
    {
		//izbornik -----------------------------------------

        printf("\n--------------------------------------------------------\n");
		printf("Odaberite opcu koju zelite: \n");
		printf("1. Ispis trenutno dostupnih filmova. \n");
		printf("2. Dodavanje filma. \n");
		printf("3. Brisanje filma. \n");
		printf("4. Sortiranje filmova po godinama izdanja. \n");
		printf("5. Sortiranje filmova po zanru. \n");
        printf("6. Pretrazivanje filmova\n");
		printf("7. Izaberite za zatvaranje programa. \n");
        printf("--------------------------------------------------------\n");
        printf("Izbor: ");

		//odabir -----------------------------------------------

        scanf_s("%d", &odabir);
        switch (odabir)
    {
        case 1:
            ispisFilmova(filmovi, brojacFilmova); //napravljeno ispisuje sve
        break;

        case 2:
            dodajFilm(&filmovi, &brojacFilmova, &maxFilms); //napraljveno dodaje jedan film
        break;

        case 3:
            brisiFilm(&filmovi, &brojacFilmova, &maxFilms); //napravljeno brise jedan film ovisno o ID-u 
        break;

        case 4:
			sortGodina(filmovi, brojacFilmova); //napravljeno stortira bez problema i u file i na
        break;

        case 5:
			sortZanr(filmovi, brojacFilmova); //sortira kako treba
        break;
        
        case 6:

            pretrazivanjeFilmova(filmovi, brojacFilmova);

        case 7:
			close(); //samo return printf
        break;

        default:
            printf("Krivi unos -- unesite brojeve 1-6\n");
    }

    } while (odabir != 7);

    return 0;
    free(fileFilmovi);
}

char close(){
	return printf("Program se zatvara...");    
} 
