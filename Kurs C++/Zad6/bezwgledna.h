//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_BEZWGLEDNA_H
#define ARYTMETYKA2_BEZWGLEDNA_H


#include "operator1arg.h"
#include <cmath>


class bezwgledna : public operator1arg{

public:
    double oblicz();

    bezwgledna(wyrazenie *a);

    std::string formatuj_wyrazenie();

};


#endif //ARYTMETYKA2_BEZWGLEDNA_H
