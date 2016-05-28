//
// Created by Mateusz Pater on 08.04.2016.
//

#include "log.h"

double logarytm::oblicz() {

    return log2(b->oblicz())/log2(a->oblicz());
}

logarytm::logarytm(wyrazenie *a, wyrazenie *b){ this->a = a; this->b = b; }

std::string logarytm::formatuj_wyrazenie() {
    return "log" + a->formatuj_wyrazenie() + " " +  b->formatuj_wyrazenie();
}
