//
// Created by Mateusz Pater on 08.04.2016.
//

#include "dodaj.h"


double dodaj::oblicz() {
    return a->oblicz()+b->oblicz();
}

std::string dodaj::opis() {

    return "Wartosc " + std::to_string(oblicz());

}

std::string dodaj::formatuj_wyrazenie() {
    return "(" + a->formatuj_wyrazenie() + " + " + b->formatuj_wyrazenie() + ")";
}

dodaj::dodaj(wyrazenie *a, wyrazenie *b){ this->a = a; this->b = b; }