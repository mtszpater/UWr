//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_POMNOZ_H
#define ARYTMETYKA2_POMNOZ_H


#include "operator2arg.h"

class pomnoz : public operator2arg{

public:
    double oblicz();

    pomnoz(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();
};



#endif //ARYTMETYKA2_POMNOZ_H
