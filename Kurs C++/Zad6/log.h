//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_LOG_H
#define ARYTMETYKA2_LOG_H

#include <cmath>
#include "operator2arg.h"

class logarytm : public operator2arg{

public:
    double oblicz();

    logarytm(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_LOG_H
