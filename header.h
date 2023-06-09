#ifndef header_h
#define header_h

extern int maxFilms;

//3 //6 //1 //2
typedef struct
{
    char ime[70]; //12
    int godina;
    char zanr[15]; //12
    char nacinGledanja[5]; //12
    double placanjeUlaz;
} FILM;

void ispisFilmova(FILM *filmovi, int const brojacFilmova);
void dodajFilm(FILM **filmovi, int *brojacFilmova, int *maxFilms);
void brisiFilm(FILM **filmovi, int *brojacFilmova, int *maxFilms);
void sortGodina(FILM *filmovi, int const brojacFilmova);
void sortZanr(FILM *filmovi, int const brojacFilmova);
void povecanjeBaze(FILM **filmovi, int *maxFilms);
void smanjenjeBaze(FILM **filmovi, int *maxFilms, int *brojacFilmova);
void sortiranjeCijeneUlaza(FILM* filmovi, int const brojacFilmova);
void preimenovanjeDatoteke();
void randomFilm(FILM *filmovi, int brojacFilmova);

// posebne funkcije za pretrazivajne
void pretrazivanjeFilmova(FILM *filmovi, int brojacFilmova); // ova je jos u mainu

// ostatak funckije se koristi u funckiji pretrazivajne, a napisane su u functions.c
void trazenjeImeFilma(FILM *filmovi, int brojacFilmova);
void trazenjeIDFilma(FILM *filmovi, int brojacFilmova);
void trazenjeGodinaFilma(FILM *filmovi, int brojacFilmova);
void trazenjeZanrFilma(FILM *filmovi, int brojacFilmova);

// funkcije za zatvaranje programa
char zavrseteTrazenjaFilma(); // nalazi se u funckiji pretrazivanjefilmova
void close();                 // nalazi se u main

#endif
