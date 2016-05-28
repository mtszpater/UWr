//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_PODZIEL_H
#define ARYTMETYKA2_PODZIEL_H

#include <stdexcept>
#include "operator2arg.h"

class podziel : public operator2arg{

public:
    double oblicz();

    podziel(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();
};



#endif //ARYTMETYKA2_PODZIEL_H
