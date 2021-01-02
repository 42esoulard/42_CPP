/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:44 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/02 17:46:53 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void) {

	std::cout << "---------James: a regular john----------" << std::endl;
	try {
		Bureaucrat James("James", 50);
		std::cout << James << std::endl;
		James.incrementGrade();
		std::cout << James << std::endl;
		James.incrementGrade();
		std::cout << James << std::endl;
		James.incrementGrade();
		std::cout << James << std::endl;
		James.decrementGrade();
		std::cout << James << std::endl;
		James.decrementGrade();
		std::cout << James << std::endl;
		James.decrementGrade();
		std::cout << James << std::endl;
		James.incrementGrade();
		std::cout << James << std::endl;
		James.decrementGrade();
		std::cout << James << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Sophie: Increment exception----------" << std::endl;
	try {
		Bureaucrat Sophie("Sophie", 1);
		std::cout << Sophie << std::endl;
		Sophie.incrementGrade();
		std::cout << Sophie << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Zaz: decrement exception----------" << std::endl;

	try {
		Bureaucrat Zaz("Zaz", 150);
		std::cout << Zaz << std::endl;
		Zaz.decrementGrade();
		std::cout << Zaz << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Instanciation: too high exception----------" << std::endl;
	try {
		Bureaucrat ImTooHigh("ImTooHigh", 0);
		std::cout << ImTooHigh << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	std::cout << std::endl;
	std::cout << "---------Instanciation: too low exception----------" << std::endl;
	try {
		Bureaucrat ImTooLow("ImTooLow", 151);
		std::cout << ImTooLow << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;	
	}

	return 0;
}