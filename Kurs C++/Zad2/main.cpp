#include <cstdlib>
#include <iostream>
#include <cmath>
#include "punkt.h"
#include "wektor.h"
#include "prosta.h"


using namespace std;


int main(int argc, char** argv) {

    /* TESTY */

    /* Sprawdzenie 1 konstruktora, czyli prosta przechodzaca przez 2 punkty */

    punkt a = punkt(6,7);
    punkt b = punkt(5,8);

    prosta pierwsza = prosta(a,b);

    /* Sprawdze poprawnosc od razu funkcji lezy(), czyli teoretycznie punkt a powinien lezec na w/w prostej */
    cout << "Prosta (1): " << pierwsza.return_a() << "x " << pierwsza.return_b() << "y " << pierwsza.return_c() << endl;
    if(pierwsza.lezy(a) == 0) cout << "punkt A lezy" <<endl;

    /* Sprawdzenie 2 konstruktora, czyli jawne zadeklarowanie A/B/C */
    prosta druga = prosta(-3, -4,7);
    punkt c = punkt( 1,1 );
    /* Jest to prosta -3x + 4y -7 = 0zatem punkt (1,1) powinien lezeć na tej prostej */
    cout << "Prosta (2): " << druga.return_a() << "x " << druga.return_b() << "y " << druga.return_c() << endl;
    if(druga.lezy(c) == 0) cout << "punkt C lezy" <<endl;

    /* Dla porownania punkt a(6,7) nie powinien lezec na prostej drugiej */
    cout << "Odleglosc punktu A od prostej drugiej: "<<druga.lezy(a) <<endl;

    /* Sprawdzenie 3 konstruktora, czyli prosta przesunieta o wektor */
    wektor w = wektor(1,2);
    prosta trzecia = prosta(w, druga);
    cout << "Prosta (3): " << trzecia.return_a() << "x " << trzecia.return_b() << "y " << trzecia.return_c() << endl;

    /* Sprawdzenie 4 konstruktora, prosta wyznaczona przez wektor i prostopadla do niego */
    prosta czwarta = prosta(w);
    cout << "Prosta (4): " << czwarta.return_a() << "x " << czwarta.return_b() << "y " << czwarta.return_c() << endl;

    /* Oraz przy okazji sprawdzenie metody czy wektor jest prostopadly do prostej (a powinien w w/w wypadku) */
    if(czwarta.wektor_prostopadly(w)) cout << "Wektor jest prostopadly" << endl;
    /* Sprawdzenie innego, losowego wektora */
    wektor w2 = wektor(5,1203);
    if(czwarta.wektor_prostopadly(w2)) cout <<"[] Wektor jest prostopadly" << endl; // tego nie powinno wyswietlic


    /* Metoda wyznaczajaca punkt przeciecia prostej "pierwszej" z "druga" : */
    punkt xs = pierwsza.przeciecie(druga);

    cout << "Punkt : " << xs.return_x() << "," << xs.return_y() << endl;

    /* Sprawdzenie czy proste sa prostopadle */
    if(pierwsza.prostopadle(druga)) cout << "Pierwsza jest prostopadla do drugiej"; // nie powinno tego wyswietlic

    /* Sprawdzenie czy sa rownolegle */
    prosta piata = prosta(-3, -4, 3);
    if(druga.rownolegle(piata))  cout << "Rownolegla piata do drugiej" << endl;


    /* Sprawdzenie czy wektor jest rownolegly do prostej */

    prosta szosta = prosta(2, -1, 4);
    wektor w3 = wektor(4,8);

    if(szosta.wektor_rownolegly(w3)) cout << "Wektor rownolegly" << endl; // powinno to wyswietlic
    w3 = wektor(4,9);
    if(szosta.wektor_rownolegly(w3)) cout << "[] Wektor rownolegly" << endl; // tego nie powinno to wyswietlic

    /* Punkt przesuniety o wektor */

    punkt p4 = punkt(3,0, w3); // powinno wyjsc punkt (3,0) przesuniety o wektor (4,9) (3+4, 0+9) z wektora w3
    cout << "punkt o x/y " << p4.return_x() << "/" << p4.return_y(); //

    return 0;
}

