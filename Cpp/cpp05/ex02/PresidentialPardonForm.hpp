/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 13:31:11 by irifarac          #+#    #+#             */
/*   Updated: 2023/07/07 12:26:48 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		void	execute(Bureaucrat const &executor) const;
		bool	checkRequirement(const Bureaucrat &executor) const;
	private:
		const std::string m_target;
};
#endif
