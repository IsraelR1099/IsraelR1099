/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:08:03 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/06 20:27:03 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

static bool	ft_checkStr(char **str)
{
	int			j;
	int			counter;
	int			counterPoint;
	std::string tmp;

	j = 1;
	counter = 0;
	counterPoint = 0;
	tmp = str[1];
	if (tmp.empty())
		return (false);
	else if (tmp == "nan" || tmp == "nanf")
		return (true);
	else if (tmp == "inf" || tmp == "-inf")
		return (true);
	for (int i = 0; str[j][i]; i++)
	{
		if (std::isdigit(str[j][i]) == 0 && str[j][i] != '-' && str[j][i] != '.')
			return (false);
		if (str[j][i] == '-')
		{
			counter++;
			if (counter > 1 || i > 0)
				return (false);
		}
		if (str[j][i] == '.')
		{
			counterPoint++;
			if (counterPoint > 1)
				return (false);
		}
	}
	return (true);
}

static bool	ft_checkChar(const char *str)
{
	int			tmp;
	std::string tmpStr;

	//tmp = std::stoi(str);
	tmp = std::atoi(str);
	tmpStr = str;
	if (tmpStr == "nan" || tmpStr == "nanf")
		return (false);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		return (false);
	else if (tmp < 32 || tmp > 126)
		return (false);
	else if (tmp <= std::numeric_limits<char>::min()
			|| tmp >= std::numeric_limits<char>::max())
		return (false);
	return (true);
}

static bool	ft_checkInt(const char *str)
{
	long		tmp;
	std::string tmpStr;

	//tmp = std::stol(str);
	tmp = std::atoll(str);
	tmpStr = str;
	if (tmpStr == "nan" || tmpStr == "nanf")
		return (false);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		return (false);
	else if (tmp <= std::numeric_limits<int>::min()
			|| tmp >= std::numeric_limits<int>::max())
		return (false);
	return (true);
}

static bool	ft_checkFloat(const char *str)
{
	double		tmp;
	std::string tmpStr;
	char		*endPtr;

//	tmp = std::stod(str);
	tmp = std::strtod(str, &endPtr);
	tmpStr = str;
	if (endPtr == str || *endPtr != '\0')
		return (false);
	if (tmp <= std::numeric_limits<float>::min()
			|| tmp >= std::numeric_limits<float>::max())
		return (false);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		return (false);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		return (false);
	return (true);
}

static bool	ft_checkDouble(const char *str)
{
	long double	tmp;
	char		*endPtr;
	std::string tmpStr;

	//tmp = std::stold(str);
	tmp = std::strtold(str, &endPtr);
	tmpStr = str;
	if (endPtr == str || *endPtr != '\0')
		return (false);
	if (tmp <= std::numeric_limits<double>::min()
			|| tmp >= std::numeric_limits<double>::max())
		return (false);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		return (false);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		return (false);
	return (true);
}

void	Convert::ft_errorCh(const char *str)
{
	int			tmp;
	std::string	tmpStr;

	tmp = std::atoi(str);
	tmpStr = str;
	if (tmp < 32 || tmp > 126)
		strncpy(this->m_errorCh, "char: impossible", 17);
	else if (tmp <= std::numeric_limits<char>::min()
			|| tmp >= std::numeric_limits<char>::max())
		strncpy(this->m_errorCh, "char: overflow or underflow\n", 29);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		strncpy(this->m_errorCh, "char: impossible", 17);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		strncpy(this->m_errorCh, "char: impossible", 17);
}

void	Convert::ft_errorInt(const char *str)
{
	long		tmp;
	std::string	tmpStr;

	tmp = std::atol(str);
	tmpStr = str;
	if (tmp <= std::numeric_limits<int>::min()
			|| tmp >= std::numeric_limits<int>::max())
		strncpy(this->m_errorInt, "int: impossible", 16);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		strncpy(this->m_errorInt, "int: impossible", 17);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		strncpy(this->m_errorInt, "int: impossible", 17);
}

void	Convert::ft_errorFloat(const char *str)
{
	double		tmp;
	char		*endPtr;
	std::string	tmpStr;

	tmp = std::strtod(str, &endPtr);
	tmpStr = str;
	if (tmp <= std::numeric_limits<float>::min()
			|| tmp >= std::numeric_limits<float>::max())
		strncpy(this->m_errorFloat, "impossible", 11);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		strncpy(this->m_errorFloat, "nanf", 5);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		strncpy(this->m_errorFloat, "inf", 4);
}

void	Convert::ft_errorDouble(const char *str)
{
	long double	tmp;
	char		*endPtr;
	std::string	tmpStr;

	tmp = std::strtold(str, &endPtr);
	tmpStr = str;
	if (tmp <= std::numeric_limits<double>::min()
			|| tmp >= std::numeric_limits<double>::max())
		strncpy(this->m_errorDouble, "impossible", 11);
	else if (tmpStr == "nan" || tmpStr == "nanf")
		strncpy(this->m_errorDouble, "nan", 4);
	else if (tmpStr == "inf" || tmpStr == "-inf")
		strncpy(this->m_errorDouble, "inf", 4);
}

Convert::Convert(void) : m_ch(0), m_int(0), m_float(0.0), m_double(0.0f)
{
}

Convert::Convert(char **str)
{
	int			ch;
	long		tmpInt;
	double		tmpFloat;
	long double	tmpDouble;
	char		*endPtrFloat;
	char		*endPtrDouble;

	if (!str || !str[1])
		throw ValueNotNumber("Enter a valid argument");
	if (ft_checkStr(str) == false)
		throw ValueNotNumber("Enter a valid argument");
	for (int i = 0; i < 256; i++)
		this->m_errorCh[i] = 0;
	if (ft_checkChar(str[1]))
	{
		ch = std::atoi(str[1]);
		this->m_ch = static_cast<char>(ch);
	}
	else
		ft_errorCh(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorInt[i] = 0;
	if (ft_checkInt(str[1]))
	{
		tmpInt = std::atol(str[1]);
		this->m_int = tmpInt;
	}
	else
		ft_errorInt(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorFloat[i] = 0;
	if (ft_checkFloat(str[1]))
	{
		tmpFloat = std::strtod(str[1], &endPtrFloat);
		this->m_float = tmpFloat;
	}
	else
		ft_errorFloat(str[1]);
	for (int i = 0; i < 256; i++)
		this->m_errorDouble[i] = 0;
	if (ft_checkDouble(str[1]))
	{
		tmpDouble = std::strtold(str[1], &endPtrDouble);
		this->m_double = tmpDouble;
	}
	else
		ft_errorDouble(str[1]);
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
		std::cout << "float: " << m_errorFloat << std::endl;
	else
		std::cout << "float: " << this->m_float << "f" << std::endl;
}

void	Convert::ft_printDouble(void) const
{
	std::cout << std::fixed << std::setprecision(1);
	if (this->m_errorDouble[0])
		std::cout << "double: " << m_errorDouble << std::endl;
	else
		std::cout << "double: " << this->m_double << std::endl;
}
