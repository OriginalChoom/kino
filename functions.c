#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//10 -- 9
void ispisFilmova(FILM *filmovi, int brojacFilmova)
{
	if (brojacFilmova == 0)
	{
		printf("Nema filmova za pokazati.");
		return;
	}
	printf("\nLista filmova: \n\n");
	for (int i = 0; i < brojacFilmova; i++)
	{
		printf("ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
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
		fprintf(output, "ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
	}
	fclose(output);
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
	static int odabirZanraFilma; //5
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

	static int odabirNacinGledanja;
	printf("Unesite nacin gledanja filma: ");
	do
	{
		printf("\n----------------------------------------------\n");
		printf("1. 2D\t");
		printf("2. 3D\t");
		printf("3. 4D\n");
		printf("------------------------------------------------\n");
		printf("Unos: ");
		scanf("%d", &odabirNacinGledanja);

		switch (odabirNacinGledanja)
		{
		case 1:
			strcpy(noviFilm.nacinGledanja, "2D");
			break;
		
		case 2:
			strcpy(noviFilm.nacinGledanja, "3D");
			break;

		case 3:
			strcpy(noviFilm.nacinGledanja, "4D");
			break;

		default:
			printf("Unesite ponovno!");
			break;
		}

	} while (odabirNacinGledanja > 3);

	static double cijenaUlaza;
	printf("Unesite cijenu ulaza u kino: ");
	do
	{
		scanf("%lf", &cijenaUlaza);
		noviFilm.placanjeUlaz = cijenaUlaza;
		if (cijenaUlaza < 0 || cijenaUlaza > 100)
		{
			printf("Cijena mora biti razumna(0-100).\n");
			printf("Unesite cijenu: ");
		}

	} while (cijenaUlaza < 0 || cijenaUlaza > 100);

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
void sortGodina(FILM *filmovi, int brojacFilmova)
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

void sortZanr(FILM *filmovi, int brojacFilmova)
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

void sortiranjeCijeneUlaza(FILM* filmovi, int brojacFilmova){

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
	FILE *noviFile = fopen("novi.txt", "w");
    if (noviFile != NULL){
		perror("Nemoguce otvoriti file!");
	}
	int preimenuj;
	char novoIme[30];
	printf("Preimenujemo datoteku output.txt!\n");
	printf("Novo ime: ");
	scanf("%[^\n]", novoIme);

	preimenuj = rename("novi.txt", novoIme);

	if(preimenuj == 0) {
      printf("\nUspjesno promjenjeno ime file-a.");
   } else {
      printf("Greska, nemoguce preimenovanje file-a!");
   }

}


//---------------------------------------------------------------------------------------------------------------------
//21
void pretrazivanjeFilmova(FILM *filmovi, int brojacFilmova)
{

	int izborKriterija;
	do
	{
		// izbornik za pretrazivanje
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
			printf("ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
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
		printf("ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", trazenjeID, filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr, filmovi[trazenjeID].nacinGledanja, filmovi[trazenjeID].placanjeUlaz);
		fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", trazenjeID, filmovi[trazenjeID].ime, filmovi[trazenjeID].godina, filmovi[trazenjeID].zanr, filmovi[trazenjeID].nacinGledanja, filmovi[trazenjeID].placanjeUlaz);
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
			printf("ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
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
	} while (trazenjeZanrOdabir > 12);

	// odma otvaram file za ispis da ne moram sacuvat id pronadenog filma
	FILE *pronadeni = fopen("pronadeni.txt", "w");
	if (pronadeni == NULL)
	{
		printf("\nNe moze se otvoriti file!\n");
		return;
	}
	fprintf(pronadeni, "Film/ovi koje/g ste trazili: \n\n");

	// krece algoritam trazenja
	int pronadeniFilm;
	for (int i = 0; i < brojacFilmova; i++)
	{
		if (strcmp(filmovi[i].zanr, trazenjeZanr) == 0)
		{
			printf("ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
			fprintf(pronadeni, "ID: %d.  %s (%d) \t\t Zanr: %s \t Nacin Gledanja: %s \t Ulaz: %.2fkn\n", i, filmovi[i].ime, filmovi[i].godina, filmovi[i].zanr, filmovi[i].nacinGledanja, filmovi[i].placanjeUlaz);
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
	return printf("\nVracanje na pocetni izbornik...\n\n");
}