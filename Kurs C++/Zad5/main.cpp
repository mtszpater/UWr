#include <iostream>
#include "wielomian.h"
using namespace std;



int main() {


    /*Testowanie przenoszenia/kopiowania
     DO ODKOMENTOWANIA*/
/*
    //Wielomian z listy
    wielomian l = wielomian({1,2,3,4,5});
    cout << l << endl;


    double *a1 = new double[3];
    a1[0] = 1;
    a1[1] = 2;
    a1[2] = 3;
    a1[3] = 4;

    wielomian aa1 = wielomian(3, a1);

    cout <<"aa1:" << aa1 << endl;
    wielomian bb1 = aa1;

    bb1 += aa1;
    cout << bb1 << endl;
    bb1 -= aa1;
    cout << bb1 << endl;
    bb1 *= aa1;
    cout << bb1 << endl;

    cout <<"bb1" << bb1 << endl;
    wielomian cc1 = move(aa1);
    cout <<"cc1" << cc1 << endl;

    //cout <<"pzeniesione aa1" << aa1 << endl; //

*/


    int st, st_x;
    cout << "Wpisz stopien wielomianu" << endl;
    cin >> st;
    if (st < 0) { throw std::invalid_argument("Invalid argument"); }

    double *x = new double[st + 1];
    double *x_tmp, wart;
    wielomian a_tmp, aa;
    wielomian a = wielomian(st, x);


    cout << "Wpisz wspolczynniki" << endl;
    cin >> a;

    cout << a << endl;

    while (true) {
        int action = 0;
        cout << "Mozliwe operacje: " << endl;

        cout << "1. Dodaj " << endl;
        cout << "2. Odejmij " << endl;
        cout << "3. Pomnoz  " << endl;
        cout << "4. Pomnoz przez liczbe" << endl;
        cout << "5. Oblicz wartosc wyrazenia" << endl;
        cout << "6. Przypomnij glowny wielomian " << endl;
        cout << "7. Podaj wartosc ntego stopnia" << endl;
        cout << "8. Zamiana wspolczynnikow wielomianu" << endl;
        cout << "Exit: " << endl;


        cin >> action;


        switch (action) {
            case 1:

                cout << "Wpisz stopien wielomianu" << endl;
                cin >> st;
                if (st < 0) { cerr << "Invalid argument" << endl; break; }

                x_tmp = new double[st + 1];
                a_tmp = wielomian(st, x_tmp);

                cout << "Wpisz wspolczynniki" << endl;
                cin >> a_tmp;
                cout << a_tmp<< endl;
                cout << "Wynik: " << endl;
                aa = a_tmp + a;
                cout << aa << endl;

                delete[] x_tmp;
                break;

            case 2:

                cout << "Wpisz stopien wielomianu" << endl;
                cin >> st;
                if (st < 0) { cerr << "Invalid argument" << endl; break; }

                x_tmp = new double[st + 1];
                a_tmp = wielomian(st, x_tmp);

                cout << "Wpisz wspolczynniki" << endl;
                cin >> a_tmp;
                cout << a_tmp<< endl;
                cout << "Wynik: " << endl;
                aa = a_tmp - a;
                cout << aa << endl;

                delete[] x_tmp;
                break;

            case 3:

                cout << "Wpisz stopien wielomianu" << endl;
                cin >> st;
                if (st < 0) { cerr << "Invalid argument" << endl; break; }

                x_tmp = new double[st + 1];
                a_tmp = wielomian(st, x_tmp);

                cout << "Wpisz wspolczynniki" << endl;
                cin >> a_tmp;
                cout << a_tmp<< endl;
                cout << "Wynik: " << endl;
                aa = a_tmp * a;
                cout << aa << endl;

                delete[] x_tmp;
                break;

            case 4:

                st = 0;
                cout << "Podaj liczbe" << endl;
                cin >> st;
                aa = st * a;
                cout << aa << endl;

                break;

            case 5:

                cout << "Wpisz stopien wielomianu" << endl;
                cin >> st;
                if (st < 0) { cerr << "Invalid argument" << endl; break; }

                x_tmp = new double[st + 1];
                a_tmp = wielomian(st, x_tmp);

                cout << "Wpisz wspolczynniki" << endl;
                cin >> a_tmp;
                cout << a_tmp<< endl;
                cout << "Wielomian: " << endl;
                wart = 0;
                cout << "Podaj wartosc X" << endl;
                cin >> wart;
                cout << a_tmp.oblicz(wart) << endl;

                break;

            case 6:
                cout << a;
                break;

            case 7:
                cout << "Podaj ktory stopien: "<< endl;
                cin >> st;
                if (st < 0 || st > a.zwroc_stopien()) { cerr << "Invalid argument" << endl; break; }
                cout << a[st] << endl;
                // ZAMIANA ST'EGO STOPNIA NA k - OPERATOR INDEKSOWANIA TEST
                a[st] = 7;
                cout << a[st] << endl;

                cout << a;
                break;


            case 8:
                cout << "Podaj ktory stopien: "<< endl;
                cin >> st;
                if (st < 0 || st > a.zwroc_stopien()) { cerr << "Invalid argument" << endl; break; }
                cout << a[st] << endl;

                cout << "Podaj na co zamienic: "<< endl;

                cin >> st_x;
                if( st == a.zwroc_stopien() && st_x == 0) { cerr << "Invalid argument" << endl; break; }
                a[st] = st_x;
                cout << a[st] << endl;

                cout << a;
                break;

            default:
                return 0;
        }
    }




}