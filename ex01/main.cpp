#include <iostream>
class Fixed
{
    private:
        int					_fixedPointValue;
        const static int    _fractionalBits = 8;
    public:
        Fixed(){
            std::cout << "Default constructor called" << std::endl;
            this->_fixedPointValue = 0;
        };
        ~Fixed()
        {
            std::cout << "Destructor called" << std::endl;
        }
        Fixed(const int value);
        Fixed(const Fixed &fixed);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

Fixed ::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy Assignement operator called" << std::endl;
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}


int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}