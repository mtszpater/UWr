//
// Created by Mateusz Pater on 08.04.2016.
//

#include "modulo.h"



double modulo::oblicz() {
    return fmod(a->oblicz(), b->oblicz());
}

modulo::modulo(wyrazenie *a, wyrazenie *b) {
    this->a = a;
    this->b = b;
    if( b->oblicz() == 0 ) {  throw std::invalid_argument("Dzielenie przez 0"); }
}

std::string modulo::formatuj_wyrazenie(){
    return a->formatuj_wyrazenie() + "%" + b->formatuj_wyrazenie();
}
