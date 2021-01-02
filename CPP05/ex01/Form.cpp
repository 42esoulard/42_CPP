/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/02 21:02:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>


Form::Form(std::string const &name, int const &sGrade, int const eGrade) :
_name(name), _signed(NO), _signGrade(sGrade), _execGrade(eGrade) {

	std::cout << "Creating form..." << std::endl;
	if (sGrade < 1 || eGrade < 1)
		throw Form::GradeTooHighException();
	if (sGrade > 150 || eGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "[Form] " << _name << " created! [Signing Grade: " << _signGrade 
	<< " | Executing Grade: " << _execGrade << "]" << std::endl;
};

Form::Form(void) : _name("template"), _signed(NO), _signGrade(1), _execGrade(1) {

	std::cout << "[Form] Default constructor called" << std::endl;
};

Form::Form(Form const &src) :
_name(src.getName()), _signed(NO), _signGrade(src.getSigningGrade()), _execGrade(src.getExecGrade()) {

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


	if (rhs.getSignedStatus() == 1)
		return o << "[Form " << rhs.getName() << " | Signing Grade: " << rhs.getSigningGrade() 
		<< " | Executing Grade: " << rhs.getExecGrade() << " | Signed : yes]" << std::endl;

	return o << "[Form " << rhs.getName() << " | Signing Grade: " << rhs.getSigningGrade() 
	<< " | Executing Grade: " << rhs.getExecGrade() << " | Signed : no]" << std::endl;
};




std::string const 	&Form::getName(void) const {

	return this->_name;
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

	if (_signed == YES) {
		std::string ret = bureaucrat->getName() + " cannot sign " + _name + " because it is already signed.";
		throw Form::AlreadySignedException(ret);
	}
	_signed = YES;
};




char const *Form::GradeTooHighException::what() const throw() {

	return "Grade too high!";
};


char const *Form::GradeTooLowException::what() const throw() {

	return "Grade too low!";
};


std::string const Form::AlreadySignedException::what(std::string const str) const throw() {

	// std::string const *ret = 

	return str;
};
