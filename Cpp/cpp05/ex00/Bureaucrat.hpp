/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:19:43 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/28 12:55:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &obj);

		std::string		getName(void);
		unsigned int	getGrade(void);
	private:
		const std::string	_name;
		unsigned int		_grade;
};
#endif
