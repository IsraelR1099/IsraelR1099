/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:03:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 11:48:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <typeinfo>
# include <limits>

class	Convert
{
	private:
		char	m_ch;
		int		m_int;
		float	m_float;
		double	m_double;
	public:
		Convert(void);
		Convert(char **str);
		Convert(const Convert &obj);
		~Convert(void);
		Convert	&operator=(const Convert &obj);

		class	ValueNotNumber : public std::invalid_argument
		{
			public:
				ValueNotNumber(const std::string msg) : std::invalid_argument(msg) {}
		};
};

std::ostream	&operator<<(std::ostream &output, const Convert &obj);
#endif
