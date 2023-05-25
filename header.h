#ifndef HEADER_H   
#define header_h

//3
typedef struct{
    char ime[70];
    int godina;
    char zanr[15]; 
}FILM;

void ispisFilmova(FILM filmovi, int brojacFilmova); 
void dodajFilm(FILM filmovi, int *brojacFilmova, int); 
void brisiFilm(FILM filmovi[], int* brojacFilmova);
void sortGodina(); 
void sortZanr(); 
void close(); 

#endif 

