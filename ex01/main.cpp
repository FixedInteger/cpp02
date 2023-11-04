#include "Fixed.hpp"



std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

int main(void  ) 
{
	Fixed a;
	Fixed const b( 10.12f );
	std::cout << b << std::endl;
}