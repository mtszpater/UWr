//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_POTEGA_H
#define ARYTMETYKA2_POTEGA_H

#include <cmath>
#include "operator2arg.h"

class potega : public operator2arg{

public:
    double oblicz();

    potega(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_POTEGA_H
