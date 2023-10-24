#include <iostream>
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
        int add(Fixed const &fixed) const;
        int sub(Fixed const &fixed) const;
        int mul(Fixed const &fixed) const;
        int div(Fixed const &fixed) const;
        int compareTo(Fixed const &fixed) const;
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int min(Fixed const &fixed) const;
        int max(Fixed const &fixed) const;
        
};
Fixed ::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << this->_fractionalBits;
}

int Fixed::compareTo(Fixed const &fixed) const
{
    if (this->_fixedPointValue > fixed._fixedPointValue)
        return (1);
    else if (this->_fixedPointValue < fixed._fixedPointValue)
        return (-1);
    else
        return (0);
}
float Fixed::toFloat(void) const
{
    return ((float)this->_fixedPointValue / (1 << this->_fractionalBits));
}

int Fixed::add(Fixed const &fixed) const
{
    return (this->_fixedPointValue + fixed._fixedPointValue);
}
int Fixed::sub(Fixed const &fixed) const
{
    return (this->_fixedPointValue - fixed._fixedPointValue);
}
int Fixed::mul(Fixed const &fixed) const
{
    return (this->_fixedPointValue * fixed._fixedPointValue);
}
int Fixed::div(Fixed const &fixed) const
{
    return (this->_fixedPointValue / fixed._fixedPointValue);
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
 Fixed:: Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}
int Fixed::min(Fixed const &fixed) const
{
    if (this->_fixedPointValue > fixed._fixedPointValue)
        return (fixed._fixedPointValue);
    else
        return (this->_fixedPointValue);
}
int Fixed::max(Fixed const &fixed) const
{
    if (this->_fixedPointValue > fixed._fixedPointValue)
        return (this->_fixedPointValue);
    else
        return (fixed._fixedPointValue);
}
#include <iostream>

int main( void ) {
Fixed a;

Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


}
