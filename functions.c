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

	//unosenje zanra -- biranje umjesto samostalno utipkavanje onda je uvijek sve jednako -----------------
	int odabirZanraFilma;
	printf("Odaberite zanr novog filma: \n");

	do
	{
		printf("--------------------------------------------------------------\n");
		printf("\nZanrovi na odabir: \n\n");
		printf("1. Action\t");
		printf("2. Adventure\n");
		printf("3. Animation\t");
		printf("4. Comedy\n");
		printf("5. Drama\t");
		printf("6. Film-Noir\n");
		printf("7. Horror\t");
		printf("8. Mystery\n");
		printf("9. Sci-Fi\t");
		printf("10. War\n");
		printf("11. Western\t");
		printf("12. Music\n");
		printf("--------------------------------------------------------------\n");
		printf("Odabir: ");

		scanf("%d", &odabirZanraFilma);

		switch (odabirZanraFilma)
		{
		case 1:
			strcpy(noviFilm.zanr, "Action");
			break;
		case 2:
			strcpy(noviFilm.zanr, "Adventure");
			break;
		case 3:
			strcpy(noviFilm.zanr, "Animation");
			break;
		case 4:
			strcpy(noviFilm.zanr, "Comedy");
			break;
		case 5:
			strcpy(noviFilm.zanr, "Drama");
			break;
		case 6:
			strcpy(noviFilm.zanr, "Film-Noir");
			break;
		case 7:
			strcpy(noviFilm.zanr, "Horror");
			break;
		case 8:
			strcpy(noviFilm.zanr, "Mystery");
			break;
		case 9:
			strcpy(noviFilm.zanr, "Sci-Fi");
			break;
		case 10:
			strcpy(noviFilm.zanr, "War");
			break;
		case 11:
			strcpy(noviFilm.zanr, "Western");
			break;
		case 12:
			strcpy(noviFilm.zanr, "Music");
			break;
		default:
			printf("Ne postoji zanr! Odaberite iz liste.\n");
			break;
		}
	} while (odabirZanraFilma > 12);
	
	//zavrsetak unosa -------------------------------------------------------------------------------

	(*filmovi)[*brojacFilmova] = noviFilm;
	(*brojacFilmova)++;

	printf("Dodan film.\n");
}

//scanf(" %[^\n]", noviFilm.zanr); -> ovo bilo za unošenje zanra al bolje odabir onda je uvijek isto

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
		printf("---------------------------------------------------------------\n");
		printf("Po kojem kriteriju zelite pretrazivati filmove: \n");
		printf("1. Pretrazivanje po IMENU filma\n");
		printf("2. Pretrazivanje po ID-u filma\n");
		printf("3. Pretrazivanje po GODINI filma\n");
		printf("4. Pretrazivanje po ZANRU filma\n");
		printf("5. Nista od navedenog -- nazad na prosli izbornik\n");
		printf("---------------------------------------------------------------\n");
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


//IME
void trazenjeImeFilma(FILM* filmovi, int brojacFilmova){
	char trazenjeIme[70];
	printf("\nUpisite ime filma kojeg trazite(pazite na mala i velika slova): ");
	scanf(" %[^\n]", trazenjeIme);
	printf("\n");

	//odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE* pronadeni = fopen("pronadeni.txt", "w"); 
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");


	//krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].ime, trazenjeIme) == 0)	//opet usporedujemo tocnije filmovi[i].ime - trazenjeIme -- znaci ascii vrijednosti se oduzimaju ako je 0 rezultat znaci da je ime trazeno isto kao ime filma
		{
			printf("ID: %d. %s (%d) \t Zanr: %s\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			pronadeniFilm++;
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s takvim imenom!\n");
		fprintf(pronadeni,"U bazi nema filmova s takvim imenom!\n");
	}
	fclose(pronadeni);
}


//ID
void trazenjeIDFilma(FILM* filmovi, int brojacFilmova){
	int trazenjeID;
	printf("\nUpisite ID filma kojeg trazite: ");
	scanf("%d", &trazenjeID);
	printf("\n");

	//odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE* pronadeni = fopen("pronadeni.txt", "w"); 
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");


	//krece algoritam trazenja
	int pronadeniFilm;
	if (trazenjeID >= 0 && trazenjeID < brojacFilmova) 
	{
        	printf("ID: %d. %s (%d) \t Zanr: %s\n", trazenjeID, filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \n", trazenjeID,filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr);
			pronadeniFilm++;
    }
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s tim ID-om!\n");
		fprintf(pronadeni,"U bazi nema filmova s tim ID-om!\n");
	}
	fclose(pronadeni);
}


//GODINA
void trazenjeGodinaFilma(FILM* filmovi, int brojacFilmova){
	int trazenjeGodina;
	printf("Upisite godinu filmova koje trazite: ");
	scanf("%d", &trazenjeGodina);
	printf("\n");

	//odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE* pronadeni = fopen("pronadeni.txt", "w"); 
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");


	//krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (trazenjeGodina == filmovi[i].godina)
		{
			printf("ID: %d. %s (%d) \t Zanr: %s\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			pronadeniFilm++;
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova iz te godine!\n");
		fprintf(pronadeni,"U bazi nema filmova iz te godine!\n");
	}
	fclose(pronadeni);
}


//ZANR
void trazenjeZanrFilma(FILM* filmovi, int brojacFilmova){
	int trazenjeZanrOdabir;
	char trazenjeZanr[15];

	printf("Unesite zanr kojeg zelite traziti: ");
	printf("\n");

	do
	{
		printf("--------------------------------------------------------------\n");
		printf("\nZanrovi na odabir: \n\n");
		printf("1. Action\t");
		printf("2. Adventure\n");
		printf("3. Animation\t");
		printf("4. Comedy\n");
		printf("5. Drama\t");
		printf("6. Film-Noir\n");
		printf("7. Horror\t");
		printf("8. Mystery\n");
		printf("9. Sci-Fi\t");
		printf("10. War\n");
		printf("11. Western\t");
		printf("12. Music\n");
		printf("--------------------------------------------------------------\n");
		printf("Odabir: ");

		scanf("%d", &trazenjeZanrOdabir);

		switch (trazenjeZanrOdabir)
		{
		case 1:
			strcpy(trazenjeZanr, "Action");
			break;
		case 2:
			strcpy(trazenjeZanr, "Adventure");
			break;
		case 3:
			strcpy(trazenjeZanr, "Animation");
			break;
		case 4:
			strcpy(trazenjeZanr, "Comedy");
			break;
		case 5:
			strcpy(trazenjeZanr, "Drama");
			break;
		case 6:
			strcpy(trazenjeZanr, "Film-Noir");
			break;
		case 7:
			strcpy(trazenjeZanr, "Horror");
			break;
		case 8:
			strcpy(trazenjeZanr, "Mystery");
			break;
		case 9:
			strcpy(trazenjeZanr, "Sci-Fi");
			break;
		case 10:
			strcpy(trazenjeZanr, "War");
			break;
		case 11:
			strcpy(trazenjeZanr, "Western");
			break;
		case 12:
			strcpy(trazenjeZanr, "Music");
			break;
		default:
			printf("Ne postoji zanr! Odaberite iz liste.\n");
			break;
		}
	} while (trazenjeZanr > 12);

	//odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE* pronadeni = fopen("pronadeni.txt", "w"); 
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Film/ovi koje/g ste trazili: \n\n");

	//krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].zanr, trazenjeZanr) == 0)	
		{
			printf("ID: %d. %s (%d) \t Zanr: %s\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \n", i,filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr);
			pronadeniFilm++; 
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s takvim imenom!\n");
		fprintf(pronadeni,"U bazi nema filmova koji odgovaraju odabranom zanru!\n");
	}
	fclose(pronadeni);
}
//izbornici zavrsavanje programa

char zavrseteTrazenjaFilma(){
	return printf("\nVracanje na pocetni izbornik...\n\n");
}