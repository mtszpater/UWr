//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_PI_H
#define ARYTMETYKA2_PI_H


#include "operator0arg.h"
#include <cmath>


class pi : public operator0arg{

public:
    double oblicz();

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_PI_H
