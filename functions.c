#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

//10  //9
inline void ispisFilmova(FILM *filmovi, int const brojacFilmova) //7
{
	if (brojacFilmova == 0)
	{
		printf("Nema filmova za pokazati.");
		return;
	}
	printf("\nLista filmova: \n\n");
	for (int i = 0; i < brojacFilmova; i++)
	{
		printf("ID: %2d.  %-40s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);

	}

	FILE *output = fopen("output.txt", "w");
	if (output == NULL)
	{
		printf("Ne moze se otvoriti file!\n");
		return;
	}
	fprintf(output, "Lista Filmova: \n\n");
	for (int i = 0; i < brojacFilmova; i++)
	{
		fprintf(output, "ID: %2d.  %-40s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
	}
	fclose(output);
	free(filmovi);
}
void dodajFilm(FILM **filmovi, int *brojacFilmova, int *maxFilms)
{
	if (*brojacFilmova == *maxFilms)
	{
		printf("Max filmovi, ne mozemo dodavati vise filmova!\n");
		return;
	}

	printf("Unesite parametre za film:\n");
	FILM noviFilm;

	printf("Unesite ime novog filma: ");
	scanf(" %[^\n]", noviFilm.ime);

	// unosenje godine i provjera pravilnog unosa
	printf("Unesite godinu novog filma: ");
	do
	{
		scanf("%d", &noviFilm.godina);
		if (noviFilm.godina < 1880 || noviFilm.godina > 2025)
		{
			printf("Nije moguca godina filma, upise ponovno!\n");
		}

	} while (noviFilm.godina < 1880 || noviFilm.godina > 2025);
	// zavrsetak provjera

	// unosenje zanra -- biranje umjesto samostalno utipkavanje onda je uvijek sve jednako -----------------


	static char odabirZanraFilma[100]; //5
	int odabirZanraFilmaLoopClose; 

	printf("Odaberite zanr novog filma: \n");

	//8
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

		scanf(" %99s", odabirZanraFilma);

		if (strcmp(odabirZanraFilma, "1") == 0) {
            strcpy(noviFilm.zanr, "Action");
            odabirZanraFilmaLoopClose = 1;
        }
        else if (strcmp(odabirZanraFilma, "2") == 0) {
            strcpy(noviFilm.zanr, "Adventure");
            odabirZanraFilmaLoopClose = 2;
        }
        else if (strcmp(odabirZanraFilma, "3") == 0) {
            strcpy(noviFilm.zanr, "Animation");
            odabirZanraFilmaLoopClose = 3;
        }
        else if (strcmp(odabirZanraFilma, "4") == 0) {
            strcpy(noviFilm.zanr, "Comedy");
            odabirZanraFilmaLoopClose = 4;
        }
        else if (strcmp(odabirZanraFilma, "5") == 0) {
			strcpy(noviFilm.zanr, "Drama");
            odabirZanraFilmaLoopClose = 5;
        }
        else if (strcmp(odabirZanraFilma, "6") == 0) {
            strcpy(noviFilm.zanr, "Film-Noir");
            odabirZanraFilmaLoopClose = 6;
        }
        else if (strcmp(odabirZanraFilma, "7") == 0) {
            strcpy(noviFilm.zanr, "Horror");
            odabirZanraFilmaLoopClose = 7;
        }
        else if (strcmp(odabirZanraFilma, "8") == 0) {
			strcpy(noviFilm.zanr, "Mystery");
            odabirZanraFilmaLoopClose = 8;
        }
        else if (strcmp(odabirZanraFilma, "9") == 0) {
            strcpy(noviFilm.zanr, "Sci-Fi");
            odabirZanraFilmaLoopClose = 9;
        }
        else if (strcmp(odabirZanraFilma, "10") == 0) {
            strcpy(noviFilm.zanr, "War");
            odabirZanraFilmaLoopClose = 10;
        }
        else if (strcmp(odabirZanraFilma, "11") == 0) {
            strcpy(noviFilm.zanr, "Western");
            odabirZanraFilmaLoopClose = 11;
        }
        else if (strcmp(odabirZanraFilma, "12") == 0) {
            strcpy(noviFilm.zanr, "Music");
            odabirZanraFilmaLoopClose = 12;
        }
        else {
        	printf("Ne postoji zanr! Odaberite iz liste.\n");
			odabirZanraFilmaLoopClose = 0;
        }

	} while (odabirZanraFilmaLoopClose == 0);


	static char odabirNacinGledanja[2];
	int duzina = 0;
	printf("Unesite nacin gledanja filma: ");
	do
	{
		do
		{
			printf("\n----------------------------------------------\n");
			printf("1. 2D\t");
			printf("2. 3D\t");
			printf("3. 4D\n");
			printf("------------------------------------------------\n");
			printf("Unos: ");

			scanf(" %s", odabirNacinGledanja);
			duzina = strlen(odabirNacinGledanja);
			if (duzina>1)
			{
				printf("Krivi unos!");
			}
			
		} while (duzina>1);

		switch (odabirNacinGledanja[0])
		{
		case '1':
			strcpy(noviFilm.nacinGledanja, "2D");
			break;
		
		case '2':
			strcpy(noviFilm.nacinGledanja, "3D");
			break;

		case '3':
			strcpy(noviFilm.nacinGledanja, "4D");
			break;

		default:
			printf("Krivi unos!");
			break;
		}

	} while (odabirNacinGledanja[0] > '3');

	static double cijenaUlaza;
	char inputCijena[100];
	int dobarInput = 0;

	printf("Unesite cijenu ulaza u kino: ");
	
	do
	{
		fgets(inputCijena, sizeof(inputCijena), stdin);
		if (sscanf(inputCijena, "%lf", &cijenaUlaza) == 1)
		{
			if (!(cijenaUlaza < 0 || cijenaUlaza > 100))
			{
				dobarInput = 1;
			}else{
				printf("Cijena mora biti razumna(0-100).\n");
				printf("Unesite cijenu: ");
			}
		}else{
			printf("Unesite broj ne string.\n");
			printf("Unesite cijenu: ");
		}
	} while (!dobarInput);
	noviFilm.placanjeUlaz = cijenaUlaza;

// zavrsetak unosa -------------------------------------------------------------------------------

	(*filmovi)[*brojacFilmova] = noviFilm;
	(*brojacFilmova)++;

	printf("Dodan film.\n");
}

void brisiFilm(FILM **filmovi, int *brojacFilmova, int *max)
{
	if (*brojacFilmova == 0)
	{
		printf("Nema filmova u bazi!");
		return;
	}

	printf("Unesite index filma kojeg zelite obrisati: \n");
	static int index;

	do
	{
		scanf("%d", &index);
		if (index < 0 || index >= *brojacFilmova)
		{
			printf("Index ne postoji, pokušajte opet.\n");
		}
	} while (index < 0 || index >= *brojacFilmova);

	for (int i = index; i < *brojacFilmova - 1; i++)
	{
		(*filmovi)[i] = (*filmovi)[i + 1];
	}
	(*brojacFilmova)--;
	printf("Film obrisan!\n");
}

//20
void sortGodina(FILM *filmovi, int const brojacFilmova)
{
	FILM tempFilm;
	for (int i = 0; i < brojacFilmova - 1; i++)
	{
		for (int j = 0; j < brojacFilmova - i - 1; j++)
		{
			if (filmovi[j].godina > filmovi[j + 1].godina)
			{
				tempFilm = filmovi[j];
				filmovi[j] = filmovi[j + 1];
				filmovi[j + 1] = tempFilm;
			}
		}
	}
	printf("Filmovi su sortirani po godina!");
}

void sortZanr(FILM *filmovi, int const brojacFilmova)
{
	FILM tempZanr;
	for (int i = 0; i < brojacFilmova - 1; i++)
	{
		for (int j = 0; j < brojacFilmova - i - 1; j++)
		{
			if (strcmp(filmovi[j].zanr, filmovi[j + 1].zanr) > 0) // srtcmp dosl samo compare-a ascii vrijednosti prvog i drugog zanra i onda ranka
			{
				tempZanr = filmovi[j];
				filmovi[j] = filmovi[j + 1];
				filmovi[j + 1] = tempZanr;
			}
		}
	}
	printf("Filmovi sortirani prema zanru(A-Z)!");
}

void sortiranjeCijeneUlaza(FILM* filmovi, int const brojacFilmova){

	FILM tempUlaz;
	for (int i = 0; i < brojacFilmova - 1; i++)
	{
		for (int j = 0; j < brojacFilmova - i - 1; j++)
		{
			if (filmovi[j].placanjeUlaz > filmovi[j + 1].placanjeUlaz)
			{
				tempUlaz = filmovi[j];
				filmovi[j] = filmovi[j + 1];
				filmovi[j + 1] = tempUlaz;
			}
		}
	}
	printf("Filmovi su sortirani po cijeni!");
}


void povecanjeBaze(FILM **filmovi, int *maxFilms)
{
	int povecanje;
	int noviMaxFilms;
	printf("Za koliko mjesta zelite povecati bazu: ");
	do
	{
		scanf("%d", &povecanje);
		if (povecanje < 0)
		{
			printf("Povecanje znaci 1 ili vise! Nema smanjivanje baze.\n");
			printf("Za koliko mjesta zelite povecati bazu: ");
		}

	} while (povecanje < 0);

	noviMaxFilms = *maxFilms + povecanje;

	//14
	FILM *noviFilmovi = realloc(*filmovi, noviMaxFilms * sizeof(FILM));
	if (noviFilmovi == NULL)
	{
		printf("Pogreška u relokaciji memorije\n");
		return;
	}

	printf("Novi maksimalni broj filmova je: %d\n", noviMaxFilms);

	*filmovi = noviFilmovi;
	*maxFilms = noviMaxFilms;
}

void smanjenjeBaze(FILM **filmovi, int *maxFilms, int *brojacFilmova)
{
	int smanjenje;
	int *pSmanjenje;
	int noviMaxFilms;
	printf("Za koliko mjesta zelite smanjiti bazu(moguce brisanje filmova!): ");
	do
	{
		scanf("%d", &smanjenje);
		pSmanjenje = &smanjenje;
		if (smanjenje <= 0 || *pSmanjenje > *maxFilms)
		{
			printf("Los unos, mora biti veci od 0.\n");
			printf("Za koliko mjesta zelite smanjiti bazu: ");
		}
	} while (smanjenje <= 0 || *pSmanjenje > *maxFilms);

	noviMaxFilms = *maxFilms - smanjenje;

	int izbrisaniFilmovi = *brojacFilmova - noviMaxFilms;
	if (noviMaxFilms < *brojacFilmova)
	{
		printf("Neki filmovi ce biti izbrisani!!! Broj izbrisanih filmova: %d\n", izbrisaniFilmovi);
		*brojacFilmova = noviMaxFilms;
	}

	//14
	FILM *noviFilmovi = realloc(*filmovi, noviMaxFilms * sizeof(FILM));
	if (noviFilmovi == NULL)
	{
		printf("Pogreška u relokaciji memorije\n");
		return;
	}

	printf("Novi maksimalni broj filmova je: %d\n", noviMaxFilms);

	*filmovi = noviFilmovi;
	*maxFilms = noviMaxFilms;
}

//18
void preimenovanjeDatoteke(){ 

	char ime[] = "novi";
	FILE *file = fopen(ime, "wb");
    if (file == NULL){
		perror("Nemoguce otvoriti file!");
	}
	fclose(file);

	char novoIme[30];
	printf("Preimenujemo datoteku!\n");
	printf("Novo ime: ");
	scanf(" %[^\n]", novoIme);

	int rezultatPreimenovanja = rename(ime, novoIme);
	if (rezultatPreimenovanja !=0)
	{
		printf("Neuspjesno preimenovanje datoteke.\n");
	}else{
	printf("Uspjesna promjena imena. --> Pogledajte novo ime. \n");
	}

	char unosBrisanja[2];
	int unosBrisanjaRezultat = 0;

	do
	{
		do
		{
			printf("\n----------------------------------------------\n");
			printf("Zelite li izbrisati datoteku?\n");
			printf("1. DA\t");
			printf("2. !NE\n");
			printf("------------------------------------------------\n");
			printf("Unos: ");

			scanf(" %s", unosBrisanja);

			unosBrisanjaRezultat = strlen(unosBrisanja);

			if (unosBrisanjaRezultat > 1)
			{
				printf("Krivi unos!");
			}
			
		} while (unosBrisanjaRezultat > 1);

		switch (unosBrisanja[0])
		{
		case '1':
			remove(novoIme);
			break;
		
		case '2':
			remove(novoIme);
			break;

		default:
			printf("Krivi unos!");
			break;
		}

	} while (unosBrisanja[0] > '2');
}

void randomFilm(FILM *filmovi, int brojacFilmova){
	srand((unsigned)time(NULL));
	int min = 0;

	int dobivanjeRandomFilma = min + rand() % (brojacFilmova - min);

	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	printf("Random film iz liste: \n");
	fprintf(pronadeni, "Random film iz liste: \n");
	printf("ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", dobivanjeRandomFilma, filmovi[dobivanjeRandomFilma].ime, filmovi[dobivanjeRandomFilma].godina, filmovi[dobivanjeRandomFilma].zanr, filmovi[dobivanjeRandomFilma].nacinGledanja, filmovi[dobivanjeRandomFilma].placanjeUlaz);
	fprintf(pronadeni, "ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", dobivanjeRandomFilma, filmovi[dobivanjeRandomFilma].ime, filmovi[dobivanjeRandomFilma].godina, filmovi[dobivanjeRandomFilma].zanr, filmovi[dobivanjeRandomFilma].nacinGledanja, filmovi[dobivanjeRandomFilma].placanjeUlaz);
}

//---------------------------------------------------------------------------------------------------------------------

//21
void pretrazivanjeFilmova(FILM *filmovi, int brojacFilmova)
{

	char izborKriterija[2];
	int rezultatKriterija = 0;

	// izbornik za pretrazivanje

	do
	{
		do
		{
		printf("\n---------------------------------------------------------------\n");
		printf("Po kojem kriteriju zelite pretrazivati filmove: \n");
		printf("1. Pretrazivanje po IMENU filma\n");
		printf("2. Pretrazivanje po ID-u filma\n");
		printf("3. Pretrazivanje po GODINI filma\n");
		printf("4. Pretrazivanje po ZANRU filma\n");
		printf("5. Nista od navedenog -- nazad na prosli izbornik\n");
		printf("---------------------------------------------------------------\n");
		printf("Izbor: ");

		scanf(" %s", izborKriterija);
		rezultatKriterija = strlen(izborKriterija);
		if (rezultatKriterija>1)
		{
			printf("Krivi upis -- mora biti izmedu 1-5!");
		}
			
		} while (rezultatKriterija>1);

		switch (izborKriterija[0])
		{
		case '1':
			trazenjeImeFilma(filmovi, brojacFilmova);
			break;

		case '2':
			trazenjeIDFilma(filmovi, brojacFilmova);
			break;

		case '3':
			trazenjeGodinaFilma(filmovi, brojacFilmova);
			break;

		case '4':
			trazenjeZanrFilma(filmovi, brojacFilmova);
			break;

		case '5':
			zavrseteTrazenjaFilma();
			break;

		default:
			printf("Krivi upis -- mora biti izmedu 1-5!");
			break;
		}

	} while (izborKriterija[0] != '5');
}

// funkcija izbornika funkcije pretrazivanjeFilmova

// IME
void trazenjeImeFilma(FILM *filmovi, int brojacFilmova)
{
	char trazenjeIme[70];
	printf("\nUpisite ime filma kojeg trazite(pazite na mala i velika slova): ");
	scanf(" %[^\n]", trazenjeIme);
	printf("\n");

	// odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");

	// krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].ime, trazenjeIme) == 0) // opet usporedujemo tocnije filmovi[i].ime - trazenjeIme -- znaci ascii vrijednosti se oduzimaju ako je 0 rezultat znaci da je ime trazeno isto kao ime filma
		{
			printf("ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			pronadeniFilm++;
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s takvim imenom!\n");
		fprintf(pronadeni, "U bazi nema filmova s takvim imenom!\n");
	}
	fclose(pronadeni);
}

// ID
void trazenjeIDFilma(FILM *filmovi, int brojacFilmova)
{
	int trazenjeID;
	printf("\nUpisite ID filma kojeg trazite: ");
	scanf("%d", &trazenjeID);
	printf("\n");

	// odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");

	// krece algoritam trazenja
	int pronadeniFilm;
	if (trazenjeID >= 0 && trazenjeID < brojacFilmova)
	{
		printf("ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", trazenjeID, filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr, filmovi[trazenjeID].nacinGledanja, filmovi[trazenjeID].placanjeUlaz);
		fprintf(pronadeni, "ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", trazenjeID, filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr, filmovi[trazenjeID].nacinGledanja, filmovi[trazenjeID].placanjeUlaz);
		pronadeniFilm++;
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s tim ID-om!\n");
		fprintf(pronadeni, "U bazi nema filmova s tim ID-om!\n");
	}
	fclose(pronadeni);
}

// GODINA
void trazenjeGodinaFilma(FILM *filmovi, int brojacFilmova)
{
	int trazenjeGodina;
	printf("Upisite godinu filmova koje trazite: ");
	scanf("%d", &trazenjeGodina);
	printf("\n");

	// odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Filmovi koje ste trazili: \n\n");

	// krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (trazenjeGodina == filmovi[i].godina)
		{
			printf("ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			pronadeniFilm++;
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova iz te godine!\n");
		fprintf(pronadeni, "U bazi nema filmova iz te godine!\n");
	}
	fclose(pronadeni);
}

// ZANR
void trazenjeZanrFilma(FILM *filmovi, int brojacFilmova)
{
	char trazenjeZanrOdabir[100];
	char trazenjeZanr[15];
	int trazenjeZanrLoopClose;

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

		scanf(" %99s", trazenjeZanrOdabir);

		if (strcmp(trazenjeZanrOdabir, "1") == 0) {
            strcpy(trazenjeZanr, "Action");
            trazenjeZanrLoopClose = 1;
        }
        else if (strcmp(trazenjeZanrOdabir, "2") == 0) {
            strcpy(trazenjeZanr, "Adventure");
            trazenjeZanrLoopClose = 2;
        }
        else if (strcmp(trazenjeZanrOdabir, "3") == 0) {
            strcpy(trazenjeZanr, "Animation");
            trazenjeZanrLoopClose = 3;
        }
        else if (strcmp(trazenjeZanrOdabir, "4") == 0) {
            strcpy(trazenjeZanr, "Comedy");
            trazenjeZanrLoopClose = 4;
        }
        else if (strcmp(trazenjeZanrOdabir, "5") == 0) {
			strcpy(trazenjeZanr, "Drama");
            trazenjeZanrLoopClose = 5;
        }
        else if (strcmp(trazenjeZanrOdabir, "6") == 0) {
            strcpy(trazenjeZanr, "Film-Noir");
            trazenjeZanrLoopClose = 6;
        }
        else if (strcmp(trazenjeZanrOdabir, "7") == 0) {
            strcpy(trazenjeZanr, "Horror");
            trazenjeZanrLoopClose = 7;
        }
        else if (strcmp(trazenjeZanrOdabir, "8") == 0) {
			strcpy(trazenjeZanr, "Mystery");
            trazenjeZanrLoopClose = 8;
        }
        else if (strcmp(trazenjeZanrOdabir, "9") == 0) {
            strcpy(trazenjeZanr, "Sci-Fi");
            trazenjeZanrLoopClose = 9;
        }
        else if (strcmp(trazenjeZanrOdabir, "10") == 0) {
            strcpy(trazenjeZanr, "War");
            trazenjeZanrLoopClose = 10;
        }
        else if (strcmp(trazenjeZanrOdabir, "11") == 0) {
            strcpy(trazenjeZanr, "Western");
            trazenjeZanrLoopClose = 11;
        }
        else if (strcmp(trazenjeZanrOdabir, "12") == 0) {
            strcpy(trazenjeZanr, "Music");
            trazenjeZanrLoopClose = 12;
        }
        else {
        	printf("Ne postoji zanr! Odaberite iz liste.\n");
			trazenjeZanrLoopClose = 0;
        }

	} while (trazenjeZanrLoopClose == 0);

	// odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Film/ovi koje/g ste trazili: \n\n");

	// krece algoritam trazenja

	int pronadeniFilm = 0;
	
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].zanr, trazenjeZanr) == 0)
		{
			printf("ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %2d.  %-30s (%4d) \t Zanr: %-12s \t Nacin Gledanja: %-3s \t Ulaz: %6.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			pronadeniFilm++;
		}
	}
	if (pronadeniFilm == 0)
	{
		printf("U bazi nema filmova s takvim imenom!\n");
		fprintf(pronadeni, "U bazi nema filmova koji odgovaraju odabranom zanru!\n");
	}
	fclose(pronadeni);
}
// izbornici zavrsavanje programa

char zavrseteTrazenjaFilma()
{
	return printf("\nVracanje na pocetni izbornik...\n");
}