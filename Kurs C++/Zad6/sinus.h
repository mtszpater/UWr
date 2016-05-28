//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_SINUS_H
#define ARYTMETYKA2_SINUS_H



#include "operator1arg.h"
#include <cmath>


class sinus : public operator1arg{

public:
    double oblicz();

    sinus(wyrazenie *a);

    std::string formatuj_wyrazenie();
};


#endif //ARYTMETYKA2_SINUS_H
