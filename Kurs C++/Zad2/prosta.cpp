//
// Created by Mateusz Pater on 09.03.2016.
//

#include "prosta.h"


    void prosta::normal(){
        double alfa;

        if ( C < 0 ){
            alfa = ( 1 / sqrt( A * A + B * B) );
        }
        else
        {
            alfa = ( -1 / sqrt( A * A + B * B) );
        }

        A = A * alfa;
        B = B * alfa;
        C = C * alfa;

    }



    prosta::prosta(punkt p1, punkt p2){
        A = (p2.return_y() + p1.return_y())/(p1.return_x() + p2.return_x());
        C = (p1.return_y()*p2.return_x() - p1.return_x()*p2.return_y())/ (p1.return_x() + p2.return_x() );

        B = -1;

        normal();

    }

    prosta::prosta(double A1, double B1, double C1){
        if (A1 == 0 && B1 == 0)
            throw std::invalid_argument("nie można jednoznacznie utworzyć prostej");

        A = A1;
        B = B1;
        C = C1;

        normal();
    }

    prosta::prosta(wektor w, prosta k){
        A = k.return_a();
        B = k.return_b();
        C = ( - 1) * k.return_a() * w.return_x() - w.return_y();

        normal();

    }

    prosta::prosta(wektor w){
        if (w.return_y() == 0)
            throw std::invalid_argument("nie można jednoznacznie utworzyć prostej");
        A = (-1)*( w.return_x() / w.return_y());
        B = -1;
        C = ( pow(w.return_y(),2) + pow(w.return_x(), 2) ) / w.return_y();

        normal();

    }

    punkt prosta::przeciecie(prosta k){
        punkt p;

        double x =  (C*k.return_b() - k.return_c()*B) / (k.return_a() * B - A * k.return_b() );
        double y =  (A*k.return_c() - k.return_a()*C) / (k.return_b() * A - B * k.return_a() );
        p = punkt (x, y);

        return p;
    }

    bool prosta::wektor_prostopadly(wektor w){

        if((w.return_x() == 0) || (B == 0) ) return false;

        if((w.return_x() == 0) && (B == 0) ) return true;

        if(w.return_y()/w.return_x() == B/A ) return true;

        return false;

    }

    bool prosta::wektor_rownolegly(wektor w){
        if (w.return_x() == 0)
            throw std::invalid_argument("nie można jednoznacznie sprawdzic wektora");

        if((w.return_x() == 0) || (B == 0) ) return false;

        if((w.return_x() == 0) && (B == 0) ) return true;

        if(w.return_y()/w.return_x() == -A/B ) return true;

        return false;

    }

    bool prosta::rownolegle(prosta B){
        if(A == B.A) return true;
        return false;
    }

    bool prosta::prostopadle(prosta B){
        if( (A * B.return_a()) == -1) return true;
        return false;

    }


    double prosta::lezy(punkt p){

        double distance;

        if( fabs( p.return_x() * A + p.return_y() * B  + C ) < EPSILON){
            distance = 0;
        }
        else {
            distance = ( fabs(A*p.return_x() + B*p.return_y() + C) / ( sqrt(A*A + B*B) ) );
        }

        return distance;


    }
    double prosta::return_a (){
        return A;
    }
    double prosta::return_b (){
        return B;
    }
    double prosta::return_c (){
        return C;
    }
