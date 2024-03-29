#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

  private:
	int fpoint;
    static const int frac_bits = 8;
  
  public:
    Fixed();
	Fixed(Fixed const& fixed);
    Fixed(int const fpoint_int);
    Fixed(float const fpoint_float);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator=(Fixed const& fixed);
};

std::ostream& operator<<(std::ostream& os, Fixed const &Fixed);

#endif
