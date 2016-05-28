//
// Created by Mateusz Pater on 08.04.2016.
//

#include "lognat.h"


double lognat::oblicz() {
    return log2(a->oblicz());
}

lognat::lognat(wyrazenie *a){
    this->a = a;
    if( a->oblicz() == 0 ) {  throw std::invalid_argument("Nie może być 0"); }
}

std::string lognat::formatuj_wyrazenie() {

    return "log2 " + a->formatuj_wyrazenie();
}