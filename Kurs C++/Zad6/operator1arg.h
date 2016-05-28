//
// Created by Mateusz Pater on 15.04.2016.
//

#ifndef ARYTMETYKA2_OPERATOR1ARG_H
#define ARYTMETYKA2_OPERATOR1ARG_H


#include "operator0arg.h"

class operator1arg : public operator0arg {

public:

    std::string opis();

protected:
    wyrazenie *a;
};



#endif //ARYTMETYKA2_OPERATOR1ARG_H
