
#include "Fixed.hpp"


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

int main()
{
    Fixed a(2137.21f);
    Fixed b(5);
    Fixed c(5);
    
    std::cout <<"max" << Fixed::max(b, c) << std::endl;
  
}