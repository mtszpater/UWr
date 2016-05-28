//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_EXP_H
#define ARYTMETYKA2_EXP_H

#include "operator1arg.h"
#include <cmath>


class exponent : public operator1arg{

public:
    double oblicz();

    exponent(wyrazenie *a);

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_EXP_H
