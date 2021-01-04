/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:44 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 09:43:49 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {

	std::cout << "---------James: a regular john signing a form----------" << std::endl;
	try {
		Bureaucrat James("James", 50);
		std::cout << James << std::endl;
		Form A612("A612", 60, 20);
		std::cout << A612 << std::endl;
		James.signForm(A612);
		std::cout << A612 << std::endl;

	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}
	

	std::cout << std::endl;
	std::cout << "---------Sophie: tries to sign form twice----------" << std::endl;
	try {
		Bureaucrat Sophie("Sophie", 1);
		std::cout << Sophie << std::endl;
		Form A612("A612", 60, 20);
		std::cout << A612 << std::endl;
		Sophie.signForm(A612);
		std::cout << A612 << std::endl;
		Sophie.signForm(A612);
		std::cout << A612 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Zaz: Can't sign form (Zaz's grade > form signingGrade----------" << std::endl;
	try {
		Form VitB12("VitB12", 12, 12);
		std::cout << VitB12 << std::endl;
		Bureaucrat Zaz("Zaz", 150);
		std::cout << Zaz << std::endl;
		Zaz.signForm(VitB12);
		std::cout << VitB12 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Bad Form signingGrade----------" << std::endl;

	try {
		Form B413("B413", 0, 20);
		std::cout << B413 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	try {
		Form B413("B413", 151, 20);
		std::cout << B413 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Bad Form execGrade----------" << std::endl;
	try {
		Form B413("B413", 50, 0);
		std::cout << B413 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	try {
		Form B413("B413", 50, 151);
		std::cout << B413 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	return 0;
}