//
// Created by Mateusz Pater on 08.04.2016.
//

#include "odejmij.h"


double odejmij::oblicz() {
    return a->oblicz()-b->oblicz();
}
odejmij::odejmij(wyrazenie *a, wyrazenie *b) { this->a = a; this->b = b; }


std::string odejmij::formatuj_wyrazenie() {
    return "(" + a->formatuj_wyrazenie() + " - " + b->formatuj_wyrazenie() + ")";
}