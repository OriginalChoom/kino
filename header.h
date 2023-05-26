#ifndef header_h   
#define header_h

typedef struct{
    char ime[70];
    int godina;
    char zanr[15]; 
}FILM;

void ispisFilmova(FILM* filmovi, int brojacFilmova); 
void dodajFilm(FILM** filmovi, int *brojacFilmova, int* maxFilms); 
void brisiFilm(FILM** filmovi, int* brojacFilmova, int* maxFilms);
void sortGodina(FILM* filmovi, int brojacFilmova); 
void sortZanr(FILM* filmovi, int brojacFilmova); 
char close(); 

#endif 

