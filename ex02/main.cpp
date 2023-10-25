#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
        int					_fixedPointValue;
        const static int    _fractionalBits = 8;
    public:
        Fixed() 
        {
            std::cout << "Default constructor called" << std::endl;
            this->_fixedPointValue = 0;

        }
        ~Fixed()
        {
            std::cout << "Destructor called" << std::endl;
        }
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &fixed);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float operator*(const Fixed &fixed) const;
        float max(const Fixed &fixed1, const Fixed &fixed2);
        float min(const Fixed &fixed1, const Fixed &fixed2);
        float operator+(const Fixed &fixed) const;

};

Fixed ::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed ::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
    return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
   
    return (this->_fixedPointValue);
}


void Fixed::setRawBits(int const raw)
{
   
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
float Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.toFloat() > fixed2.toFloat())
        return (fixed1.toFloat());
    else
        return (fixed2.toFloat());
}

float Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
    if (fixed1.toFloat() < fixed2.toFloat())
        return (fixed1.toFloat());
    else
        return (fixed2.toFloat());
}

float Fixed::operator+(const Fixed &fixed) const
{
    return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator*(const Fixed &fixed) const
{
    return (this->toFloat() * fixed.toFloat());
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}

int main(void)
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    return (0);
}