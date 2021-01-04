/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:47:24 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string const &name, int const &sGrade, int const eGrade, std::string const &target) :
_name(name), _signed(NO), _signGrade(sGrade), _execGrade(eGrade), _target(target) {

	std::cout << "Creating Aform..." << std::endl;
	if (sGrade < 1 || eGrade < 1)
		throw AForm::GradeTooHighException("Cannot create form " + _name);
	if (sGrade > 150 || eGrade > 150)
		throw AForm::GradeTooLowException("Cannot create form " + _name);

	std::cout << "[AForm] " << _name << " created!"  << std::endl;
};

AForm::AForm(void) : _name("template"), _signed(NO), _signGrade(1), _execGrade(1) {

	std::cout << "[AForm] Default constructor called" << std::endl;
};

AForm::AForm(AForm const &src) :
_name(src.getName()), _signed(NO), _signGrade(src.getSigningGrade()), _execGrade(src.getExecGrade()) {

	std::cout << "[AForm] Copy constructor called" << std::endl;
};

AForm::~AForm(void) {

	std::cout << "[AForm] Destructor called" << std::endl;
};

AForm & AForm::operator=(AForm const &rhs) {

	std::cout << "[AForm] Assignation operator called" << std::endl;
	return *this;
};

std::ostream & operator<<(std::ostream &o, AForm const &rhs) {


	std::string sign = "no";

	if (rhs.getSignedStatus() == 1)
		sign = "yes";

	return o << "[AForm " << rhs.getName() << " | Signing Grade: " << rhs.getSigningGrade() 
		<< " | Executing Grade: " << rhs.getExecGrade() << " | Signed : " << sign << "]" << std::endl;
};




std::string const 	&AForm::getName(void) const {

	return this->_name;
};

int 				AForm::getSignedStatus(void) const {

	return this->_signed;
};

int const			&AForm::getSigningGrade(void) const {

	return this->_signGrade;
};

int const 			&AForm::getExecGrade(void) const {

	return this->_execGrade;
};


void				AForm::beSigned(Bureaucrat const *bureaucrat) {

	if (bureaucrat->getGrade() > _signGrade)
		throw AForm::GradeTooLowException(bureaucrat->getName() + " couldn't sign " + _name);

	if (_signed == YES) 
		throw AForm::AlreadySignedException(bureaucrat->getName() + " couldn't sign " + _name);
	
	_signed = YES;
};

void 		 AForm::tryExec(Bureaucrat const &executor) const {

	if (_signed == NO) 
		throw AForm::NotSignedException(executor.getName() + " couldn't execute " + _name);
	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException(executor.getName() + " couldn't execute " + _name);

	execute(executor);
};

