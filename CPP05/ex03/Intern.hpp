/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:32:53 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 15:30:12 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
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

		AForm 	*makeForm(std::string const &formName, std::string const &target);

		class FormUnknownException : public customException {
			public:
				FormUnknownException(std::string const &str) : 
					customException("Intern couldn't create " + str + ": form unknown!") {};
		};

		AForm 	*shrubberyFactory(std::string const &target);
		AForm 	*robotomyFactory(std::string const &target);
		AForm 	*presidentialFactory(std::string const &target);

	private:
		typedef AForm* (Intern::*_formC)(std::string const &);
	
		_formC 		_formConstr[3] 	= 	{	
											&Intern::shrubberyFactory, 
											&Intern::robotomyFactory,
											&Intern::presidentialFactory
										};
		
		std::string	_formNames[3] 	= {"shrubbery creation", "robotomy request", "presidential pardon"};


};

#endif