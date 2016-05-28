//
// Created by Mateusz Pater on 08.04.2016.
//

#ifndef ARYTMETYKA2_ZMIENNA_H
#define ARYTMETYKA2_ZMIENNA_H


#include "wyrazenie.h"
#include <string>
#include <vector>

class zmienna : public  wyrazenie{
public:
    virtual double oblicz();

    virtual std::string opis();

    void newPair(std::string k, double s);

    void setValue(double newValue);

    void changeValue(std::string _value);

    zmienna(const std::string &value);

    std::string formatuj_wyrazenie();

private:
    std::string value;
    std::vector< std::pair<std::string, double> > myVector;

};


#endif //ARYTMETYKA2_ZMIENNA_H
