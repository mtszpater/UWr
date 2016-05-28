//
// Created by Mateusz Pater on 08.04.2016.
//

#include "potega.h"


double potega::oblicz() {
    return pow(a->oblicz(),b->oblicz());
}

potega::potega(wyrazenie *a, wyrazenie *b) {
    this->a = a;
    this->b = b;
}

std::string potega::formatuj_wyrazenie() {
    return a->formatuj_wyrazenie() + "^" + b->formatuj_wyrazenie();
}