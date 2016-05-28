//
// Created by Mateusz Pater on 09.03.2016.
//

#ifndef ZADANIE2_PROSTA_H
#define ZADANIE2_PROSTA_H
#include "wektor.h"
#include "punkt.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stdexcept>

#define EPSILON 0.0000000000001

class prosta{
    double A;
    double B;
    double C;


        void normal();

public:

        prosta(punkt p1, punkt p2);

        prosta(double A1, double B1, double C1);

        prosta(wektor w, prosta k);

        prosta(wektor w);

        punkt przeciecie(prosta k);

        bool wektor_prostopadly(wektor w);

        bool wektor_rownolegly(wektor w);

        bool rownolegle(prosta B);

        bool prostopadle(prosta B);

        double lezy(punkt p);

        double return_a ();

        double return_b ();

        double return_c ();
};

#endif //ZADANIE2_PROSTA_H
