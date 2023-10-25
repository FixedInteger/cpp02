#include  <iostream>

class Fixed
{
    private:
        int					_fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
        Fixed(){
            std::cout << "Default constructor called" << std::endl;
            this->_fixedPointValue = 0;
        };
        ~Fixed()
        {
            std::cout << "Destructor called" << std::endl;
        }
        Fixed(const Fixed &fixed);
        Fixed& operator=(const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

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

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;
    c = b;
    a = Fixed(1234);
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return (0);
}