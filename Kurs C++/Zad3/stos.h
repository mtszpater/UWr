//
// Created by Mateusz Pater on 19.03.2016.
//

#ifndef ZAD3C_STOS_H
#define ZAD3C_STOS_H
#include <iostream>

class stos {

    int pojemnosc;
    int ile;
    double *st;

public:

    stos ();
    stos(int p);

    stos(const stos& zrodlo);
    stos& operator=(const stos& zrodlo);
    stos& operator=(stos&& zrodlo);
    stos (stos &&zrodlo);
    template <unsigned N, typename T>  stos (T (&t)[N]) {

        ile = (int) (sizeof(t) / sizeof(t[0]));

        pojemnosc = 2 * ile + 1;
        st = new double [ pojemnosc ];

        for( int i = 0; i < ile; ++i ){
            st[i] = t[i];
        }


    }
    void wloz( double e );
    double sprawdz ();
    void sciagnij();
    int rozmiar();
    void wypisz_stos();
    ~stos();


};


#endif //ZAD3C_STOS_H
