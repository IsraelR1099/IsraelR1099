/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:03:06 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/04 12:51:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <typeinfo>
# include <limits>
# include <iomanip>
# include <cstdlib>
# include <cstring>

class	Convert
{
	private:
		char	m_ch;
		int		m_int;
		float	m_float;
		double	m_double;
		char	m_errorCh[256];
		char	m_errorInt[256];
		char	m_errorFloat[256];
		char	m_errorDouble[256];
	public:
		Convert(void);
		Convert(char **str);
		Convert(const Convert &obj);
		~Convert(void);
		Convert	&operator=(const Convert &obj);
		void	ft_errorCh(const char *str);
		void	ft_errorInt(const char *str);
		void	ft_errorFloat(const char *str);
		void	ft_errorDouble(const char *str);
		void	ft_printCh(void) const;
		void	ft_printInt(void) const;
		void	ft_printFloat(void) const;
		void	ft_printDouble(void) const;

		class	ValueNotNumber : public std::invalid_argument
		{
			public:
				ValueNotNumber(const std::string msg) : std::invalid_argument(msg) {}
		};
};

#endif
