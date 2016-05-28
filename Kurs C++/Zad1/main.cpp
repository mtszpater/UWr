#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
#include <stdexcept>
#include <sstream>

using namespace std;

vector <long long> podzial ( long long liczba ){
    
    long long k = 2; 
    
    vector <long long> vect;
    
    switch( liczba )
    {
        case -1:
            vect.push_back(-1);

            break;

        case 0:
            vect.push_back(0);

            break;

        case 1:
            vect.push_back(1);

            break;

        default:
            /* Jesli liczba jest ujemna to najpierw przemnozmy ja razy (-1)*/
            if(liczba < -1)
            {
                vect.push_back(-1);
                
                if( liczba < LLONG_MAX * (-1) ){
                    liczba /= 2;
                }
                vect.push_back(2);
                
                liczba = liczba * (-1);    
            }
            /* Skoro juz mamy liczbe dodatnia i wieksza od 1 to po prostu szukajmy jej czynnikow */
            while( liczba > 1 )
            {
                while( liczba % k==0) 
                {        
                    vect.push_back(k);

                    liczba /= k;
                }
                ++k;
            } 


            break;
    }
     
    
    return vect;
}
/* Wypisujemy cala zawartosc vectora */
void wypisz ( vector < long long > vect ){
    
    for( size_t i = 0; i < vect.size(); i++ )
    {
        if(i+1 == vect.size()){ cout << vect[i] << endl; }
         
        else { cout <<  vect[ i ]  << "*"; }      
    }
        
}
/* Sprawdzamy czy argument jest liczba */
template<typename T> bool num(const char *str)
{
    istringstream ss(str);
    T val;
    return (ss>>val)&&(ss.get()==EOF);
}

int main(int argc, char** argv) {
    
    if(argc == 1) cerr << "Za malo argumentow przy wywolaniu programu. Wywolaj program z argumentami typu liczbowego"; 
    
    for( int i = 1; i < argc; ++i ){
        
        if(num<long long>(argv[i])){
            
            long long liczba = atoll(argv[i]);
            
            if( liczba < LLONG_MIN || liczba > LLONG_MAX ){ throw std::invalid_argument("Za mala/duza liczba."); }

            cout << argv[i]  << " = ";

            vector <long long> vect = podzial ( liczba );

            wypisz ( vect );
            
        }
        else
        {
            throw std::invalid_argument("Zly argument");
        }
    }
    

            
    return 0;
}

