/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:32:53 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 11:14:54 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "customException.hpp"

class Intern {
	
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		Form 	*makeForm(std::string const &formName, std::string const &target);

		class FormUnknownException : public customException {
			public:
				FormUnknownException(std::string const &str) : 
					customException("Intern couldn't create " + str + ": form unknown!") {};
		};

		Form 	*shrubberyFactory(std::string const &target);
		Form 	*robotomyFactory(std::string const &target);
		Form 	*presidentialFactory(std::string const &target);

	private:
		typedef Form* (Intern::*_formC)(std::string const &);
	
		_formC 		_formConstr[3] 	= 	{	
											&Intern::shrubberyFactory, 
											&Intern::robotomyFactory,
											&Intern::presidentialFactory
										};
		
		std::string	_formNames[3] 	= {"shrubbery creation", "robotomy request", "presidential pardon"};


};

#endif