//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_DODAJ_H
#define ARYTMETYKA2_DODAJ_H

#include "wyrazenie.h"
#include "operator2arg.h"

class dodaj : public operator2arg{

public:
    virtual double oblicz();

    virtual std::string opis();

    dodaj(wyrazenie *a, wyrazenie *b);

    std::string formatuj_wyrazenie();


};


#endif //ARYTMETYKA2_DODAJ_H
