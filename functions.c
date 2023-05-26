#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void ispisFilmova(FILM* filmovi, int brojacFilmova){
	if (brojacFilmova == 0)
	{
		printf("Nema filmova za pokazati.");
		return;
	}
	printf("\nLista filmova: \n\n");
	for (int i = 0; i < brojacFilmova; i++)
	{
		printf("ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
	}

	FILE* output = fopen("output.txt", "w"); 
	if (output == NULL)
	{
		printf("Ne moze se otvoriti file!\n");
		return;
	}
	fprintf(output, "Lista Filmova: \n\n");
	for (int i = 0; i < brojacFilmova; i++)
	{
		fprintf(output, "ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
	}
	fclose(output);
	

}
void dodajFilm(FILM** filmovi, int *brojacFilmova, int *maxFilms){
	if (*brojacFilmova == *maxFilms)
	{
		printf("Max filmovi, ne mozemo dodavati vise filmova!\n");
		return;
	}

	printf("Unesite parametre za film:\n");
	FILM noviFilm;

	printf("Unesite ime novog filma: ");
	scanf(" %[^\n]", noviFilm.ime);

	//unosenje godine i provjera pravilnog unosa
	printf("Unesite fodinu novog filma: ");
	do
	{
		scanf("%d", &noviFilm.godina);
		if (noviFilm.godina < 1880 || noviFilm.godina > 2025)
		{
			printf("Nije moguca godina filma, upise ponovno!\n");
		}
		
	} while (noviFilm.godina < 1880 || noviFilm.godina > 2025);
	//zavrsetak provjera

	printf("Unesite zanr novog filma(1): ");
	scanf(" %[^\n]", noviFilm.zanr);

	(*filmovi)[*brojacFilmova] = noviFilm;
	(*brojacFilmova)++;

	printf("Dodan film.\n");
}

void brisiFilm(FILM** filmovi, int *brojacFilmova, int* max){
	if (*brojacFilmova == 0)
	{
		printf("Nema filmova u bazi!");
		return;
	}
		
	printf("Unesite index filma kojeg zelite obrisati: \n");
	int index;
	
	do
	{
		scanf("%d", &index);
		if (index < 0 || index >= *brojacFilmova) {
            printf("Index ne postoji, pokušajte opet.\n");
        }
	} while(index < 0 || index >= *brojacFilmova);

	for (int i = index; i < *brojacFilmova - 1; i++) {
		(*filmovi)[i] = (*filmovi)[i + 1];
	}
	(*brojacFilmova)--;
	printf("Film obrisan!\n");
} 

void sortGodina(FILM* filmovi, int brojacFilmova){
	FILM tempFilm;
	for (int i = 0; i < brojacFilmova - 1; i++)
	{
		for (int j = 0; j < brojacFilmova - i - 1; j++)
		{
			if (filmovi[j].godina > filmovi[j+1].godina)
			{
				tempFilm = filmovi[j];
				filmovi[j] = filmovi[j+1];
				filmovi[j+1] = tempFilm;
			}
		}
	}
	printf("Filmovi su sortirani po godina!");

} 

void sortZanr(FILM* filmovi, int brojacFilmova){
	FILM tempZanr;
	for (int i = 0; i < brojacFilmova - 1; i++)
	{
		for (int j = 0; j < brojacFilmova - i - 1; j++)
		{
			if (strcmp(filmovi[j].zanr, filmovi[j + 1].zanr) > 0) //srtcmp dosl samo compare-a ascii vrijednosti prvog i drugog zanra i onda ranka
			{
				tempZanr = filmovi[j];
				filmovi[j] = filmovi[j + 1];
				filmovi[j + 1] = tempZanr;
			}
		}
	}
	printf("Filmovi sortirani prema zanru(A-Z)!");
} 

//---------------------------------------------------------------------------------------------------------------------

void pretrazivanjeFilmova(FILM* filmovi, int brojacFilmova){

	int izborKriterija;
	do
	{
		//izbornik za pretrazivanje
		printf("\n");
		printf("Po kojem kriteriju zelite pretrazivati filmove: \n");
		printf("1. Ime\n");
		printf("2. ID\n");
		printf("3. Godina\n");
		printf("4. Zanr\n");
		printf("5. Nista od navedenog -- nazad na prosli izbornik\n");
		printf("Izbor: ");
		scanf("%d", &izborKriterija);

		switch (izborKriterija)
		{
		case 1:
			trazenjeImeFilma(filmovi, brojacFilmova);
			break;
		
		case 2:
			trazenjeIDFilma(filmovi, brojacFilmova);
			break;

		case 3:
			trazenjeGodinaFilma(filmovi, brojacFilmova);
			break;

		case 4:
			trazenjeZanrFilma(filmovi, brojacFilmova);
			break;

		case 5:
			zavrseteTrazenjaFilma();
			break;

		default:
			printf("Krivi upis -- mora biti izmedu 1-5!\n");
			break;
		}

	} while (izborKriterija != 5);

}

//funkcija izbornika funkcije pretrazivanjeFilmova

void trazenjeImeFilma(FILM* filmovi, int brojacFilmova){
	char trazenjeIme[70];
	printf("Upisite ime filma kojeg trazite(pazite na mala i velika slova): ");
	scanf(" %[^\n]", trazenjeIme);


	//odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE* pronadeni = fopen("pronadeni.txt", "w"); 
	if (pronadeni == NULL)
	{
		printf("Ne moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Film kojeg ste trazili: \n\n");


	//krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].ime, trazenjeIme) == 0)	//opet usporedujemo tocnije filmovi[i].ime - trazenjeIme -- znaci ascii vrijednosti se oduzimaju ako je 0 rezultat znaci da je ime trazeno isto kao ime filma
		{
			printf("ID: %d. %s (%d) \t Zanr: %s\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s takvim imenom!\n");
	}
	fclose(pronadeni);
}

void trazenjeIDFilma(FILM* filmovi, int brojacFilmova){




}

void trazenjeGodinaFilma(FILM* filmovi, int brojacFilmova){



}

void trazenjeZanrFilma(FILM* filmovi, int brojacFilmova){




}


//izbornici zavrsavanje programa

char zavrseteTrazenjaFilma(){
	return printf("Vraćanje na pocetni izbornik...\n");
}