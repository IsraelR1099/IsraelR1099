/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:42:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/16 13:46:26 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Date class implementation
Date::Date(void) : m_year(2023), m_month(01), m_day(01)
{
}

Date::Date(const char *input)
{
	std::ifstream	my_file(input);
	std::string		line;

	if (my_file.is_open())
	{
		getline(my_file, line);
		while (getline(my_file, line))
				std::cout << line << std::endl;
	}
	my_file.close();
}

Date::Date(const Date &obj) : m_year(obj.m_year), m_month(obj.m_month), m_day(obj.m_day)
{
}

Date	&Date::operator=(const Date &obj)
{
	if (this == &obj)
		return (*this);
	m_year = obj.m_year;
	m_month = obj.m_month;
	m_day = obj. m_day;
	return (*this);
}

Date::~Date(void)
{
}
//BitcoinExchange class implementation
/*BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : m_map(obj.m_map)
{
}

BitcoinExchange::BitcoinExchange(Date &validDate)
{
	(void)validDate;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this == &obj)
		return (*this);
	m_map = obj.m_map;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}*/
