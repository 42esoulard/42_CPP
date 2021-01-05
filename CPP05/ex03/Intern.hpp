/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 12:32:53 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 13:59:13 by esoulard         ###   ########.fr       */
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


	private:
		typedef AForm* (Intern::*_formC)(std::string const &);
	
		_formC 	_formConstr[3] = 	{	&PresidentialPardonForm::PresidentialPardonForm, 
										&RobotomyRequestForm::RobotomyRequestForm,
										&ShrubberyCreationForm::ShrubberyCreationForm
									};
		
		std::string	_formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};


};

#endif