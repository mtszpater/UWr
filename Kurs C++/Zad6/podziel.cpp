//
// Created by Mateusz Pater on 08.04.2016.
//

#include "podziel.h"


double podziel::oblicz() {

    return a->oblicz()/b->oblicz();
}
podziel::podziel(wyrazenie *a, wyrazenie *b){
    this->a = a;
    this->b = b;
    if( b->oblicz() == 0 ) {  throw std::invalid_argument("Dzielenie przez 0"); }
}

std::string podziel::formatuj_wyrazenie() {
    return "(" + a->formatuj_wyrazenie() + " / " + b->formatuj_wyrazenie() + ")";
}