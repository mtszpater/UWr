#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "index.h"

using namespace std;


inline ostream& comma (ostream &os)
{
    return os << ", ";
}

inline ostream& colon (ostream &os)
{
    return os << ": ";
}

istream &clearline(istream &in)
{
    while(in && in.get() != '\n')
    {
    }

    return in;
}



bool compare(const pair<int, string>&i, const pair<int, string>&j)
{
    return i.second < j.second;
}


int main() {


    vector<pair <int,string>> tab;
    int i = 1;

    string line;


    /* DRUGA LINIA BEDZIE BEZ 5 ZNAKOW PIERWSZYCH */
    /* PIERWSZA LINIA JEST POMIJANA, WIEC W WEKTORZE BEDZIE PUSTY STRING */

    while(true)
    {
        if( i == 1 )
            clearline(cin);
        else
            cin >> strumienie::ignore2(5) >> line;

        if( line == "end" ) break;

        tab.push_back(make_pair(i,line));
        ++i;
    }

    int len = 1;

    if (i > 0) {
        for (len = 0; i > 0; len++) {
            i = i / 10;
        }
    }

    for(const auto& a : tab) {
        cout << strumienie::index2(a.first, len) << colon << a.second << comma << endl;
    }

    std::sort(tab.begin(), tab.end(), compare);

    cout << " PO SORTOWANIU " << endl;

    for(const auto& a : tab) {
        cout << strumienie::index2(a.first, len) << colon << a.second << comma << endl;
    }


    return 0;
}

