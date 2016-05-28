//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_COSINUS_H
#define ARYTMETYKA2_COSINUS_H


#include "operator1arg.h"
#include <cmath>


class cosinus : public operator1arg{

public:
    double oblicz();

    cosinus(wyrazenie *a);

    std::string formatuj_wyrazenie();

};



#endif //ARYTMETYKA2_COSINUS_H
