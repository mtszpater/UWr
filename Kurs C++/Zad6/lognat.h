//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_LOGNAT_H
#define ARYTMETYKA2_LOGNAT_H


#include "operator1arg.h"
#include <cmath>


class lognat : public operator1arg{

public:
    double oblicz();

    lognat(wyrazenie *a);

    std::string formatuj_wyrazenie();

};



#endif //ARYTMETYKA2_LOGNAT_H
