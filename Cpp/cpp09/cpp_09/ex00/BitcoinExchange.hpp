/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:43:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/16 13:17:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>

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
		Date(const Date &obj);
		Date(const char *input);
		Date	&operator=(const Date &obj);
		~Date(void);
	private:
		int	m_year;
		int	m_month;
		int	m_day;
};

/*class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(Date &validDate);
		BitcoinExchange(const BitcoinExchange &obj);
		BitcoinExchange	&operator=(const BitcoinExchange &obj);
		~BitcoinExchange(void);
	private:
		std::multimap<Date, std::string>	m_map;
};*/
#endif
