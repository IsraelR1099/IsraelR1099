/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:40:53 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/23 09:21:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixedPoint = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

Fixed	&Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = copy.getRawBits();
	return (*this);
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = value << _fractBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPoint = roundf(value * (1 << _fractBits));
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedPoint / (1 << this->_fractBits));
}

int	Fixed::toInt(void) const
{
	return ((int)(roundf((float)this->_fixedPoint / (1 << this->_fractBits))));
}

std::ostream	&operator<<(std::ostream &output, const Fixed &copy)
{
	output << copy.toFloat();
	return (output);
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->_fixedPoint > copy._fixedPoint);
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->_fixedPoint >= copy._fixedPoint);
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->_fixedPoint < copy._fixedPoint);
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->_fixedPoint <= copy._fixedPoint);
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->_fixedPoint == copy._fixedPoint);
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->_fixedPoint != copy._fixedPoint);
}

Fixed	Fixed::operator+(const Fixed &copy) const
{
	return (this->toFloat() + copy.toFloat());
}

Fixed	Fixed::operator-(const Fixed &copy) const
{
	return (this->toFloat() - copy.toFloat());
}

Fixed	Fixed::operator*(const Fixed &copy) const
{
	return (this->toFloat() * copy.toFloat());
}

Fixed	Fixed::operator/(const Fixed &copy) const
{
	return (this->toFloat() / copy.toFloat());
}

Fixed	Fixed::operator++(void)
{
	++_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	const Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	--_fixedPoint;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	const Fixed	temp(*this);
	--(*this);
	return (temp);
}

Fixed	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (Fixed(f2));
	return (Fixed(f1));
}

Fixed	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (Fixed(f2));
	return (Fixed(f1));
}

Fixed	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 >= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}

Fixed	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 >= f2)
		return (Fixed(f1));
	return (Fixed(f2));
}
