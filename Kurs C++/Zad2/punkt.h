//
// Created by Mateusz Pater on 09.03.2016.
//

#ifndef ZADANIE2_PUNKT_H
#define ZADANIE2_PUNKT_H
#include "wektor.h"

class punkt{
    double x;
    double y;

public:
    punkt ();

    punkt (double x1, double y1);

    punkt(double x1, double y1, wektor w);

    double return_x();

    double return_y();


};

#endif //ZADANIE2_PUNKT_H
