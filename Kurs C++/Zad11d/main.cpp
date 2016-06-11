#include <iostream>
#include <deque>
#include <random>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using namespace std;




int main() {
    std::deque <double > v;

    auto fun = [] ( int x ) { return x < 3 && x > 0;  } ;

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(6, 2);


    for( int i = 0; i < 25; ++i)
    {
        double k = distribution(generator);
        cout << k << endl;
        v.push_back(k);
    }


    int num_items1 = std::count_if(v.begin(), v.end(), fun);

    deque<double>::iterator it = std::find_if(v.begin(), v.end(), fun);

    std::cout << "count: " << num_items1 << '\n';

    std::cout << "First value: " << *it << '\n';



    return 0;
}