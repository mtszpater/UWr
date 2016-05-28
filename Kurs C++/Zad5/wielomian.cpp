//
// Created by Mateusz Pater on 26.03.2016.
//

#include "wielomian.h"

    wielomian::wielomian(int st, double wsp){

        n = st;
        a = new double[st+1];
        a[0] = wsp;
    }

    wielomian::wielomian(int st, double wsp[]){
        n = st;
        a = wsp;

    }

    wielomian::wielomian( initializer_list<double> wsp ){

        n = wsp.size();
        a = new double[n+1];

        int i =0;
        for (auto value : wsp)
        {
            a[i] = value;
            ++i;
        }
    }



    wielomian::wielomian(const wielomian& zrodlo) : n(zrodlo.n), a(new double[zrodlo.n+1]) {
        std::copy( zrodlo.a, zrodlo.a+n+1,a);
    }



    wielomian&  wielomian::operator=(const wielomian& zrodlo) {
        if (&zrodlo==this) return *this; 
        n = zrodlo.n;
        a = new double [n+1];
        std::copy(zrodlo.a, zrodlo.a+n+1,a);
        return *this;
    }

    wielomian::wielomian (wielomian &&zrodlo) : n(zrodlo.n), a(zrodlo.a)
    {
        zrodlo.a = nullptr;
    }

    wielomian&  wielomian::operator=(wielomian&& zrodlo) {
        std::swap(n, zrodlo.n);
        std::swap(a, zrodlo.a);
        return *this;
    }


    int wielomian::zwroc_stopien(){
        return this->n;
    }
    double wielomian::oblicz(double x){
        double wartosc = 0;
        if(this->n == 0) return this->a[0];


        for(int i = this->n; i >= 0; --i){
            wartosc *= x;
            wartosc += this->a[i];

        }
        return wartosc;
    }

    double& wielomian::operator[](int idx) {
        if( idx > this->n ) {  throw std::invalid_argument("Zly stopien"); }

        return this->a[idx];
    }


    const double& wielomian::operator[](int idx) const
    {
        if( idx > this->n ) {  throw std::invalid_argument("Zly stopien"); }

        return this->a[idx];
    };


    wielomian operator+ ( const wielomian& v, wielomian u )
    {

        if( v.n > u.n ) {
            for (int i = 0; i <= u.n; ++i) {
                v.a[i] += u.a[i];
            }

            return v;
        }


        for( int i = 0; i <= v.n; ++i ){
            u.a[i] += v.a[i];
        }
        return u;

    }

    wielomian operator- ( const wielomian& v, wielomian u )
    {

        if( v.n > u.n ) {
            for (int i = 0; i <= u.n; ++i) {
                v.a[i] -= u.a[i];
            }

            return v;
        }


        for( int i = 0; i <= v.n; ++i ){
            u.a[i] -= v.a[i];
        }


        return u;

    }

    wielomian operator * ( const wielomian& v, wielomian u )
    {
        double *tab = new double[u.n + v.n];

        for(int i = 0; i <= u.n + v.n; ++i ) tab[i] = 0;



        for(int i = u.n; i >= 0; --i){
            for(int j = v.n; j >= 0; --j){

                tab[i+j] += v.a[j] * u.a[i];

            }
        }

        u.a = tab;


        u.n += v.n;


        return u;
    }

    wielomian operator * ( double k, wielomian u )
    {
        for( int i = 0; i <= u.n; ++i ){
            u.a[i] = u.a[i] * k;
        }
        return u;

    }

    wielomian& wielomian::operator += ( const wielomian & v )
    {
        int st;

        if(this->n > v.n){
            st = v.n;
        }
        else{
            st = this->n;
        }

        for(int i = 0; i <= st; ++i){
            this->a[i] += v.a[i];
        }

        return * this;
    }

    wielomian& wielomian::operator -= ( const wielomian & v )
    {
        int st;

        if(this->n > v.n){
            st = v.n;
        }
        else{
            st = this->n;
        }

        for(int i = 0; i <= st; ++i){
            this->a[i] -= v.a[i];
        }

        return * this;
    }

    wielomian& wielomian::operator *= ( const wielomian & v )
    {
        double *tab = new double[this->n + v.n];

        for(int i = 0; i <= this->n + v.n; ++i ) tab[i] = 0;



        for(int i = this->n; i >= 0; --i){
            for(int j = v.n; j >= 0; --j){

                tab[i+j] += v.a[j] * this->a[i];

            }
        }
        this->a = tab;


        this->n += v.n-1;

        return *this;
    }

    wielomian& wielomian::operator *= ( double k )
    {
        for( int i = 0; i < this->n; ++i ){
            this->a[i] = this->a[i] * k;
        }
        return *this;

    }


    ostream& operator << (ostream &wy, const wielomian &w){

        string wynik;

        for( int i = 0; i <= w.n ; ++i){
            if(w.a[i] != 0){

                if(i == 0){
                    wynik = to_string(w.a[0]);
                }
                else if(i == 1){
                    wynik = wynik + " " + to_string(w.a[1]) + "x";
                }
                else{
                    wynik = wynik + " " + to_string(w.a[i]) + "x^" + to_string(i) + " ";
                }
                if(i < w.n) wynik = wynik  + " + ";
            }
        }

        return wy << wynik;
    }

    istream& operator >> (istream &we, wielomian &w){
        for( int i = 0; i < w.n+1; ++i ){
            we >> w.a[i];
        }
        if( w.a[w.n] == 0) { throw std::invalid_argument("Zly stopien"); }

        return we;
    }

    wielomian::~wielomian(){
        delete []a;
    }

