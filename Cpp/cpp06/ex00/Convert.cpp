/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:08:03 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/03 13:46:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static bool	ft_checkChar(const char *str)
{
	int	tmp;

	tmp = std::stoi(str);
	if (tmp < 32 || tmp > 126)
		return (false);
	else if (tmp >= std::numeric_limits<char>::min()
			&& tmp <= std::numeric_limits<char>::max())
		return (false);
	return (true);
}

static bool	ft_checkInt(const char *str)
{
	long	tmp;

	tmp = std::stol(str);
	if (tmp >= std::numeric_limits<int>::min()
			&& tmp <= std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool	ft_checkFloat(const char *str)
{
	double	tmp;

	tmp = std::stod(str);
	if (tmp >= std::numeric_limits<float>::min()
			&& tmp <= std::numeric_limits<float>::max())
		return (false);
	return (true);
}

static bool	ft_checkDouble(const char *str)
{
	long double	tmp;

	tmp = std::stold(str);
	if (tmp >= std::numeric_limits<double>::min()
			&& tmp <= std::numeric_limits<double>::max())
		return (false);
	return (true);
}

static void	ft_errorCh(const char *str)
{
}

Convert::Convert(void) : m_ch(0), m_int(0), m_float(0.0), m_double(0.0f)
{
}

Convert::Convert(char **str)
{
	int		j;
/*	int		ch;
	float	f_value;
	double	d_value;*/

	if (!str || !str[0])
		throw ValueNotNumber("Enter a valid argument");
	j = 1;
	for (int i = 0; str[j][i]; i++)
	{
		if (std::isdigit(str[j][i]) == 0)
			throw ValueNotNumber("This value is not a number");
	}
	for (int i = 0; i < 256; i++)
		this->m_errorCh[i] = 0;
	if (ft_checkChar(str[1]))
		this->m_ch = static_cast<char>(std::stoi(str[1]));
	else
		ft_errorCh(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorInt[i] = 0;
	if (ft_checkInt(str[1]))
		this->m_int = std::stoi(str[1]);
	else
		ft_errorInt(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorFloat[i] = 0;
	if (ft_checkFloat(str[1]))
		this->m_float = std::stof(str[1]);
	else
		ft_errorFloat(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorDouble[i] = 0;
	if (ft_checkDouble(str[1]))
		this->m_double = std::stod(str[1]);
	else
		ft_errorDouble(str[1]);
/*	ch = std::stoi(str[1]);
	if (ch >= std::numeric_limits<char>::min() &&
			ch <= std::numeric_limits<char>::max())
		this->m_ch = static_cast<char>(ch);
	else
		this->m_ch = '\t';
	if (ch >= std::numeric_limits<int>::min() &&
			ch <= std::numeric_limits<int>::max())
		this->m_int = ch;
	else
		throw ValueNotNumber("Enter a valid argument");
	f_value = std::stof(str[1]);
	if (f_value >= std::numeric_limits<float>::min() &&
			f_value <= std::numeric_limits<float>::max())
		this->m_float = f_value;
	else
		throw ValueNotNumber("Enter a valid argument");
	d_value = std::stod(str[1]);
	if (d_value >= std::numeric_limits<double>::min() &&
			d_value <= std::numeric_limits<double>::max())
		this->m_double = d_value;
	else
		throw ValueNotNumber("Enter a valid argument");*/
}

Convert::~Convert(void)
{
}

Convert	&Convert::operator=(const Convert &obj)
{
	if (this == &obj)
		return (*this);
	return (*this);
}

void	Convert::ft_printCh(void) const
{
	if (this->m_errorCh[0])
		std::cout << m_errorCh << std::endl;
	else
		std::cout << "char: " << this->m_ch << std::endl;
}

void	Convert::ft_printInt(void) const
{
	if (this->m_errorInt[0])
		std::cout << m_errorInt << std::endl;
	else
		std::cout << "int: " << this->m_int << std::endl;
}

void	Convert::ft_printFloat(void) const
{
	std::cout << std::fixed << std::setprecision(1);
	if (this->m_errorFloat[0])
		std::cout << m_errorFloat << std::endl;
	else
		std::cout << "float: " << this->m_float << "f" << std::endl;
}

void	Convert::ft_printDouble(void) const
{
	std::cout << std::fixed << std::setprecision(1);
	if (this->m_errorDouble[0])
		std::cout << m_errorDouble << std::endl;
	else
		std::cout << "double: " << this->m_double << std::endl;
}
