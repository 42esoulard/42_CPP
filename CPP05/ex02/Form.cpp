/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 12:28:55 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include <iostream>

Form::Form(std::string const &name, int const &sGrade, int const eGrade, std::string const &target) :
_name(name), _signed(NO), _signGrade(sGrade), _execGrade(eGrade), _target(target) {

	std::cout << "Creating Form..." << std::endl;
	if (sGrade < 1 || eGrade < 1)
		throw Form::GradeTooHighException("Cannot create form " + _name);
	if (sGrade > 150 || eGrade > 150)
		throw Form::GradeTooLowException("Cannot create form " + _name);

	std::cout << "[Form] " << _name << " created!"  << std::endl;
};

Form::Form(void) : _name("template"), _signed(NO), _signGrade(1), _execGrade(1), _target("") {

	std::cout << "[Form] Default constructor called" << std::endl;
};

Form::Form(Form const &src) :
_name(src.getName()), _signed(NO), _signGrade(src.getSigningGrade()), _execGrade(src.getExecGrade()), _target(src.getTarget()) {

	std::cout << "[Form] Copy constructor called" << std::endl;
};

Form::~Form(void) {

	std::cout << "[Form] Destructor called" << std::endl;
};

Form & Form::operator=(Form const &rhs) {

	std::cout << "[Form] Assignation operator called" << std::endl;
	return *this;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs) {


	std::string sign = "no";

	if (rhs.getSignedStatus() == 1)
		sign = "yes";

	return o << "[Form " << rhs.getName() << " | Signing Grade: " << rhs.getSigningGrade() 
		<< " | Executing Grade: " << rhs.getExecGrade() << " | Signed : " << sign << "]" << std::endl;
};




std::string const 	&Form::getName(void) const {

	return this->_name;
};

std::string const 	&Form::getTarget(void) const {

	return this->_target;
};

int 				Form::getSignedStatus(void) const {

	return this->_signed;
};

int const			&Form::getSigningGrade(void) const {

	return this->_signGrade;
};

int const 			&Form::getExecGrade(void) const {

	return this->_execGrade;
};


void				Form::beSigned(Bureaucrat const *bureaucrat) {

	if (bureaucrat->getGrade() > _signGrade)
		throw Form::GradeTooLowException(bureaucrat->getName() + " couldn't sign " + _name);

	if (_signed == YES) 
		throw Form::AlreadySignedException(bureaucrat->getName() + " couldn't sign " + _name);
	
	_signed = YES;
};

void 		 Form::tryExec(Bureaucrat const &executor) const {

	if (_signed == NO) 
		throw Form::NotSignedException(executor.getName() + " couldn't execute " + _name);
	if (executor.getGrade() > _execGrade)
		throw Form::GradeTooLowException(executor.getName() + " couldn't execute " + _name);

	execute(executor);
};

