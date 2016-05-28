//
// Created by Mateusz Pater on 08.04.2016.
//

#include "exp.h"

double exponent::oblicz() {
    return exp(a->oblicz());
}
exponent::exponent(wyrazenie *a){
    this->a = a;
}
std::string exponent::formatuj_wyrazenie() {
    return "e" + a->formatuj_wyrazenie();
}