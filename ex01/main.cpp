#include <iostream>
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
   
    return (this->_fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
  
    this->_fixedPointValue = raw;
}
Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}
Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}
 Fixed:: Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
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

int main(void  ) 
{
    Fixed a;
    Fixed const b( 10.12f );
    std::cout << b << std::endl;
}