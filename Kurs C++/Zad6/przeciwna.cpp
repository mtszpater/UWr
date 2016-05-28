//
// Created by Mateusz Pater on 08.04.2016.
//

#include "przeciwna.h"

double przeciwna::oblicz() {
    return (-1) * a->oblicz();
}

przeciwna::przeciwna(wyrazenie *a) {
    this->a = a;
}

std::string przeciwna::formatuj_wyrazenie() {
    return "(-1)*" + a->formatuj_wyrazenie();
}