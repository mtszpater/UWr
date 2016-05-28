//
// Created by Mateusz Pater on 25.05.2016.
//

#include "PlikWyjsciowy.h"



    strumienie::PlikWyjsciowy::PlikWyjsciowy (ofstream *plik) : wsk(plik) {

        try {
            wsk->exceptions(wsk->failbit);
            wsk->exceptions(wsk->badbit);
        }
        catch (ifstream::failure e) {
            std::cout << "Caught an ios_base::failure.\n"
            << "Explanatory string: " << e.what() << '\n'
            << "Error code: " << e.code() << '\n';
        }


    }

    strumienie::PlikWyjsciowy::~PlikWyjsciowy() {
        wsk->close();
        wsk = 0;
    }


    void strumienie::PlikWyjsciowy::putLine(string line)
    {
        *wsk << line << endl;
    }

    void strumienie::PlikWyjsciowy::putChar(char k)
    {
        stringstream ss;
        string s;
        ss << k;
        ss >> s;
        *wsk << s;
    }

    void strumienie::PlikWyjsciowy::putInt(int k)
    {
        stringstream ss;
        string s;
        ss << k;
        ss >> s;
        *wsk << s << " ";
    }

    void strumienie::PlikWyjsciowy::putDouble(double k)
    {
        string s = to_string(k);

        *wsk << std::fixed  << s << " ";
    }




