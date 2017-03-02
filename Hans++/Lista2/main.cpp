
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
   rational r1( 2, 6 );
   rational r2( 4, 3 ); 
   rational r3( 5,6 );
   rational r4( 1, 2 );
      
   matrix m1 = { { rational(1,2), rational(1,3) }, { rational(-2,7), rational(2,8) } };
   std::cout << m1 << "\n";

   matrix m2 = { { 5,4 }, { 6, rational(1,2) } }; 
   std::cout << m2 << "\n";

   matrix m3 = { { 4,5}, { -1, 2 }};
   
   std::cout << "\n\n";
   std::cout << (m1*m2)*m3 << std::endl;
   std::cout << m1*(m2*m3) << std::endl;
   
   std::cout << "\n\n";
   std::cout << (m1*m2)*rational(1,2) << std::endl;
   std::cout << m1*(m2*rational(1,2)) << std::endl;
   
   std::cout << "\n\n";
   std::cout << m1.inverse()*m1 << std::endl;

   std::cout << m1. determinant( ) << "\n";
   std::cout << m1. adjugate( ) << "\n";
   std::cout << m1. inverse( ) * m1 << "\n";

}

