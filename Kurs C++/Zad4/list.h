//
// Created by Mateusz Pater on 25.03.2016.
//

#ifndef ZAD4C_LIST_H
#define ZAD4C_LIST_H

#include <stdexcept>
#include <iostream>
using namespace std;

class list {

    class wezel {
        wezel *next = 0;
        string val;

    public:

        wezel();

        wezel(const string &_val);

        wezel* return_next();

        void set_next( wezel* _n );

        const string& return_val ();

        void set_val ( const string &_val );

        friend ostream& operator << (ostream &wy, const wezel &wzl);

        ~wezel();

    };

    friend ostream& operator << (ostream &wy, const list::wezel &wzl);

public:

    wezel *first;

    list();

    list(const string &_val);

    list(const list &rhs);

    list(list &&rhs);

    list &operator=(const list &rhs);

    list &operator=(list &&rhs);

    void insert( const string &_val, int poz);

    const string& read( int poz );

    void remove( int poz );

    list( initializer_list<string> lst);

    int size();

    friend ostream& operator << (ostream &wy, const list &lst);

    ~list();
};



#endif //ZAD4C_LIST_H
