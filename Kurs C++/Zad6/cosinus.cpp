//
// Created by Mateusz Pater on 08.04.2016.
//

#include "cosinus.h"

double cosinus::oblicz() {
    return cos(a->oblicz());
}

cosinus::cosinus(wyrazenie *a){
    this->a = a;
}

std::string cosinus::formatuj_wyrazenie(){
    return "cos(" + a->formatuj_wyrazenie() + ")";
}