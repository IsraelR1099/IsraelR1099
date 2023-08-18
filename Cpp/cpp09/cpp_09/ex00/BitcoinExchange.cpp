/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:42:45 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/18 12:12:40 by irifarac         ###   ########.fr       */
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
	//std::cout << "tmp string es : " << tmpStr << std::endl;
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
	//std::cout << "retorno len: " << len << std::endl;
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
		throw Date::BadFormat("Bad input: " + line);
	tmp = strdup(line.c_str());
	estr = tmp + strlen(tmp);
	i = 0;
	len = 0;
	while (i < 4)
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
		//std::cout << "tmp es: " << tmp << std::endl;
		//std::cout << "tmp es: " << *tmp << std::endl;
		if (*tmp != '|' || *tmp != '-')
		{
			std::cout << "tmp es: " << tmp << std::endl;
			std::cout << "tmp dentro es: #" << *tmp << "#" << std::endl;
			std::cout << "integer es : " << (int)*tmp << std::endl;
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

Date::Date(const char *input)
{
	std::ifstream	my_file(input);
	std::string		lineDate;
	std::string		yearString;
	std::string		monthString;
	std::string		dayString;
	char			*argv[4];
	char			*eargv[4];

	if (my_file.is_open())
	{
		getline(my_file, lineDate);
		while (getline(my_file, lineDate))
		{
			try
			{
				if (ft_isValidDate(lineDate, argv, eargv))
				{
					yearString = argv[0];
				//	std::cout << "year string es : " << yearString << std::endl;
					this->m_year = atoi(yearString.c_str());
					monthString = argv[1];
					this->m_month = atoi(monthString.c_str());
					dayString = argv[2];
					this->m_day = atoi(dayString.c_str());
				}
			else
				std::cout << "Invalid date format" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
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
