#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>
#include <iomanip>
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
		Fixed(const Fixed &fixed);
		float toFloat(void) const;
		int toInt(void) const;
		Fixed& operator=(const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};
#endif  