//
// Created by Mateusz Pater on 23.04.2016.
//

#include "wymierna.h"

using namespace obliczenia;

wymierna::wymierna(int licznik, int mianownik) {

    try
    {
        Ustaw(licznik, mianownik);
    }
    catch (std::exception& e)
    {
        std::cerr << "Sth went wrong " << e.what() << '\n';
    }

}

/* Konstruktor dla liczb całkowitych */
wymierna::wymierna(int liczba) : wymierna(liczba, 1) { }

int wymierna::getLicznik() const {
    return licznik;
}

int wymierna::getMianownik() const {
    return mianownik;
}

/* Największy wspólny dzielnik */
int wymierna::nwd(int a, int b) {

    a = std::abs(a);
    b = std::abs(b);

    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;
}

int wymierna::nww(int a, int b)
{
    return a/nwd(a,b)*b;
}


/* Zweryfikuj liczby i ostatecznie przypisz składowe */
void wymierna::Ustaw(int licznik, int mianownik){

    if(mianownik == 0) throw std::invalid_argument("Dzielenie przez zero");

    if(nwd(licznik, mianownik) != 1) throw std::invalid_argument("NWD liczb powinno być równe 1");

    if(mianownik < 0) {
        this->licznik = (-1)*licznik;
        this->mianownik = (-1)*mianownik;
    }
    else {
        this->licznik = licznik;
        this->mianownik = mianownik;
    }

}
wymierna::operator int const() {

    return licznik/mianownik;
}

wymierna::operator double const() {

    return 1.0*licznik/mianownik;
}




namespace obliczenia {

    wymierna operator+(const wymierna &v, wymierna u) {
        int temp_licznik, temp_mianownik;

        temp_mianownik = u.nww(u.mianownik, v.mianownik);
        int pom = temp_licznik = temp_mianownik / v.mianownik * v.licznik + temp_mianownik / u.mianownik * u.licznik;

        temp_licznik /= u.nwd(pom, temp_mianownik);
        temp_mianownik /= u.nwd(pom, temp_mianownik);

        u.mianownik = temp_mianownik;
        u.licznik = temp_licznik;

        return u;
    }


    wymierna operator-(const wymierna &v, wymierna u) {
        int temp_licznik, temp_mianownik;

        temp_mianownik = u.nww(u.mianownik, v.mianownik);
        int pom = temp_licznik = temp_mianownik / v.mianownik * v.licznik - temp_mianownik / u.mianownik * u.licznik;

        temp_licznik /= u.nwd(pom, temp_mianownik);
        temp_mianownik /= u.nwd(pom, temp_mianownik);

        u.mianownik = temp_mianownik;
        u.licznik = temp_licznik;

        return u;
    }

    wymierna operator*(const wymierna &v, wymierna u) {
        u.mianownik *= v.mianownik;
        u.licznik *= v.licznik;

        return u;
    }

    wymierna operator/(const wymierna &v, wymierna u) {
        u.mianownik *= v.licznik;
        u.licznik *= v.mianownik;

        return u;
    }


    wymierna operator-(wymierna &a) {
        a.licznik = (-1) * a.licznik;
        return a;
    }


    wymierna operator!(wymierna &a) {

        /* Chciałem użyć std::swap ale ten minus przy liczniku psuje prostote :c */
        a.Ustaw(a.mianownik, a.licznik);

        return a;
    }

    std::ostream& operator << (std::ostream &wy, const wymierna &w){

        return wy << 1.0*w.licznik/w.mianownik;
    }


}

