//
// Created by Mateusz Pater on 25.05.2016.
//

#ifndef ZADANIE9MANIPULATORY_PLIKWEJSCIOWY_H
#define ZADANIE9MANIPULATORY_PLIKWEJSCIOWY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

namespace strumienie{
    using namespace std;
    class PlikWejsciowy {
        ifstream *wsk;


    public:



        PlikWejsciowy (ifstream *plik);

        ~PlikWejsciowy();

        void skipWhiteSpace();

        string getLineString();

        char getLineChar();

        int getLineInt();

        double getLineDouble();

        void resetSeek();

        friend ostream& operator<<(ostream& o,  PlikWejsciowy& f);



    };
}

#endif //ZADANIE9MANIPULATORY_PLIKWEJSCIOWY_H
