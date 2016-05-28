//
// Created by Mateusz Pater on 25.05.2016.
//

#ifndef ZADANIE9MANIPULATORY_PLIKWYJSCIOWY_H
#define ZADANIE9MANIPULATORY_PLIKWYJSCIOWY_H


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace strumienie {

    using namespace std;

    class PlikWyjsciowy {
        ofstream *wsk;


    public:

        PlikWyjsciowy(ofstream *plik);

        ~PlikWyjsciowy();

        void putLine(string line);

        void putChar(char k);

        void putInt(int k);

        void putDouble(double k);

    };


}
#endif //ZADANIE9MANIPULATORY_PLIKWYJSCIOWY_H
