/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:19:43 by irifarac          #+#    #+#             */
/*   Updated: 2023/06/29 20:56:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <stdexcept>

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
		void			incrementGrade(void);
		void			decrementGrade(void);

		class	GradeTooLowException : public std::out_of_range
		{
			public:
				GradeTooLowException(std::string const msg) :
				std::out_of_range(msg) {}
		};
		class	GradeTooHighException : public std::out_of_range
		{
			public:
				GradeTooHighException(std::string const msg) :
				std::out_of_range(msg) {}
		};
	private:
		const std::string	_name;
		unsigned int		_grade;
};
#endif
