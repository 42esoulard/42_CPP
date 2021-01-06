/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:10 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 11:15:23 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) :
_name(name), _grade(grade) {

	std::cout << "Creating bureaucrat..." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Cannot create bureaucrat " + _name);
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Cannot create bureaucrat " + _name);
	std::cout << "[Bureaucrat] " << _name << " grade " << _grade << " created!" << std::endl;
};

Bureaucrat::Bureaucrat(void) {

	std::cout << "[Bureaucrat] Default void constructor called" << std::endl;
};


Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()) {

	std::cout << "[Bureaucrat] Copy constructor called" << std::endl;
	*this = src;
};

Bureaucrat::~Bureaucrat(void) {

	std::cout << "[Bureaucrat " << _name <<"] Destructor called" << std::endl;
};

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {

	std::cout << "[Bureaucrat] Assignation operator called" << std::endl;
	_grade = rhs.getGrade();
	return *this;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs) {

	return o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
};


std::string const 	&Bureaucrat::getName(void) const {

	return this->_name;
};

int 		 		Bureaucrat::getGrade(void) const {

	return this->_grade;
};

void				Bureaucrat::incrementGrade(void) {

	std::cout << "Attempting to increment grade..." << std::endl;
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException("Cannot increment " + _name + "'s grade");
	_grade--;
	std::cout << "Grade successfully incremented!" << std::endl;
};

void				Bureaucrat::decrementGrade(void) {

	std::cout << "Attempting to decrement grade..." << std::endl;
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException("Cannot decrement " + _name + "'s grade");
	_grade++;
	std::cout << "Grade successfully decremented!" << std::endl;
};

void		Bureaucrat::signForm(Form &form) const {

	std::cout << "Bureaucrat " << _name << " attempts to sign form "
	<< form.getName() << "..." << std::endl;

	form.beSigned(this);
	std::cout << _name << " signs " << form.getName() << std::endl;
};


void 		Bureaucrat::executeForm(Form const & form) {

	form.tryExec(*this);
	std::cout << _name << " executed " << form.getName() << std::endl;
};
