/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:16:28 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/07 13:50:44 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed	&operator=(const Fixed &copy);
		bool	operator>(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
		Fixed	&operator+(const Fixed &copy);
		Fixed	&operator-(const Fixed &copy);
		Fixed	&operator*(const Fixed &copy);
		Fixed	&operator/(const Fixed &copy);
	private:
		int					_fixedPoint;
		static int const	_fractBits = 8;
};

std::ostream	&operator<<(std::ostream &output, const Fixed &copy);
#endif
