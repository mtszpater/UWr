#include <iostream>
#include "stos.h"

using namespace std;



int main() {

    stos k = stos(300);
    stos a;
    cout << "Rozmiar:" << k.rozmiar() << endl;
    k.wloz(5.00);
    k.wloz(3.00);
    a=k;


    k.wloz(5.00);
    k.wloz(15.00);
    k.wloz(153.00);
    k.wloz(35.00);
    cout << "Na samej gorze:" << k.sprawdz() << endl;
    k.sciagnij();
    cout << "Na samej gorze:" << k.sprawdz() << endl;
    k.sciagnij();
    cout << "Na samej gorze:" << k.sprawdz() << endl;
    k.sciagnij();

    cout << "Rozmiar:" << k.rozmiar() << endl;

    cout << "Rozmiar[a] powinien byc rozny od rozmiaru k:" << a.rozmiar() << endl;

    k.wypisz_stos();




    double t[] = { 4.00, 2.00, 3.00, 4.00 , 5.00, 342.00 };
    stos b = stos(t);

    b.wypisz_stos();
    b.sciagnij();
    b.wypisz_stos();
    b.wloz(5.00);
    b.wypisz_stos();

    cout << "Hello, World!" << endl;
    a.wypisz_stos();

    stos c(move(a));
    c.wypisz_stos();

    stos d = move(c);

    cout << "Wypisanie d" << endl;
    d.wypisz_stos();
    return 0;
}