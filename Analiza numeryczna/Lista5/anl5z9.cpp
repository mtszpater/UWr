//
// Created by Mateusz Pater on 15.11.2016.
//




#include <cmath>
#include <iostream>


double p_x (long double en, long double en_1, long double en_2 )
{
    return (log(fabsl(en_2)) - log(fabsl(en_1))) /(  log(fabsl(en_1)) - log(fabsl(en) ));
}

long double c_x ( long double en, long double en_1, long double p ){

    return fabsl(en_1)/pow(fabsl(en), p*1.00);

}


/**
 *
 *
 * WYLICZAMY P ZE WZORU: LOG(EN_2) - LOG(EN_1) / LOG(EN_1)  - LOG(EN)
 * WYLICZAMY C ZE WZORU: EN_1 / EN^P
 * WYLICZAMY EN_1 = EN^P * C
 *
 * TAK DŁUGO AŻ BĘDZIE < 10^-100
 *
 * @return
 */
int main() {

    int liczba_iteracji = 0;
    long double en,en_1,en_2, en_3;

    std::cout <<" TAK SIE BAWI ROSJA " << std::endl;

    en = 0.763907023;
    en_1 = 0.543852762;
    en_2 = 0.196247370;
    en_3 = 0.009220859;

    long double p = p_x(en, en_1, en_2 );
    long double c = c_x(en, en_1, p_x(en, en_1, en_2 ) );

    std::cout.precision(100);
    std::cout << "P = " <<  p << std::endl;
    std::cout << "C = " << c << std::endl;

    long double tmp = c * powl(en, p);

    do
    {
        if( tmp < pow(10, -10) )
        ++liczba_iteracji;
        std::cout << tmp << std::endl;
        tmp = c * powl(tmp, p);
    }

    while(tmp > pow(10, -100));

    std::cout << "Iteracja["<< liczba_iteracji << "] " << tmp << std::endl;

    std::cout <<" A TU JAK SIE AMERYKANIE BAWIĄ " << std::endl;

    liczba_iteracji = 0;

    en = 0.605426053;
    en_1 = 0.055322784;
    en_2 = 0.004819076;
    en_3 = 0.000399783;

    p = p_x(en, en_1, en_2);
    c = c_x(en, en_1, p);
    std::cout << "P = " <<  p << std::endl;
    std::cout << "C = " << c << std::endl;

    tmp = c * powl(en, p);

    do
    {
        if( tmp < pow(10, -10) )
        ++liczba_iteracji;
        std::cout << tmp << std::endl;
        tmp = c * powl(tmp, p);
    }

    while(tmp > pow(10, -100));

    std::cout << "Iteracja["<< liczba_iteracji << "] " << tmp << std::endl;

}
