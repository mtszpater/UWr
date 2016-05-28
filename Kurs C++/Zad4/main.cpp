#include <iostream>
#include "list.h"

using namespace std;

int main() {

    list c = list();
    cout << c << endl; // NIC
    cout << "END TEST0" << endl;


    list s = list("aaa");
    cout << s << endl; // aaa
    cout << "END TEST0.1" << endl;

    list k = list({"test1", "test2", "test3"});

    cout << "Rozmiar: " << k.size() << endl; // 3
    cout << k << endl; // test1, test2, test3
    cout << "END TEST1" << endl;

    k.insert("xxxx", 1); // test1,xxxx,test2,test3
    cout << k << endl;

    cout << "Rozmiar: " << k.size() << endl; // 4
    cout << "2: " << k.read(2) <<endl; // test2
    k.remove(0); // test1
    cout << k << endl; // xxxx, test2, test3
    cout << "END TEST2" <<endl;


    k.remove(0); // xxxx
    cout << k << endl; // test2, test3
    cout << "Rozmiar: " << k.size() << endl; // 2
    cout << "END TEST3" <<endl;

    cout << "Kopiujemy"<<endl;
    list z(k);
    cout << "K: "<< k << endl;
    cout << "Z: "<< z << endl;


    // Przeniesiemy teraz z na o. W z nie powinno byc nic.

    list o = move(z);

    cout << "O: "<< o << endl;
    cout << "Z: "<< z << endl;


    // Proba wywolania nieistniejacego rekordu:
    //o.read(32324);
    //o.read(-100);
    o.remove(123123);
    cout << "O: "<< o << endl;
    return 0;
}