//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_ODWROTNA_H
#define ARYTMETYKA2_ODWROTNA_H

#include "operator1arg.h"
#include <cmath>


class odwrotna : public operator1arg{

public:
    double oblicz();

    odwrotna(wyrazenie *a);

    std::string formatuj_wyrazenie();
};


#endif //ARYTMETYKA2_ODWROTNA_H
