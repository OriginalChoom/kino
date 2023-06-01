#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//za napravit 11, 7

//10 //4
int main()
{
    // alokacija filmova -- 15 -- 14 -- 13
    int maxFilms = 10;
    FILM *filmovi = malloc(maxFilms * sizeof(FILM));
    if (filmovi == NULL)
    {
        perror("Alokacija nije uspjela"); //19
        return 1;
    }
    int brojacFilmova = 0;

    // inicializiranje filmovi.txt -- 16
    FILE *fileFilmovi = fopen("filmovi.txt", "r"); // moro stavit cijelu adresu vs code nije htio drugacije
    if (fileFilmovi != NULL)
    {
        //17
        fseek(fileFilmovi, 0, SEEK_SET); //na pocetak dokumenta
        while (fscanf(fileFilmovi, "%[^,],%d,%[^,],%[^,],%lf\n", filmovi[brojacFilmova].ime, &filmovi[brojacFilmova].godina, filmovi[brojacFilmova].zanr, filmovi[brojacFilmova].nacinGledanja, &filmovi[brojacFilmova].placanjeUlaz) != EOF) // pise u filmovi struct redosljedom ime>godina>zanr -- to sve radi dok ne dode do EOF(end of file)
        {
            brojacFilmova++;
        }
        fclose(fileFilmovi);
    }
    else
    {
        printf("Nemoguce otvoriti file.");
    }

    char staroIme[] = "output.txt";
    int odabir;

    printf("BAZA PODATAKA KINA -- FILMOVI\n");
    printf("Maksimalni broj filmova u bazi %d", maxFilms);
    do
    {
        // izbornik ----------------------------------------- //8

        printf("\n--------------------------------------------------------\n");
        printf("Odaberite opcu koju zelite: \n");
        printf("1. Ispis trenutno dostupnih filmova. \n");
        printf("2. Dodavanje filma. \n");
        printf("3. Brisanje filma. \n");
        printf("4. Sortiranje filmova po godinama izdanja. \n");
        printf("5. Sortiranje filmova po zanru. \n");
        printf("6. Sortiranje po cijeni. \n");
        printf("7. Pretrazivanje filmova\n");
        printf("8. Povecanje baze. \n");
        printf("9. Smanjenje baze. \n");
        printf("10. Provjera velicine baze. \n");
        printf("11. Preimenovanje .txt dokumenta");
        printf("12. Izaberite za zatvaranje programa. \n");
        printf("--------------------------------------------------------\n");
        printf("Izbor: ");

        // odabir -----------------------------------------------

        scanf("%d", &odabir);

        switch (odabir)
        {
        case 1:
            ispisFilmova(filmovi, brojacFilmova);
            break;

        case 2:
            dodajFilm(&filmovi, &brojacFilmova, &maxFilms);
            break;

        case 3:
            brisiFilm(&filmovi, &brojacFilmova, &maxFilms);
            break;

        case 4:
            sortGodina(filmovi, brojacFilmova); //20
            break;

        case 5:
            sortZanr(filmovi, brojacFilmova); //20
            break;

        case 6:
            sortiranjeCijeneUlaza(filmovi, brojacFilmova);
            break;

        case 7:
            pretrazivanjeFilmova(filmovi, brojacFilmova); //21
            break;

        case 8:
            povecanjeBaze(&filmovi, &maxFilms);
            break;

        case 9:
            smanjenjeBaze(&filmovi, &maxFilms, &brojacFilmova);
            break;

        case 10:
            printf("Trenutna velicina baze: %d\n", maxFilms);
            break;

        case 11:
            preimenovanjeDatoteke(); //18
            break;

        case 12:
            close(); // samo return printf
            break;

        default:
            printf("Krivi unos -- unesite brojeve 1-6\n");
        }
    } while (odabir != 12);

    return 0;
    free(fileFilmovi); //15
}

char close()
{
    return printf("Program se zatvara...");
}
