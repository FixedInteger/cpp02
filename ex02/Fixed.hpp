#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>
class Fixed 
{
	private:
		int					_fixedPointValue;
		const static int    _fractionalBits = 8;
	public:
		Fixed();
		~Fixed();
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
		static Fixed &max(Fixed &left, Fixed &right) ;
		static const Fixed &min(Fixed &left, Fixed &right)  ;
		static const Fixed &maxt(Fixed &left, Fixed &right) ;
		static const Fixed &mint(Fixed &left, Fixed &right) ;
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



#endif