//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_PRZECIWNA_H
#define ARYTMETYKA2_PRZECIWNA_H


#include "operator1arg.h"
#include <cmath>


class przeciwna : public operator1arg{

public:
    double oblicz();

    przeciwna(wyrazenie *a);

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_PRZECIWNA_H
