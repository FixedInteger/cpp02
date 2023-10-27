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
        Fixed &operator++(void);
        Fixed operator++(int );
        Fixed &operator--(void);
        Fixed operator--(int );
        int operator<(const Fixed &fixed);
        int operator>(const Fixed &fixed);
        int operator<=(const Fixed &fixed);
        int operator>=(const Fixed &fixed);
        int operator==(const Fixed &fixed);
        int operator!=(const Fixed &fixed);
        static Fixed &max(Fixed &left, Fixed &right);
        static const Fixed &min(Fixed &left, Fixed &right);
        Fixed(const Fixed &fixed);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator=(const Fixed &fixed);
        Fixed &operator+(const Fixed &fixed);
        Fixed &operator-(const Fixed &fixed);
        Fixed &operator*(const Fixed &fixed);
        Fixed &operator/(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
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
    *this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    if (this != &fixed)
        this->_fixedPointValue = fixed.getRawBits();
    return (*this);
}
Fixed &Fixed::operator++(void)
{
    this->_fixedPointValue++;
    return (*this);
}
Fixed Fixed::operator++(int) 
{
    Fixed tmp(*this);
    _fixedPointValue++;
    return (tmp);
}
Fixed &Fixed::operator--(void)
{
    this->_fixedPointValue--;
    return (*this);
}
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _fixedPointValue--;
    return (tmp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
 int Fixed::operator>(const Fixed &fixed)
 {
     return (this->_fixedPointValue > fixed._fixedPointValue);
 }

int Fixed::operator<(const Fixed &fixed)
{
    return (this->_fixedPointValue < fixed._fixedPointValue);
}

int Fixed::operator>=(const Fixed &fixed)
{
    return (this->_fixedPointValue >= fixed._fixedPointValue);
}

int Fixed::operator<=(const Fixed &fixed)
{
    return (this->_fixedPointValue <= fixed._fixedPointValue);
}

int Fixed::operator==(const Fixed &fixed)
{
    return (this->_fixedPointValue == fixed._fixedPointValue);
}

int Fixed::operator!=(const Fixed &fixed)
{
    return (this->_fixedPointValue != fixed._fixedPointValue);
}
 
Fixed &Fixed::operator+(const Fixed &fixed)
{
    this->_fixedPointValue += fixed._fixedPointValue;
    return (*this);
}

Fixed &Fixed::operator-(const Fixed &fixed)
{
    this->_fixedPointValue -= fixed._fixedPointValue;
    return (*this);
}

Fixed &Fixed::operator*(const Fixed &fixed)
{
    this->_fixedPointValue *= fixed._fixedPointValue;
    return (*this);
}

Fixed &Fixed::operator/(const Fixed &fixed)
{
    this->_fixedPointValue /= fixed._fixedPointValue;
    return (*this);
}
Fixed &Fixed::max(Fixed &left, Fixed &right)
{
    if (left > right)
        return (left);
    else
        return (right);
}

const Fixed &Fixed::min(Fixed &left, Fixed &right)
{
    if (left < right)
        return (left);
    else
        return (right);
}


int main()
{
    Fixed a(213721);
    Fixed b(5);
    Fixed c(5);
    
    std::cout <<"max" << Fixed::max(b, c) << std::endl;
  
}