//
// Created by Mateusz Pater on 25.05.2016.
//

#ifndef ZADANIE9MANIPULATORY_INDEX_H
#define ZADANIE9MANIPULATORY_INDEX_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

namespace strumienie {


    class index2 {

        int w;
        int x;

        friend ostream &operator<<(ostream &os, const index2 &licz);
    public:
        index2(int x, int w);
    };

    class ignore2 {

        int x;

        friend istream &operator>>  (istream &os,const ignore2 &licz) ;
    public:
        ignore2(int x);
    };




}


#endif //ZADANIE9MANIPULATORY_INDEX_H
