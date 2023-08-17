/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:42:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/17 17:46:56 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Utils functions

bool	ft_isValidDate(std::string &line)
{
	//if (line.length() != 10)
	//	return (false);
	if (line[4] != '-' || line[7] != '-')
		return (false);
	std::cout << "line es " << line << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(line[i]))
			return (false);
	}
	std::cout << "retorno true" << std::endl;
	return (true);
}

//Date class implementation
Date::Date(void) : m_year(2023), m_month(01), m_day(01)
{
}

Date::Date(const char *input)
{
	std::ifstream	my_file(input);
	std::string		lineDate;
	std::string		lineValue;
	std::string		yearString;
	std::string		monthString;
	std::string		dayString;
	size_t			pos;

	if (my_file.is_open())
	{
		getline(my_file, lineDate);
		while (getline(my_file, lineDate))
		{
			pos = lineDate.find("|");
			lineValue = lineDate.substr(pos + 1);
			if (ft_isValidDate(lineDate))
			{
				yearString = lineDate.substr(0, 4);
				this->m_year = atoi(yearString.c_str());
				monthString = lineDate.substr(5, 2);
				this->m_month = atoi(monthString.c_str());
				dayString = lineDate.substr(8, 2);
				this->m_day = atoi(dayString.c_str());
			}
			else
				std::cout << "Invalid date format" << std::endl;
		}
	}
	else
		std::cout << "Unable to open file" << std::endl;
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
