//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_WYRAZENIE_H
#define ARYTMETYKA2_WYRAZENIE_H
#include <string>

class wyrazenie {

public:
    virtual double oblicz() = 0;
    virtual std::string formatuj_wyrazenie() = 0;
    virtual std::string opis() = 0;
};


#endif //ARYTMETYKA2_WYRAZENIE_H
