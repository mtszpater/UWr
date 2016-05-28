//
// Created by Mateusz Pater on 09.03.2016.
//

#include "punkt.h"

    punkt::punkt (){
        x = 0;
        y = 0;
    }
    punkt::punkt (double x1, double y1){
        x = x1;
        y = y1;
    }

    punkt::punkt(double x1, double y1, wektor w)
    {
        x = x1 + w.return_x();
        y = y1 + w.return_y();
    }

    double punkt::return_x(){
        return x;
    }

    double punkt::return_y(){
        return y;
    }


