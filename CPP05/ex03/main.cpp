/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:44 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 15:31:28 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {

	srand((unsigned int)time(NULL));

	Bureaucrat bureaucrat[1] = { 
									//Bureaucrat("Norminet", 46),
									Bureaucrat("Sophie", 1),
								};

	Intern	someRandomIntern;
	AForm	*aFreeForm;

	for (int i = 0; i < 1; i++) {

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << "---------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << std::endl << "		" << bureaucrat[i] << std::endl;
		std::cout << "--------------------------------------------------------" << std::endl;
		std::cout << "----------------------------------------" << std::endl;		
		std::cout << "---------------------------" << std::endl;
		std::cout << "---------------" << std::endl;
		std::cout << std::endl;

		try {

			std::cout << "---------SHRUBBERY CREATION FORM----------" << std::endl << std::endl;

			aFreeForm = someRandomIntern.makeForm("shrubbery creation", "MyLoveForBobRoss");
			std::cout << *aFreeForm << std::endl;
		
			bureaucrat[i].signForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;
			bureaucrat[i].executeForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;


			delete aFreeForm;
			std::cout << std::endl;
			std::cout << "---------ROBOTOMY REQUEST FORM----------" << std::endl << std::endl;
			
			aFreeForm = someRandomIntern.makeForm("robotomy request", "Bender");
			std::cout << *aFreeForm << std::endl;
		
			bureaucrat[i].signForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;
			bureaucrat[i].executeForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;
			
			delete aFreeForm;
			std::cout << std::endl;
			std::cout << "---------PRESIDENTIAL PARDON FORM----------" << std::endl << std::endl;
			
			aFreeForm = someRandomIntern.makeForm("presidential pardon", "Julian Assange");
			std::cout << *aFreeForm << std::endl;
		
			std::cout << std::endl;
			bureaucrat[i].signForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;
			bureaucrat[i].executeForm(*aFreeForm);
			std::cout << *aFreeForm << std::endl;
			
			delete aFreeForm;
			std::cout << std::endl;
			std::cout << "---------A BAD FORM----------" << std::endl << std::endl;
			
			aFreeForm = someRandomIntern.makeForm("hehehe im a bad form", "COTTON EYED JOE");
			std::cout << *aFreeForm << std::endl;
		
			delete aFreeForm;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;	
		}
	}

	return 0;
}