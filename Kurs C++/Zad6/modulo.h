//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_MODULO_H
#define ARYTMETYKA2_MODULO_H

#include "operator2arg.h"
#include <cmath>


class modulo : public operator2arg{

public:
    double oblicz();

    modulo(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();
};



#endif //ARYTMETYKA2_MODULO_H
