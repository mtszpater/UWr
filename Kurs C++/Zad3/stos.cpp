//
// Created by Mateusz Pater on 19.03.2016.
//

#include "stos.h"

    stos::stos (){
        ile = 0;
        pojemnosc = 1;
        st = new double [ pojemnosc ];
    }
    stos::stos(int p){
        ile = 0;
        pojemnosc = p;
        st = new double [ pojemnosc ];
    }

    stos::stos(const stos& zrodlo) : ile(zrodlo.ile), pojemnosc(zrodlo.pojemnosc), st(new double[zrodlo.pojemnosc]) {
        std::copy( zrodlo.st, zrodlo.st+pojemnosc,st);
    }

    stos::stos (stos &&zrodlo) : ile(zrodlo.ile), pojemnosc(zrodlo.pojemnosc), st(zrodlo.st)  // konstruktor przenoszący
    {
        zrodlo.st = nullptr;
    }

    stos& stos::operator=(const stos& zrodlo) {
        if (&zrodlo==this) return *this; 
        ile = zrodlo.ile;
        pojemnosc = zrodlo.pojemnosc;
        st = new double [ pojemnosc];
        std::copy(zrodlo.st, zrodlo.st+pojemnosc,st);
        return *this;
    }

    stos& stos::operator=(stos&& zrodlo) {
        std::swap(pojemnosc, zrodlo.pojemnosc);
        std::swap(ile, zrodlo.ile);
        std::swap(st, zrodlo.st);
        return *this;
    }


    void  stos::wloz( double e ){
        if( ile < pojemnosc ){
            st[ile] = e;
            ++ile;
        }
    }


    double  stos::sprawdz (){
        if( ile == 0 ){ std::cout << "Nie ma zadnego elementu na stosie" << std::endl; return 0; }

        return st[ile-1];
    }

    void  stos::sciagnij(){
        double *pom;
        pom = new double [ pojemnosc ];

        for ( int i = 0; i < ile; ++i ){
            pom[i] = st[i];
        }
        for ( int i = 0; i < ile; ++i ){
            st[i] = pom[i];
        }
        --ile;


        delete[] pom;


    }

    int  stos::rozmiar() {
        return ile;
    }

    void  stos::wypisz_stos() {
        for ( int i =0; i < ile; ++i ){
            std::cout << st[i] << std::endl;
        }

    }
    stos::~stos() {
        delete[] st;
    };

