/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:22:59 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:17:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	
	public:
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm(void);

		virtual void execute(Bureaucrat const & executor) const;

	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
	
};

#endif