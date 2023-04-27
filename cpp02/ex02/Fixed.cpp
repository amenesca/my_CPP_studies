#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : fpoint(0) {
  std::cout << "Default constructor called" << std::endl;  
}

Fixed::Fixed(int const fpoint_int) {
	this->fpoint = fpoint_int << this->frac_bits;
}

Fixed::Fixed(float const fpoint_float) {
	this->fpoint = roundf(fpoint_float * (1 << this->frac_bits));
}

Fixed::~Fixed(void) {
  std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(this->fpoint) / (1 << this->frac_bits));
}

int Fixed::toInt(void) const {
	return (static_cast<int>(this->fpoint) >> this->frac_bits);
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return(this->fpoint);
}

void Fixed::setRawBits(int const raw) {
  this->fpoint = raw;
}

Fixed& Fixed::operator=(Fixed const& fixed) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &fixed) {
    fpoint = fixed.getRawBits();
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed) {
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator>(Fixed const& fixed) const {
  if (this->fpoint > fixed.fpoint)
    return (true);
  else
    return (false);
}

bool Fixed::operator<(Fixed const& fixed) const {
  if (this->fpoint < fixed.fpoint)
    return (true);
  else
    return (false);
}

bool Fixed::operator>=(Fixed const& fixed) const {
  if (this->fpoint > fixed.fpoint || this->fpoint == fixed.fpoint)
    return (true);
  else
    return (false);
}

bool Fixed::operator<=(Fixed const& fixed) const {
  if (this->fpoint < fixed.fpoint || this->fpoint == fixed.fpoint)
    return (true);
  else
    return (false);
}

bool Fixed::operator==(Fixed const& fixed) const {
  if (this->fpoint == fixed.fpoint)
    return (true);
  else
    return (false);
}

bool Fixed::operator!=(Fixed const& fixed) const {
  if (this->fpoint != fixed.fpoint)
    return (true);
  else
    return (false);
}

Fixed Fixed::operator+(Fixed const& fixed) {
  Fixed plus;
  
  plus.setRawBits(this->getRawBits() + fixed.getRawBits());	
  return (plus);
}

Fixed Fixed::operator-(Fixed const& fixed) {
  Fixed minus;
  
  minus.setRawBits(this->getRawBits() - fixed.getRawBits());
  return (minus);
}

Fixed Fixed::operator*(Fixed const& fixed) {
	Fixed multi(static_cast<float>(this->getRawBits() * fixed.getRawBits()) / (1 << (2*frac_bits)));

	return (multi);
}

Fixed Fixed::operator/(Fixed const& fixed) {
	Fixed div;

	div.fpoint = (this->fpoint << frac_bits) / (fixed.fpoint << frac_bits);
	div.fpoint = (div.fpoint << frac_bits);
	return (div);
}