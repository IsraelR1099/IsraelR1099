/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:53:42 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/21 18:17:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>
# include <cstring>

class	RPN
{
	public:
		RPN(void);
		RPN(const RPN &obj);
		RPN(std::stack<char> &init);
		RPN(const char *str);
		RPN	&operator=(const RPN &obj);
		~RPN(void);

		float	Calculate(const char *str);
		float	Operation(char c, float first, float second);
		float	getResult(void) const;
		class	BadFormat : public std::exception
		{
			public:
				BadFormat(const std::string &m_msg) : m_error(m_msg) {}
				virtual const char *what() const throw()
				{
					return (m_error.c_str());
				}
				~BadFormat(void) throw () {}
			private:
				std::string	m_error;
		};

	private:
		std::stack<char>	m_init;
		float				m_result;
};
#endif
