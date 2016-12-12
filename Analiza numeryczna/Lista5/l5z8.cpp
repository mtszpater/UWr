//
// Created by Mateusz Pater on 14.11.2016.
//


/**
 *
 * 1: G sqrt(3) a ~ p = 2
 * 3: Z 1/sqrt(a) ~ p = 3
 * 4: I (x-17.42)*(x+1234234)
 * 0: F sqrt(a) ~ p = 2,63
 * 5: X sqrt(5) a ~ p = 2,67
 */

#define CURRENT_FUNCTION 1


#include <iostream>
#include <cmath>

/* Zdefiniujmy funkcję f = x*x - a oraz jej pochodne sqrt(a) */
double f(double x, int n, double a)
{
    switch(n) {
        case 1:
            return 2*x;
        case 2:
            return 2;
        default:
            return x*x - a;
    }
}

/* Funkcja g = x*x*x - a (sqrt 3 (a) ) */
double g(double x, int n, double a)
{
    switch(n) {
        case 1:
            return 3*x*x;
        case 2:
            return 6*x;
        default:
            return x*x*x - a;
    }
}


/* Funkcja g = x*x*x - a (sqrt 5 (a) ) */
double x(double x, int n, double a)
{
    switch(n) {
        case 1:
            return 5*x*x*x*x;
        case 2:
            return 20*x*x*x;
        default:
            return x*x*x*x*x - a;
    }
}

/* Funkcja z = 1/sqrt(a) */
double z(double x, int n, double a)
{

    switch(n) {
        case 1:
            return -2/(x*x*x);
        case 2:
            return 6/(x*x*x*x);
        default:
            return (1/(x*x))-a;
    }
}

/* Funkcja i = (x-1)*(x+1239471239); */
double i(double x, int n, double a)
{

    switch(n) {
        case 1:
            return 2*x+1239471238;
        case 2:
            return 2;
        default:
            return (x-17.43)*(x+1239471239);
    }
}

double Funkcja ( double xn, int n, double a)
{
    switch(CURRENT_FUNCTION)
    {
        case 1:
            return g(xn, n, a);
        case 3:
            return z(xn, n, a);
        case 4:
            return i(xn, n, a);
        case 5:
            return x(xn, n, a);
        default:
            return f(xn, n, a);
    }


}



double wynik( double a)
{

    switch(CURRENT_FUNCTION)
    {
        case 1:
            return pow(a, 1/3.0);
        case 2:
            return 1/a;
        case 3:
            return 1/sqrt(a);
        case 4:
            return 17.43;
        case 5:
            return pow(a, 1/5.0);
        default:
            return sqrt(a);
    }

}

void Olver ( double x, double a )
{
    double xn = x;
    double en = 0;
    double en_1 = 0;
    double en_2 = 0;
    double dokladny_wynik = wynik(a);
    double en_3 = fabs(dokladny_wynik-x);

    for(int i=0; i<100; i++)
    {
        xn = xn - (Funkcja(xn, 0, a))/(Funkcja(xn, 1, a)) - 0.5*(Funkcja(xn, 2, a))/(Funkcja(xn, 1, a)) * (Funkcja(xn, 0, a))/(Funkcja(xn, 1, a)) * (Funkcja(xn, 0, a))/(Funkcja(xn, 1, a));

        en = en_1;
        en_1 = en_2;
        en_2 = en_3;
        en_3 = xn - dokladny_wynik;

        std::cout << "\t Dokładna wartość: " << wynik(a) <<"\t Wartość: " << xn << "\tBłąd: " << en_3 << std::endl;

        if(fabs(en_3) < 0.0000000000001)
            break;
    }


    double p=log(en_2/en_1)/log(en_1/en);

    std::cout << "\t P: " << p << std::endl;

}


int main() {


    using namespace std;
    cout.precision(20);


//    /** DLA 3 **/
//    Olver(0.1, 15);
//    Olver(0.1, 1/13.00);

    /** DLA INNYCH **/
    Olver(9284, 5);
    Olver(9000, 44);

}


