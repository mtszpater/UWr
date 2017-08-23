/***********************************************************
* MATESZ PATER SYSTEMY OPERACYJNE 2017                     *
* ALGORYTMY PRZYDZIALU PAMIECI                             *
***********************************************************/

#include <stdio.h>
#define WORST 0
#define FIRST 1
#define BEST 2

int procesy[10];
int bloki[10];
int pamiec[10];
int liczba_blokow, liczba_procesow;

void wczytajArgumenty();

void wyczyscPamiec();

void drukujWynik(int type);

void drukujNaglowek(int type);

void firstFit();

void bestFit();

void worstFit();

void algorytm(int type);

int main()
{
    wczytajArgumenty();

    algorytm(BEST);
    algorytm(WORST);
    algorytm(FIRST);

    return 0;
}

void wczytajArgumenty(){
    int m;

    printf("\nLiczba bloków\t");
    scanf("%d",&liczba_blokow);

    if(liczba_blokow > 10) liczba_blokow = 10;
    if(liczba_blokow < 0) liczba_blokow = 1;

    printf("\nLiczba procesow\t");
    scanf("%d",&liczba_procesow);

    if(liczba_procesow > 10) liczba_procesow = 10;
    if(liczba_procesow < 0) liczba_procesow = 1;

    printf("\nPamiec kolejnych blokow:\n");
    for(m = 0; m < liczba_blokow; m++) 
    {
        printf("Block [%d]:\t", m + 1);
        scanf("%d", &bloki[m]);
    }

    printf("Pamiec kolejnych procesow:\n");
    for(m = 0; m < liczba_procesow; m++) 
    {
        printf("Proces [%d]:\t", m + 1);
        scanf("%d", &procesy[m]);
    }
}

void algorytm(type)
{
    wyczyscPamiec();
    switch(type)
    {
        case WORST:
            worstFit();
            break;
        case BEST:
            bestFit();
            break;
        default:
            firstFit();
            break;
    }
    drukujWynik(type);
}


void wyczyscPamiec(){
    for(int i = 0; i < liczba_blokow; ++i )
        pamiec[i] = -1;
}

void firstFit(){
    int aktualny_proces;
    for( int i = 0; i < liczba_procesow; ++i ){
        aktualny_proces = procesy[i];
        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 ){
                if( bloki[k] >= aktualny_proces )
                {
                    pamiec[k] = i;
                    break;
                }
            }
        }
    }
}

void bestFit(){
    int aktualny_proces;
    for( int i = 0; i < liczba_procesow; ++i ){
        aktualny_proces = procesy[i];
        int max;

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 && bloki[k] >= aktualny_proces){
                max = bloki[k];
                break;
            }
        }

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 && bloki[k] >= aktualny_proces){
                if( max > bloki[k])
                    max = bloki[k];
            }
        }

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 ){
                if( bloki[k] == max && bloki[k] - aktualny_proces >= 0)
                {
                    pamiec[k] = i;
                    break;
                }
            }
        }
    }
}

void worstFit(){
    int aktualny_proces;

    for( int i = 0; i < liczba_procesow; ++i ){
        aktualny_proces = procesy[i];

        int max;

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 && bloki[k] >= aktualny_proces){
                max = bloki[k];
                break;
            }
        }

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 && bloki[k] >= aktualny_proces){
                if( max < bloki[k] )
                    max = bloki[k];
            }
        }

        for( int k = 0; k < liczba_blokow; ++k){
            if(pamiec[k] == -1 ){
                if( bloki[k] == max && bloki[k] - aktualny_proces >= 0)
                {
                    pamiec[k] = i;
                    break;
                }
            }
        }
    }
}

void drukujWynik(int type){
    printf("------------------------------------------------------------\n");
    drukujNaglowek(type);

    int pamiec_stracona = 0;
    for(int i = 0; i < liczba_blokow; ++i){
        if( pamiec[i] == -1 ){ 
            pamiec_stracona += bloki[i];
            printf("%d\tnull\t0\t\t%d\t\t%d\n", i, bloki[i], bloki[i]);
        }
        else
        {
            pamiec_stracona += bloki[i] - procesy[pamiec[i]];
            printf("%d\tP%d\t%d\t\t%d\t\t%d\n", i, pamiec[i]+1, procesy[pamiec[i]], bloki[i], bloki[i] - procesy[pamiec[i]]);
        }
    }
    printf("\n\tUtracona pamiec: %d\n", pamiec_stracona);
}

void drukujNaglowek(int type){
    switch(type)
    {
        case WORST:
            printf("\t\tWORST FIT");
            break;
        case BEST:
            printf("\t\tBEST FIT");
            break;
        default:
            printf("\t\tFIRST FIT");
            break;
    }
    printf("\nBLOK\tPROCES\tPAMIEC PROCESU\tPAMIEC BLOKU\tFRAGMENTACJA\n");
}
