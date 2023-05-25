#include <stdio.h>
#include <stdlib.h>
#include "header.h" 

void pravljenjeListe(); //pravljenje liste iz filmovi.txt - zove se odma
int dodajFilm(); //dodavanje filma
int brisiFilm(); //brisanje filma
void sortGodina(); // sortiraj prema godinama
void sortZanr(); //sortiranje po zanreu
void close(); //zatvaranje programa

int main(){

    //inicializiranje filmovi.txt

    FILE *filmovi = fopen("filmovi.txt", "r");
    if (filmovi != NULL)
    {
        
    }else{
        printf("Nemoguce otvoriti file.");
        fclose(filmovi);
        return 1;
    }
    


    int odabir;

    //izbornik -----------------------------------------

    printf("BAZA PODATAKA KINA -- FILMOVI\n\n");
    printf("Odaberite opcu koju zelite: \n");
    printf("1. Ispis trenutno dostupnih filmova. \n");
    printf("2. Dodavanje filma. \n");
    printf("3. Brisanje filma. \n");
    printf("4. Sortiranje filmova po godinama izdanja. \n");
    printf("5. Sortiranje filmova po zanru. \n");
    printf("6. Zatvaranje programa. \n\n");
    printf("Izbor: ");

    //odabir -----------------------------------------------

    do
    {

        switch (odabir)
    {
        case 1:
            //dawda
        break;

        case 2:
            // statements
        break;

        case 3:
            //dawda
        break;

        case 4:
            // statements
        break;

        case 5:
            //dawda
        break;

        case 6:
            // statements
        break;

        default:
            printf("Krivi unos -- unesite brojeve 1-6\n");
    }

    } while (odabir == 6);


    return 0;
}