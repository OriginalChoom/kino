#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//10 //4
int main()
{
    //alokacija filmova //15 //14 //13
    int maxFilms = 10;
    FILM *filmovi = malloc(maxFilms * sizeof(FILM));
    if (filmovi == NULL)
    {
        perror("Alokacija nije uspjela"); //19
        return 1;
    }
    int brojacFilmova = 0;

    // inicializiranje filmovi.txt -- //16
    FILE *fileFilmovi = fopen("filmovi.txt", "r"); 
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
        perror("Nemoguce otvoriti file.");
    }

    char odabir[100];
    int closeLoop;

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
        printf("11. Preimenovanje i brisanje dokumenta(novog)\n");
        printf("12. Random film iz liste. \n");
        printf("13. Izaberite za zatvaranje programa. \n");
        printf("--------------------------------------------------------\n");
        printf("Izbor: ");

        // odabir -----------------------------------------------

        int duzina;
        scanf(" %99s", odabir);
        duzina = strlen(odabir);
        

        if (strcmp(odabir, "1") == 0) {
            ispisFilmova(filmovi, brojacFilmova);
            closeLoop = 1;
        }
        else if (strcmp(odabir, "2") == 0) {
            dodajFilm(&filmovi, &brojacFilmova, &maxFilms);
            closeLoop = 2;
        }
        else if (strcmp(odabir, "3") == 0) {
            brisiFilm(&filmovi, &brojacFilmova, &maxFilms);
            closeLoop = 3;
        }
        else if (strcmp(odabir, "4") == 0) {
            sortGodina(filmovi, brojacFilmova);
            closeLoop = 4;
        }
        else if (strcmp(odabir, "5") == 0) {
            sortZanr(filmovi, brojacFilmova);
            closeLoop = 5;
        }
        else if (strcmp(odabir, "6") == 0) {
            sortiranjeCijeneUlaza(filmovi, brojacFilmova);
            closeLoop = 6;
        }
        else if (strcmp(odabir, "7") == 0) {
            pretrazivanjeFilmova(filmovi, brojacFilmova);
            closeLoop = 7;
        }
        else if (strcmp(odabir, "8") == 0) {
            povecanjeBaze(&filmovi, &maxFilms);
            closeLoop = 8;
        }
        else if (strcmp(odabir, "9") == 0) {
            smanjenjeBaze(&filmovi, &maxFilms, &brojacFilmova);
            closeLoop = 9;
        }
        else if (strcmp(odabir, "10") == 0) {
            printf("Trenutna velicina baze: %d\n", maxFilms);
            closeLoop = 10;
        }
        else if (strcmp(odabir, "11") == 0) {
            preimenovanjeDatoteke();
            closeLoop = 11;
        }
        else if (strcmp(odabir, "12") == 0) {
            randomFilm(filmovi, brojacFilmova);
            closeLoop = 12;
        }
        else if (strcmp(odabir, "13") == 0) {
            close();
            closeLoop = 13;
        }
        else {
            printf("Krivi unos -- unesite brojeve 1-13\n");
        }
    } while(closeLoop != 13);

    free(filmovi); //15
    return 0;
}

inline void close() //7
{
    printf("Program se zatvara...");
}
