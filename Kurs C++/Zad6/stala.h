//
// Created by Mateusz Pater on 08.04.2016.
//
#include "wyrazenie.h"
#ifndef ARYTMETYKA2_STALA_H
#define ARYTMETYKA2_STALA_H


class stala : public wyrazenie {

public:
    virtual double oblicz();

    virtual std::string opis();

    int getValue();

    stala(int value);

    std::string formatuj_wyrazenie();

private:
    int value;

};


#endif //ARYTMETYKA2_STALA_H
