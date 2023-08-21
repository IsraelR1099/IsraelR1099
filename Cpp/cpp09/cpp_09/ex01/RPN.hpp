/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:53:42 by irifarac          #+#    #+#             */
/*   Updated: 2023/08/21 13:45:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>

class	RPN
{
	public:
		RPN(void);
		RPN(const RPN &obj);
		RPN(std::stack<char> &init);
		RPN(const char *str);
		RPN	&operator=(const RPN &obj);
		~RPN(void);

		int	Calculate(const char *str) const;
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
		int					m_result;
};
#endif
