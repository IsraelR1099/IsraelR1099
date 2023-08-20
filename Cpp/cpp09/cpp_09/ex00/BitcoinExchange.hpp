/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:43:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/20 21:21:45 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cstdlib>
# include <exception>
# include <cstring>
# include <sstream>

//En los contenedores de c++ hay tres clases de contenedores: los asociativos,
//los secuenciales y los adaptadores. Los asociativos son aquellos que
//almacenan sus elementos de forma ordenada, y que permiten el acceso a los
//mismos a traves de una clave (std::map, std::set, std::multimap,
//std::multiset) (std::multiset y std::multimap, son similares a map y set,
// con la diferencia que aceptan repeticiones en sus inputs. Los secuenciales
//son aquellos que almacenan sus elementos de forma secuencial, como
//una array (std::vector, std::list, std::deque). Los adaptativos son aquellos
//que estan hechos para un uso especifico (std::stack, std::queue, std::priority_queue).

class	Date
{
	public:
		Date(void);
		Date(const std::string &input);
		Date(int year, int month, int day);
		Date(const Date &obj);
		Date	&operator=(const Date &obj);
		bool	operator!=(const Date &obj) const;
		bool	operator==(const Date &obj) const;
		~Date(void);

		class	BadFormat : public std::exception
		{
			public:
				BadFormat(const std::string &m_msg) : error(m_msg) {}
				virtual const char *what() const throw()
				{
					return (error.c_str());
				}
				~BadFormat() throw() {}
			private:
				std::string	error;
		};
		bool	validData(void);

		bool	operator<(const Date &obj) const;

	private:
		int	m_year;
		int	m_month;
		int	m_day;
		int	m_value;
};

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const char *input);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		~BitcoinExchange(void);

		void	addData(void);
		void	checkData(const char *input);
		void	addDataLine(std::string &line);
	private:
		std::multimap<Date, float>	m_map;
};
#endif
