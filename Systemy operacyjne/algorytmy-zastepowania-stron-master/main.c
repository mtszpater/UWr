/*********************************************************
* ALGORYTMY ZASTĘPOWANIA STRON                           *
* MATEUSZ PATER, SYSTEMY OPERACYJNE 2017                 *
*********************************************************/
#include "main.h"
#include <stdio.h>


#define CHWIL 12
#define RAMEK 4

#define FIFO 0
#define OPTYMALNY 1
#define LRU 2
#define MFU 3
#define LFU 4


int odwolania[] = { 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5 };
int strony[RAMEK][CHWIL];

int main()
{
    zastepowanieStron(FIFO);
    zastepowanieStron(OPTYMALNY);
    zastepowanieStron(LFU);
    zastepowanieStron(MFU);
    zastepowanieStron(LRU);

    return 0;
}

void zastepowanieStron(int algorytm){
    uzupelnijTablice();
    uzupelnijPierwszeRamki();
    generuj(algorytm);
    wyswietlWynik(algorytm);
}

void uzupelnijTablice(){
    liczbaZmianStron = 0;
    for (int i = 0; i < RAMEK; i++) {
        for (int j = 0; j < CHWIL; j++) {
            strony[i][j] = -1;
        }
    }
}

void uzupelnijPierwszeRamki(){
    int aktualna_liczba;

    for(int i = 0; i < RAMEK; ++i ){

        aktualna_liczba = odwolania[i];

        int ramkaZostalaZmieniona = 0;
        for( int j = 0; j < RAMEK; ++j ){
            if( ramkaZostalaZmieniona == 1)
                strony[j][i] = 0;

            if( strony[j][i] == -1 )
            {
                for( int k = i; k < CHWIL; ++k )
                {
                    strony[j][k] = aktualna_liczba;
                }
                ramkaZostalaZmieniona = 1;
            }
        }
    }

}

void generuj(int algorytm){
    int kolejna_ramka = 0;
    int aktualna_liczba;

    for(int i = RAMEK; i < CHWIL; ++i)
    {
        aktualna_liczba = odwolania[i];

        switch(algorytm)
        {
            case FIFO:
            {
                if(kolejna_ramka == RAMEK)
                    kolejna_ramka = 0;
                break;
            }
            case LRU:
                kolejna_ramka = ALGORYTM_LRU ( i );
                break;
            case MFU:
                kolejna_ramka = ALGORYTM_MFU ( i );
                break;
            case LFU:
                kolejna_ramka = ALGORYTM_LFU ( i );
                break;
            default:
                kolejna_ramka = ALGORYTM_OPTYMALNY ( i );
                break;
        
        }

        if( ramkaJuzIstnieje(i) == 0){
            for(int k = i; k < CHWIL; ++k){
                strony[kolejna_ramka][k] = aktualna_liczba;
            }
            ++liczbaZmianStron;
            ++kolejna_ramka;
        }
    }
}
/* MFU */
int ALGORYTM_MFU( int chwila )
{
    int ramka = 0;
    int max_odwolan = 0;

    for( int i = 0; i < RAMEK; ++i )
    {
        if( max_odwolan < liczbaOdwolan( chwila, strony[i][chwila] )){
            max_odwolan = liczbaOdwolan( chwila, strony[i][chwila] );
            ramka = i;
        }
    }
    return ramka;
}

/* LFU */
int ALGORYTM_LFU( int chwila )
{
    int ramka = 0;
    int min_odwolan = chwila;

    for( int i = 0; i < RAMEK; ++i )
    {
        if( min_odwolan > liczbaOdwolan( chwila, strony[i][chwila] )){
            min_odwolan = liczbaOdwolan( chwila, strony[i][chwila] );
            ramka = i;
        }
    }
    return ramka;
}

int liczbaOdwolan( int miejsce, int liczba){
    int count = 0;

    for( int i = 0; i < miejsce; ++i )
    {
        if( odwolania[i] == liczba )
            ++count;
    }

    return count;
}

/* ALGORYTM OPTYMLANY */
int ALGORYTM_OPTYMALNY( int chwila )
{
    int ramka = 0;
    int max_odwolan = 0;

    for( int i = 0; i < RAMEK; ++i )
    {
        if( max_odwolan < odlegloscAlgorytmuOptymalnego( chwila, strony[i][chwila] )){
            max_odwolan = odlegloscAlgorytmuOptymalnego( chwila, strony[i][chwila] );
            ramka = i;
        }
    }
    return ramka;
}

int odlegloscAlgorytmuOptymalnego( int miejsce, int liczba )
{
    int count = 0;
    for( int i = miejsce; i < CHWIL; ++i ){
        if( odwolania[i] == liczba)
            break;

        ++count;
    }
    return count;
}

/* ALGORYTM LRU (Least Recently Used )*/
int ALGORYTM_LRU( int chwila )
{
    int ramka = 0;
    int max_odwolan = 0;

    for( int i = 0; i < RAMEK; ++i )
    {
        if( max_odwolan < odlegloscAlgorytmuLRU( chwila, strony[i][chwila] )){
            max_odwolan = odlegloscAlgorytmuLRU( chwila, strony[i][chwila] );
            ramka = i;
        }
    }
    return ramka;
}

int odlegloscAlgorytmuLRU( int miejsce, int liczba )
{
    int count = 0;
    for( int i = miejsce; i > 0 ; --i ){
        if( odwolania[i] == liczba)
            break;
        ++count;
    }
    return count;
}

int ramkaJuzIstnieje(int i){
    int k, onaJuzJest = 0; 
    int aktualna_liczba = odwolania[i];

    for( k = 0; k < RAMEK; ++k)
    {
        if( strony[k][i] == aktualna_liczba)
            onaJuzJest = 1;
    }

    return onaJuzJest;
}

void wyswietlWynik(int algorytm){

    printf("\n\n\nWYBRANY ALGORYTM: ");

    switch(algorytm){
        case FIFO:
            printf(" First-In-First-Out (FIFO) ");
            break;
        case LRU:
            printf(" Least Recently Used (LRU) ");
            break;
        case MFU:
            printf(" Most Frequently Used (MFU) ");
            break;
        case LFU:
            printf(" Least Frequently Used (LFU) ");
            break;
        default:
            printf(" Algorytm optymalny ");
            break;
    }
    printf("\t\tLACZNA LICZBA ZMIAN STRON: %d\t", liczbaZmianStron + RAMEK);

    printf("\nChwila:\t\t");
    for( int i = 0; i < CHWIL; ++i)
    {
        printf("%d\t", i+1);
    }
    printf("\n");

    for( int i = 0; i < CHWIL*5; ++i)
    {
        printf("_ ");
    }
    printf("\n");

    printf("Odwołanie:\t");
    for( int i = 0; i < CHWIL; ++i)
    {
        printf("%d\t", odwolania[i]);
    }
    printf("\n");


    for (int i = 0; i < RAMEK; i++) {
        printf("Ramka %d:\t", i+1);
        for (int j = 0; j < CHWIL; j++) {
            printf("%d\t", strony[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


