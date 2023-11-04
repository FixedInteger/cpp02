#include "Fixed.hpp"
Fixed ::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointValue = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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