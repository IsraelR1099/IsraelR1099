/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:19:43 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/26 10:11:06 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <stdexcept>

//Se crea las classes GradeTooLowException y GradeTooHighException dentro de la
//clase Bureaucrat debido a que el "scope" de esas excepciones son dentro de
//esta clase. Si usariamos esas excepciones en otras clases o de una forma mas
//global entonces, dichas clases, deberian estar fuera de la clase Bureaucrat.
//La clase Bureaucrat envia una excepcion, del tipo std::out_of_range, dependiendo
//si el grado es muy bajo o alto. Es responsabilidad del usuario manejar
//debidamente dichas excepciones.

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat(void);
		Bureaucrat	&operator=(const Bureaucrat &obj);

		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
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

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &obj);
#endif
