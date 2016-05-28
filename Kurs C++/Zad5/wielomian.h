//
// Created by Mateusz Pater on 26.03.2016.
//

#ifndef L5Z1_WIELOMIAN_H
#define L5Z1_WIELOMIAN_H

#include <iostream>
#include <stdexcept>


using namespace std;

class wielomian {
    int n;
    double *a;

public:
    wielomian(int st=0, double wsp=1.0);

    wielomian(int st, double wsp[]);

    wielomian( initializer_list<double> wsp );

    wielomian(const wielomian& zrodlo);

    wielomian (wielomian &&zrodlo);

    double oblicz(double x);

    int zwroc_stopien();

    double& operator[](int idx);

    const double& operator[](int idx) const;

    wielomian& operator=(wielomian&& zrodlo);

    wielomian& operator=(const wielomian& zrodlo);

    wielomian& operator += ( const wielomian & v );

    wielomian& operator -= ( const wielomian & v );

    wielomian& operator *= ( const wielomian & v );

    wielomian& operator *= ( double k );

    friend ostream& operator << (ostream &wy, const wielomian &w);

    friend istream& operator >> (istream &we, wielomian &w);

    friend wielomian operator + ( const wielomian& v, wielomian u );

    friend wielomian operator - ( const wielomian& v, wielomian u );

    friend wielomian operator * ( const wielomian& v, wielomian u );

    friend wielomian operator * ( double k, wielomian u );

    ~wielomian();


};



#endif //L5Z1_WIELOMIAN_H
