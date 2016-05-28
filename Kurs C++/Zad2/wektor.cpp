//
// Created by Mateusz Pater on 09.03.2016.
//

#include "wektor.h"


    wektor::wektor(){
        dx = 0;
        dy = 0;
    }
    wektor::wektor(double x, double y){
        dx = x;
        dy = y;
    }

    double wektor::return_x(){
        return dx;
    }

    double wektor::return_y(){
        return dy;
    }




