#include <iostream>
#include "wyrazenie.h"
#include "zmienna.h"
#include "stala.h"
#include "dodaj.h"
#include "odejmij.h"
#include "pomnoz.h"
#include "podziel.h"
#include "potega.h"
#include "log.h"
#include "modulo.h"
#include "lognat.h"
#include "exp.h"
#include "sinus.h"
#include "cosinus.h"
#include "odwrotna.h"
#include "bezwgledna.h"
#include "przeciwna.h"
#include "pi.h"
#include "e.h"

using namespace std;

int main() {



    wyrazenie *a = new dodaj( new stala(3), new zmienna("x"));

    cout << a->opis() << endl;

    a = new odejmij( new stala(3), new zmienna("y"));

    cout << a->opis() << endl;

    a = new pomnoz( new stala(3), new zmienna("x"));

    cout << a->opis() << endl;

    a = new podziel( new stala(3), new stala(3) );

    cout << a->opis() << endl;

    a = new potega( new stala(3), new stala(3) );

    cout << a->opis() << endl;

    a = new dodaj(
            new stala(2),
            new pomnoz(
                    new stala(3),
                    new zmienna("x")
            )
    );

    cout << a->opis() << endl;
    cout << a->formatuj_wyrazenie() << endl;

    a = new logarytm( new stala(2), new stala(8));

    cout << a->opis() << endl;

    a = new modulo( new stala(2), new stala(1));

    cout << a->opis() << endl;

    a = new lognat( new stala(1) );

    cout << a->opis() << endl;

    a = new bezwgledna( new stala(-11) );

    cout << a->opis() << endl;

    a = new odwrotna( new stala(15) );

    cout << a->opis() << endl;

    a = new exponent( new stala(1) );

    cout << a->opis() << endl;

    a = new cosinus( new stala(90) );

    cout << a->opis() << endl;

    a = new sinus( new stala(90) );

    cout << a->opis() << endl;

    a = new przeciwna( new stala(90) );

    cout << a->opis() << endl;

    a = new pi( );

    cout << a->opis() << endl;

    a = new e( );

    cout << a->opis() << endl;

    zmienna *x = new zmienna("x");
    // 2 + x * 7
    a = new dodaj (
            new stala(2),
            new pomnoz(
                    x,
                    new stala(7)
            )
    );
    cout << a->formatuj_wyrazenie() << endl;
    cout << a->opis() << endl;


    // (3+5)/2+x *7
    wyrazenie *b = new podziel (
            new dodaj(
                    new stala(3),
                    new stala(5)
            ),
            new dodaj (
                    new stala(2),
                    new pomnoz(
                            x,
                            new stala(7)
                    )
            )
    );
    cout << b->formatuj_wyrazenie() << endl;
    cout << b->opis() << endl;


    // ((x+1)*x)/2
    wyrazenie *c = new podziel (
            new pomnoz(
                    new dodaj(
                            x,
                            new stala(1)
                    ),
                    x
            ),
            new stala(2)
    );

    cout << c->formatuj_wyrazenie() << endl;
    cout << c->opis() << endl;


    // sin((x+1)*x)
    wyrazenie *d = new sinus (
            new pomnoz(
                    new dodaj(
                            x,
                            new stala(1)
                    ),
                    x
            )
    );

    cout << d->formatuj_wyrazenie() << endl;
    cout << d->opis() << endl;

    cout << "A: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << a->opis() << endl;
    }

    cout << "B: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << b->opis() << endl;
    }


    cout << "C: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << c->opis() << endl;
    }

    cout << "D: " << endl;

    for(int i = 0; i < 100; ++i){
        x->setValue((double) i/100 );
        cout << d->opis() << endl;
    }


    /* Dodamy nowa zmienna i wyprobujemy na niej */

    x->newPair("o", 3);
    x->changeValue("o");

    // 3 +5
    a = new dodaj( x, new stala(5) );
    cout << a->opis() << endl;
    return 0;
}
