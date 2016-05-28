//
// Created by Mateusz Pater on 25.05.2016.
//

#include "PlikWejsciowy.h"

strumienie::PlikWejsciowy::PlikWejsciowy (ifstream *plik) : wsk(plik){

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

strumienie::PlikWejsciowy::~PlikWejsciowy() {
    wsk->close();
    wsk = 0;
}

void strumienie::PlikWejsciowy::skipWhiteSpace() {
    while (wsk->peek() == ' ') // skip spaces
        wsk->get();
}

std::string strumienie::PlikWejsciowy::getLineString(){

    skipWhiteSpace();

    string line = "";

    if(!wsk->eof()) getline ((*wsk), line);
    else resetSeek();


    return line;
}

char strumienie::PlikWejsciowy::getLineChar(){

    skipWhiteSpace();

    char c = wsk->get();

    return c;

}


int strumienie::PlikWejsciowy::getLineInt(){

    skipWhiteSpace();

    char c = wsk->get();


    return (int) c - '0';

}

double strumienie::PlikWejsciowy::getLineDouble(){

    skipWhiteSpace();

    float a;

    if(!(*wsk >> a)) return 0;


    return a;



}

void strumienie::PlikWejsciowy::resetSeek(){

    wsk->seekg( 0 );
}

namespace strumienie {
    ostream &operator<<(ostream &o, PlikWejsciowy &f) {

        while (f.wsk->eof()) /* Nie dziala tak jak chce. Pobiera dodatkowe linie z pliku. W jaki sposób to NAJSPRYTNIEJ to powstrzymać? */
        {
            o << f.getLineString() << endl;
        }


        return o;


    }
}
