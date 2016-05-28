//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_ODEJMIJ_H
#define ARYTMETYKA2_ODEJMIJ_H


#include "operator2arg.h"

class odejmij : public operator2arg{

public:
    double oblicz();

    odejmij(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();

};



#endif //ARYTMETYKA2_ODEJMIJ_H
