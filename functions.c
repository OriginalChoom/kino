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

	printf("Unesite fodinu novog filma: ");
	scanf("%d", &noviFilm.godina);

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

void sortGodina(){


} 

void sortZanr(){



} 
void close(){



    
} 
