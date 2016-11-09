#include <iostream>
#include <math.h>
int n;

float g(float x)
{
    return x*x*x + 8*sinf(2*x - 5);
}
float bisekcja(float a, float b, float epsilon)
{
    /**
     *
     * Jesli na krancach to daj od razu
     *
     */

    if(g(a)==0.0)
        return a;
    if(g(b)==0.0)
        return b;

    float srodek = (a+b)/2;


    /**
     *
     * Jeśl roznica mniejsza od epsilonu to nie chcemy wiekszej dokladnosci
     *
     */

    if(b-a <= epsilon) return srodek;


    /**
     * Jeśli mieści się w a, srodek
     */

    ++n;
    if(g(a)*g(srodek)<0) {
        return bisekcja(a, srodek, epsilon);
    }

    return bisekcja(srodek, b, epsilon);


}

float bisekcja_iteracyjnie(float a, float b, int n) {


    float a0 = a;
    float b0 = b;
    float srodek;


    for (int i = 0; i <= n; ++i)
    {
        if (g(a0) == 0.0)
            return a0;
        if (g(b0) == 0.0)
            return b0;

        srodek = (a0 + b0) / 2;


        if (g(a0) * g(srodek) < 0) {
           b0 = srodek;
        }
        else
        {
            a0 = srodek;
        }
    }

    return srodek;

}


float pierwiastki(float x, float R, int n)
{

    for( int i = 0; i <= n; ++i )
    {
        x = (1.0/2.0)*x*(3.0 - R*x*x);
        std::cout << "Krok [sqrt] "<<i << ": " << x << std::endl;
    }
}


float zad5(float x0, float R, int n)
{

    /**
     * 1/R
     *
     * 1/R = x <=> 1/x = R
     *
     * f(x) = 1/x - R
     * f'(x) = -1/x^2
     *
     * xn+1 = xn - (1/x -R) / (-1/x^2)
     * [...]
     * xn+xn - x^2 * R
     *
     */


    for( int i = 0; i <= n; ++i)
    {

        x0 = x0 * (2 - x0 * R);

        std::cout << "Krok "<<i << ": " << x0 << std::endl;

    }

    std::cout << std::endl;
    return x0;
}
int main() {


    std::cout.precision(10);



    /*
     * Skąd te przedziały? Patrz podpowiedź do zadania.
     * zadanie 4 */

    n = 0;
    std::cout <<"ten x dla [0.80, 1.80] to " << std::endl << bisekcja(0.80, 1.80, 0.00001) << "\titeracji: " << n << std::endl;
    n = 0;
    std::cout <<"ten x dla [-1.00, -0.10] to " << std::endl << bisekcja(-1.00, -0.10, 0.00001) << "\titeracji: " << n << std::endl;
    n = 0;
    std::cout <<"ten x dla (1.00, 10] to " << std::endl << bisekcja(1.01, 10.00, 0.00001) << "\titeracji: " << n << std::endl;


    /* zadanie 4 */
    std::cout <<"ten x dla [0.80, 1.80] to " << std::endl << bisekcja_iteracyjnie(0.80, 1.80, 16) << std::endl;
    std::cout <<"ten x dla [-1.00, -0.10] to " << std::endl << bisekcja_iteracyjnie(-1.00, -0.10, 17) << std::endl;
    std::cout <<"ten x dla (1.00, 10] to " << std::endl << bisekcja_iteracyjnie(1.01, 10.00, 19) << std::endl;

    /* zad 5*/
    zad5(0.05, 15.00, 10);
    zad5(0.15, 10.00, 10);
    zad5(0.1, 11.00, 10);
    zad5(0.1, 12.00, 10);
    zad5(0.1, 13.00, 10);
    zad5(0.1, 14.00, 10);
    zad5(0.1, 15.00, 10);

    /*  zad 6 1/sqrt(17) bez dzielenia */
    pierwiastki(0.2, 17, 5);


    return 0;
}