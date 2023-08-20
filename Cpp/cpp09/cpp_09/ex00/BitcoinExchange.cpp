/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:42:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/20 21:39:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//Utils functions

void	ft_checkTmp(char **tmp, char *estr, int number)
{
	int	i;

	i = 0;
	while (*tmp < estr && i < number && !strchr("-|", **tmp))
	{
		if (!std::isdigit(**tmp))
		{
			std::string	error(*tmp);
			throw Date::BadFormat("Bad input: " + error);
		}
		*tmp = *tmp + 1;
		i++;
	}
}

int	ft_numberlen(char *tmp, char *estr)
{
	int		len;
	char	*tmpStr;

	len = 0;
	tmpStr = tmp;
	while (tmpStr < estr && strchr("\n\t\r\v ", *tmpStr))
		tmpStr++;
	while (tmpStr < estr && !strchr("|-\t\r\v\n ", *tmpStr))
	{
		if (!std::isdigit(*tmpStr))
		{
			std::string	error(tmpStr);
			throw Date::BadFormat("Bad input: " + error);
		}

		len++;
		tmpStr++;
	}
	return (len);
}

bool	ft_isValidDate(std::string &line, char *argv[4], char *eargv[4])
{
	char	*tmp;
	char	*estr;
	size_t	pos;
	int		i;
	int		len;
	char	*ftoken;
	char	*eftoken;


	pos = line.find("|");
	if (pos == std::string::npos)
		throw Date::BadFormat("Bad input npos: " + line);
	tmp = strdup(line.c_str());
	estr = tmp + strlen(tmp);
	i = 0;
	len = 0;
	while (i < 4 && tmp < estr)
	{
		while (tmp < estr && strchr("\n\t\r\v ", *tmp))
			tmp++;
		ftoken = tmp;
		if (i == 0)
			ft_checkTmp(&tmp, estr, 4);
		else if (i == 1 || i == 2)
			ft_checkTmp(&tmp, estr, len);
		else
			ft_checkTmp(&tmp, estr, len);
		while (tmp < estr && strchr("\n\t\r\v ", *tmp))
			tmp++;
		if (!strchr("|-", *tmp))
		{
			std::string	error(tmp);
			throw Date::BadFormat("Bad input inside if: " + error);
		}
		eftoken = tmp;
		*eftoken = 0;
		argv[i] = ftoken;
		eargv[i] = eftoken;
		tmp++;
		len = ft_numberlen(tmp, estr);
		i++;
	}
	return (true);
}

//Date class implementation
Date::Date(void) : m_year(2023), m_month(01), m_day(01)
{
}


bool	Date::validData(void)
{
	if (this->m_year < 2009 || this->m_year > 2023)
		return (false);
	if (this->m_month < 1 || this->m_month > 12)
		return (false);
	if (this->m_day < 1 || this->m_day > 31)
		return (false);
	return (true);
}

Date::Date(const Date &obj) : m_year(obj.m_year), m_month(obj.m_month), m_day(obj.m_day)
{
}

Date::Date(int year, int month, int day) : m_year(year), m_month(month), m_day(day)
{
	if (!validData())
		throw BadFormat("Bad input");
}

Date::Date(const std::string &input)
{
	std::string		copy_input;
	std::string		yearString;
	std::string		monthString;
	std::string		dayString;
	std::string		valueString;
	char			*argv[4];
	char			*eargv[4];

	copy_input = input;
	if (ft_isValidDate(copy_input, argv, eargv))
	{
		yearString = argv[0];
		this->m_year = atoi(yearString.c_str());
		if (this->m_year < 2009 || this->m_year > 2017)
			throw Date::BadFormat("Not a valid year " + copy_input);
		monthString = argv[1];
		this->m_month = atoi(monthString.c_str());
		if (this->m_month < 1 || this->m_month > 12)
			throw Date::BadFormat("Not a valid month " + copy_input);
		dayString = argv[2];
		this->m_day = atoi(dayString.c_str());
		if (this->m_day < 1 || this->m_day > 31)
			throw Date::BadFormat("Not a valid day " + copy_input);
		valueString = argv[3];
		this->m_value = atoi(valueString.c_str());
		if (this->m_value < 0 || this->m_value > 1000)
			throw Date::BadFormat("Error: too large number or negative number");
		}
		else
			throw Date::BadFormat("Bad input: " + copy_input);
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

bool	Date::operator!=(const Date &obj) const
{
	return (!(*this == obj));
}

bool	Date::operator==(const Date &obj) const
{
	if (m_year == obj.m_year && m_month == obj.m_month && m_day == obj.m_day)
		return (true);
	return (false);
}

bool	Date::operator<(const Date &obj) const
{
	if (m_year < obj.m_year)
		return (true);
	else if (m_year == obj.m_year)
	{
		if (m_month < obj.m_month)
			return (true);
		else if (m_month == obj.m_month)
		{
			if (m_day < obj.m_day)
				return (true);
		}
	}
	return (false);
}

Date::~Date(void)
{
}
//BitcoinExchange class implementation
BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const char *input)
{
	Date	date;

	addData();
	checkData(input);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) : m_map(obj.m_map)
{
}

void	BitcoinExchange::addData(void)
{
	std::ifstream	data;
	std::string		line;

	data.open("data.csv");
	std::getline(data, line);
	while (std::getline(data, line))
	{
		try
		{
			addDataLine(line);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	data.close();
}

//m_map needs to override the operator < for the Date class
//The std::multimap requires that the elements you insert
//into it are ordered, which means it needs to know how to compare Date objects.
void	BitcoinExchange::addDataLine(std::string &line)
{
	size_t	pos;
	int		year;
	int		month;
	int		day;

	pos = line.find(",");
	std::string	date = line.substr(0, pos);
	std::string	value = line.substr(pos + 1);

	float valueFloat = std::atof(value.c_str());
	std::stringstream	stream(date);
	std::string			segment;

	if (std::getline(stream, segment, '-'))
		year = atoi(segment.c_str());
	if (std::getline(stream, segment, '-'))
		month = atoi(segment.c_str());
	if (std::getline(stream, segment))
		day = atoi(segment.c_str());
	Date dateObj(year, month, day);
	std::pair<Date, float> newData(dateObj, valueFloat);
	m_map.insert(newData);
}

void	BitcoinExchange::checkData(const char *input)
{
	std::ifstream	my_file(input);
	std::string		lineDate;
	size_t			pos;

	if (my_file.is_open())
	{
		getline(my_file, lineDate);
		while (getline(my_file, lineDate))
		{
			try
			{
				pos = lineDate.find(" | ");
				Date date(lineDate);
				std::map<Date, float>::iterator it = m_map.lower_bound(date);
				if (date != it->first)
				{
					if (it == m_map.begin())
						throw Date::BadFormat("No data available for this date");
					else
						it--;
				}
				std::string dateStr = lineDate.substr(0, pos);
				std::string valueStr = lineDate.substr(pos + 3);
				float value = atoi(valueStr.c_str());
				std::cout << dateStr << " -> " << value << " = " << value *
				it->second << std::endl;
			}
			catch (std::exception &e)

			{
				std::cout << e.what() << std::endl;
			}
		}
	}
	else
		throw Date::BadFormat("Bad file");
	my_file.close();
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
}
