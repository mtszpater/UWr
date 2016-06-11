#include <iostream>
#include <deque>
#include <random>
#include <iomanip>
#include <map>


using namespace std;

int main() {

    std::deque <int > v;

    auto fun = [] ( int x ) { return x < 2 || x > 8;  } ;

    std::default_random_engine generator;
    std::binomial_distribution<int> distribution(10,0.55);


    for( int i = 0; i < 25; ++i)
    {
        int k = distribution(generator);
        cout << k << endl;
        v.push_back(k);
    }


    v.erase(std::remove_if(v.begin(),
                             v.end(),
                             fun),
              v.end());

    int num_items1 = std::count_if(v.begin(), v.end(),  [] ( int x ) { return x > 4 && x < 6;  } );


    cout << "PO USUNIECIU " << endl;
    for (std::deque<int>::iterator it = v.begin(); it!=v.end(); ++it)
        std::cout << *it << endl;

      std::cout << "wiekszych od 4 i mniejszych od 6 lacznie: " << num_items1 << '\n';


    return 0;
}