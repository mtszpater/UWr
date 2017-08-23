#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
int liczbaZmianStron;

void wyswietlWynik();
void uzupelnijTablice();
void uzupelnijPierwszeRamki();
void zastepowanieStron(int);
void generuj(int);
int odlegloscAlgorytmuOptymalnego( int , int  );
int odlegloscAlgorytmuLRU( int, int );
int ALGORYTM_LRU( int  );
int ALGORYTM_OPTYMALNY( int );
int ALGORYTM_MFU( int  );
int ALGORYTM_LFU( int  );
int liczbaOdwolan( int , int );
int ramkaJuzIstnieje(int );
#endif