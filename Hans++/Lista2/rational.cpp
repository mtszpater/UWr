
#include "rational.h"

// Complete these methods:

#if 1

int rational::gcd( int n1, int n2 ){
	if(n2 == 0)
		return n1;
	else
		return gcd(n2, n1%n2);
}

void rational::normalize( ){
	int d = gcd(num, denum);

	if(d == 0){
		throw std::runtime_error( "division by zero" ); 
	}
	 
	num /= d;
	denum /= d;
}

rational operator - ( rational r ){
	return rational(r.num * -1);
}

rational operator + ( const rational& r1, const rational& r2 ){
	return rational( r1.num*r2.denum + r2.num*r1.denum, r1.denum*r2.denum );
}

rational operator - ( const rational& r1, const rational& r2 ){
 	return rational( r1.num*r2.denum - r2.num*r1.denum, r1.denum*r2.denum );
}

rational operator * ( const rational& r1, const rational& r2 ){
	return rational( r1.num*r2.num, r1.denum*r2.denum );
}

rational operator / ( const rational& r1, const rational& r2 ){
	return rational( r1.num*r2.denum, r1.denum*r2.num );
}

bool operator == ( const rational& r1, const rational& r2 ){
	return r1.num == r2.num && r1.denum == r2.denum;
}

bool operator != ( const rational& r1, const rational& r2 ){
	return r1.num != r2.num || r1.denum != r2.denum;
}

std::ostream& operator << ( std::ostream& stream, const rational& r ) {
	stream << r.num << "/" << r.denum;
   	return stream;
}

#endif

