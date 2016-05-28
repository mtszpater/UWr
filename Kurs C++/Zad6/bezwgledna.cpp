//
// Created by Mateusz Pater on 08.04.2016.
//

#include "bezwgledna.h"

double bezwgledna::oblicz() {
    return fabs(a->oblicz());
}

bezwgledna::bezwgledna(wyrazenie *a){
    this->a = a;
}
std::string bezwgledna::formatuj_wyrazenie() {
    return "|" + a->formatuj_wyrazenie() + "|";
}

