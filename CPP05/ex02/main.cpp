/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:44 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:29:59 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {

	srand((unsigned int)time(NULL));

	Bureaucrat bureaucrat[2] = { 
									Bureaucrat("Norminet", 46),
									Bureaucrat("Sophie", 1),
								};

	for (int i = 0; i < 2; i++) {

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

			std::cout << "---------Shrubbery Creation Form----------" << std::endl << std::endl;

			ShrubberyCreationForm A612("MyLoveForBobRoss");
			std::cout << A612 << std::endl;
		
			bureaucrat[i].signForm(A612);
			std::cout << A612 << std::endl;
			bureaucrat[i].executeForm(A612);
			std::cout << A612 << std::endl;


			std::cout << std::endl;
			std::cout << "---------Robotomy Request Form----------" << std::endl << std::endl;
			
			RobotomyRequestForm B410("Bender");
			std::cout << B410 << std::endl;
		
			bureaucrat[i].signForm(B410);
			std::cout << B410 << std::endl;
			bureaucrat[i].executeForm(B410);
			std::cout << B410 << std::endl;
			

			std::cout << std::endl;
			std::cout << "---------Presidential Pardon Form----------" << std::endl << std::endl;
			
			PresidentialPardonForm PP01("Julian Assange");
			std::cout << PP01 << std::endl;
		
			std::cout << std::endl;
			bureaucrat[i].signForm(PP01);
			std::cout << PP01 << std::endl;
			bureaucrat[i].executeForm(PP01);
			std::cout << PP01 << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;	
		}
	}
		

	// std::cout << std::endl;
	// std::cout << "---------Sophie: tries to sign form twice----------" << std::endl;
	// try {
	// 	Bureaucrat Sophie("Sophie", 1);
	// 	std::cout << Sophie << std::endl;
	// 	Form A612("A612", 60, 20);
	// 	std::cout << A612 << std::endl;
	// 	Sophie.signForm(A612);
	// 	std::cout << A612 << std::endl;
	// 	Sophie.signForm(A612);
	// 	std::cout << A612 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	// std::cout << std::endl;
	// std::cout << "---------Zaz: Can't sign form (Zaz's grade > form signingGrade----------" << std::endl;
	// try {
	// 	Form VitB12("VitB12", 12, 12);
	// 	std::cout << VitB12 << std::endl;
	// 	Bureaucrat Zaz("Zaz", 150);
	// 	std::cout << Zaz << std::endl;
	// 	Zaz.signForm(VitB12);
	// 	std::cout << VitB12 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	// std::cout << std::endl;
	// std::cout << "---------Bad Form signingGrade----------" << std::endl;

	// try {
	// 	Form B413("B413", 0, 20);
	// 	std::cout << B413 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	// try {
	// 	Form B413("B413", 151, 20);
	// 	std::cout << B413 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	// std::cout << std::endl;
	// std::cout << "---------Bad Form execGrade----------" << std::endl;
	// try {
	// 	Form B413("B413", 50, 0);
	// 	std::cout << B413 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	// try {
	// 	Form B413("B413", 50, 151);
	// 	std::cout << B413 << std::endl;
	// }
	// catch (std::exception &e) {
	// 	std::cerr << e.what() << std::endl;	
	// }

	return 0;
}