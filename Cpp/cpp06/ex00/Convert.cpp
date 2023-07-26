/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:08:03 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 13:46:21 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void) : m_ch(0), m_int(0), m_float(0.0), m_double(0.0f)
{
}

Convert::Convert(char **str)
{
	int		j;
	int		ch;

	if (!str)
		throw ValueNotNumber("Enter a valid argument");
	j = 1;
	for (int i = 0; str[j][i]; i++)
	{
		if (std::isdigit(str[j][i]) == 0)
			throw ValueNotNumber("This value is not a number");
	}
	ch = std::stoi(str[1]);
	if (ch >= std::numeric_limits<char>::min() &&
			ch <= std::numeric_limits<char>::max())
		this->m_ch = static_cast<char>(ch);
	else
		throw ValueNotNumber("Enter a valid argument");
	if (ch >= std::numeric_limits<int>::min() &&
			ch <= std::numeric_limits<int>::max())
		this->m_int = ch;
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

std::ostream	&operator<<(std::ostream &output, const Convert &obj)
{
	(void)obj;
	return (output);
}
