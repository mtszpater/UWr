#include <iostream>
#include "wymierna.h"

using namespace std;


void foo( int licznik, int mianownik ){


    int wynik = 0;

    if( licznik > mianownik ) wynik = licznik/mianownik;

    while ( mianownik < licznik ) licznik -= mianownik;

    cout << wynik << endl;

    cout << licznik << " " << mianownik << endl;

    int a = (licznik * 10) / mianownik;
    int b = 0;
    cout << "a: " << a << endl;

    licznik = licznik* 10 - a*mianownik;



    for( int i = 0; i < 10; ++i) {


        cout <<  " => " << licznik << endl;
        licznik = (licznik * 10) - b * mianownik;

        b = (licznik * 10) / mianownik;

        cout << "b: " << b << endl;


    }

}



int main() {


    obliczenia::wymierna a = obliczenia::wymierna(1, 3);

    obliczenia::wymierna b = 5;

    //wymierna c = wymierna(-5, -6);

    obliczenia::wymierna d = obliczenia::wymierna(1, 3);

    obliczenia::wymierna c = b+a;

    cout << c.getLicznik() << "/" << c.getMianownik() << endl;

    cout << b.getLicznik() << "/" << b.getMianownik() << endl;

    cout << a.getLicznik() << "/" << a.getMianownik() << endl;

    cout << c.getLicznik() << "/" << c.getMianownik() << endl;

    cout << d.getLicznik() << "/" << d.getMianownik() << endl;

    -b;
    !b;


    cout << (double) d << endl;
    cout << b.getLicznik() << "/" << b.getMianownik() << endl;


    cout << a << endl;



    cout << "asd" << endl;
    foo(1,3);


    return 0;
}

