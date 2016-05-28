//
// Created by Mateusz Pater on 15.04.2016.
//

#ifndef ARYTMETYKA2_OPERATOR2ARG_H
#define ARYTMETYKA2_OPERATOR2ARG_H



#include "operator1arg.h"

class operator2arg : public operator1arg {

public:
    std::string opis();
protected:
    wyrazenie *b;
};

#endif //ARYTMETYKA2_OPERATOR2ARG_H
