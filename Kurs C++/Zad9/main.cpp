#include "PlikWyjsciowy.h"
#include <vector>
#include "PlikWejsciowy.h"

using namespace std;
using namespace strumienie;


int main() {

    ifstream *myfile = new ifstream("/Users/cotusietonawetjanie/ClionProjects/Zadanie9Manipulatory/tekst.txt");

    PlikWejsciowy plik = PlikWejsciowy(myfile);

    ofstream *myfile2 = new ofstream("/Users/cotusietonawetjanie/ClionProjects/Zadanie9Manipulatory/tekstOutput.txt");

    PlikWyjsciowy plik2 = PlikWyjsciowy(myfile2);

    vector<double> tab;

    double tmp;


    while(true){

        tmp = plik.getLineDouble();
        if(tmp == 0) break;
        cout << tmp;
        tab.push_back(tmp);

    }

    reverse(tab.begin(),tab.end());

    for(const auto& a : tab) {
        cout << a << endl;
        plik2.putDouble(a);
    }



    return 0;

};