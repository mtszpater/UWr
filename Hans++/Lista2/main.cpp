
#include "rational.h"
#include "matrix.h"

int main( int argc, char* argv [ ] )
{
      
   matrix m1 = { { rational(1,2), rational(1,3) }, { rational(-2,7), rational(2,8) } };
   std::cout << m1 << "\n";

   matrix m2 = { {rational(-1,3), rational(2,7)}, { rational(2,5), rational(-1,7) } }; 
   std::cout << m2 << "\n";

   matrix m3 = { { rational(1,2), rational(-2,7)} , { rational(1,3) , rational(2,8) } };
   

   std::cout << "Mnozenie m1,m2 " << "\n" << m1*m2 << std::endl;

   std::cout << "inwersja m3" << std::endl;
   std::cout << m3 << std::endl;
   std::cout << m3.inverse() << std::endl;
   std::cout << m3.determinant() << std::endl;



   std::cout << "Zadanie 5" << std::endl;
   std::cout << (m1 * m2) * m3 - m1 * (m2 * m3) << std::endl;

   std::cout << m1*(m2+m3) - (m1*m2+m1*m3) << std::endl;
   std::cout << (m1+m2)*m3 - (m1*m3+m2*m3) << std::endl;

   std::cout << m1.determinant() * m2.determinant() - (m1*m2).determinant() << std::endl;
   std::cout << m1*(m1.inverse()) << std::endl;
   std::cout << m1.inverse()*m1 << std::endl;

}

