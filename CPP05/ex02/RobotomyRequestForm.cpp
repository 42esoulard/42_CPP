/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:23:39 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:47:58 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) :
AForm("RRF", 72, 45, target) {

	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(void) {

	std::cout << "[RobotomyRequestForm] Default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {

	std::cout << "[RobotomyRequestForm] Copy constructor called" << std::endl;
	*this = src;
};

RobotomyRequestForm::~RobotomyRequestForm(void) {

	std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
};

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {

	std::cout << "[RobotomyRequestForm] Assignation operator called" << std::endl;
	return *this;
};

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	
	if (rand() % 2) {
		std::cout << "*brrrrrr...bRRRrRrRrrrRr..CCrcrccCRRbCzZZZZZZZZZZZZ*" << std::endl;
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << "Robotomy failed" << std::endl;
		std::cout << "*Sad beep boop*" << std::endl;
	}
};