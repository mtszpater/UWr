//
// Created by Mateusz Pater on 23.04.2016.
//

#ifndef WYMIERNA_WYMIERNA_H
#define WYMIERNA_WYMIERNA_H

#include <stdexcept>
#include <iostream>
#include <math.h>
namespace obliczenia {
    class wymierna {

    public:
        wymierna(int licznik, int mianownik);

        wymierna(int liczba);

        wymierna(const wymierna &) = default;

        wymierna(wymierna &&) = default;

        int getLicznik() const;

        int getMianownik() const;

        friend wymierna operator+(const wymierna &v, wymierna u);

        friend wymierna operator-(const wymierna &v, wymierna u);

        friend wymierna operator*(const wymierna &v, wymierna u);

        friend wymierna operator/(const wymierna &v, wymierna u);

        friend std::ostream &operator<<(std::ostream &wy, const wymierna &u);

        friend wymierna operator-(wymierna &a);

        friend wymierna operator!(wymierna &a);

        operator int const();

        operator double const();

        int nwd(int a, int b);

        int nww(int a, int b);

    private:
        void Ustaw(int licznik, int mianownik);

        int licznik;
        int mianownik;


    };

}


#endif //WYMIERNA_WYMIERNA_H
