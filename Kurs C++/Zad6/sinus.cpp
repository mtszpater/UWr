//
// Created by Mateusz Pater on 08.04.2016.
//

#include "sinus.h"


double sinus::oblicz() {
    return sin(a->oblicz());
}

sinus::sinus(wyrazenie *a){ this->a = a; }

std::string sinus::formatuj_wyrazenie() {
    return "sin (" + a->formatuj_wyrazenie() + ")";
}