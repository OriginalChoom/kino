#ifndef HEADER_H   
#define header_h

typedef struct Film{
    char ime[70];
    int godina;
    char zanr[15]; 
}FILM;

void pravljenjeListe(); 
int dodajFilm(); 
int brisiFilm(); 
void sortGodina(); 
void sortZanr(); 
void close(); 

#endif 

