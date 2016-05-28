//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_E_H
#define ARYTMETYKA2_E_H


#include "operator0arg.h"
#include <cmath>


class e : public operator0arg{

public:
    double oblicz();

    std::string formatuj_wyrazenie();

};



#endif //ARYTMETYKA2_E_H
