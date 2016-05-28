//
// Created by Mateusz Pater on 08.04.2016.
//

#include "odwrotna.h"

double odwrotna::oblicz() {
    return pow(a->oblicz(), -1);
}

odwrotna::odwrotna(wyrazenie *a){
    this->a = a;
    if( a->oblicz() == 0 ) {  throw std::invalid_argument("Dzielenie przez 0"); }
}

std::string odwrotna::formatuj_wyrazenie() {
    return a->formatuj_wyrazenie() + "^-1";
}