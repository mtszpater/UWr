#include <iostream>
#include <random>
#include <list>
#include <fstream>
#include "PlikWyjsciowy.h"

#define LIMIT 100

using namespace std;
using namespace strumienie;

int generateRandom(int limit)
{
    random_device rd;
    mt19937 re(rd());

    uniform_int_distribution<int> ui(0, limit);

    return ui(re);
}


int main() {
    ofstream myfile2 = ofstream("/Users/teez/UWr/Kurs C++/Zad11a/Imiona.txt");
    ifstream *myfile = new ifstream("/Users/teez/UWr/Kurs C++/Zad11a/Imiona.txt");

    int k = generateRandom(LIMIT);
    int n = generateRandom(LIMIT); //tyle liczb generujemy

    cout << "k: " << k << " n: " << n << endl;

    /* WPISYWANIE DO PLIKU */

    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    myfile2 << s << "\n";

    for (int i = 0; i < n; ++i)
    {
        stringstream ss;
        string s;
        ss << generateRandom(k);
        ss >> s;
        myfile2 << s << "\n";
    }

    myfile2.close();

    /* CZYTANIE Z PLIKU */
    list <int> lista;


    string napis;
    getline( *myfile, napis );

    while( myfile->good() )
    {
        getline( *myfile, napis );
        lista.push_back(atoi(napis.c_str()));
    }

    lista.pop_back();

    myfile->close();

    int max = -1;
    int min = -1;
    int average = 0;
    int count = 0;
    
    for( auto const& l : lista ) {
        ++ count;

        if(max == -1 && min == -1){  max = l; min = l; }
        if( max < l ) max = l;
        if( min > l ) min = l;
        average += l;

        cout << l << endl;
    }
    average /= count;

    cout << "MAX: " << max << " MIN: " << min << " AVERAGE: " << average;





    return 0;

}