/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:35:01 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/19 09:54:02 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class	Intern
{
	private:
		typedef AForm	*(Intern::*action)(const std::string target);
		action			actions[3];
		AForm	*m_makeShrubbery(const std::string target);
		AForm	*m_makePresidential(const std::string target);
		AForm	*m_makeRobotomy(const std::string target);
	public:
		Intern(void);
		Intern(const Intern &obj);
		~Intern(void);
		Intern	&operator=(const Intern &obj);

		AForm	*makeForm(std::string frequest, std::string target);

		class	FormDoesNotExist : public std::invalid_argument
		{
			public:
				FormDoesNotExist(const std::string msg) :
					std::invalid_argument(msg) {}
		};
};

std::ostream	&operator<<(std::ostream &output, const Intern &obj);
#endif
