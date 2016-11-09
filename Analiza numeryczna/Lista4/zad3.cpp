#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

double const alfa = 0.0646926359947960;

double f(double x) {
    return (x * exp(-x)) - 0.06064;
}

/* |e = alfa - m| */
double brz(double m) {
    return abs(alfa - m);
}
/* 2^-n-1 (b0 - a0) */
double bsz(int n, double a0, double b0)
{
    return pow(2, -n-1) * (b0 - a0);
}
int main() {
    double a0 = 0;
    double b0 = 1;
    double a = a0;
    double b = b0, m;
    int N = 15;
    for (int i = 0; i <= N; i++){

        m = (a+b) / 2;
        double blad_rz = brz(m);
        double blad_sz = bsz(i, a0, b0);
        cout << fixed << i << ":\trzeczywisty: (e) " << blad_rz << "\toszacowany: " << blad_sz << endl;

        if(f(m) > 0) {b = m;} else { a = m;}


    }
    return 0;
}

