//
// Created by Mateusz Pater on 08.04.2016.
//

#include "pomnoz.h"


double pomnoz::oblicz() {
    return a->oblicz()*b->oblicz();
}

pomnoz::pomnoz(wyrazenie *a, wyrazenie *b) {
    this->a = a;
    this->b = b;
}

std::string pomnoz::formatuj_wyrazenie() {
    return "(" + a->formatuj_wyrazenie() + " * " + b->formatuj_wyrazenie() + ")";
}