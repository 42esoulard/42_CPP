/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:51:10 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/02 20:56:38 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) :
_name(name), _grade(grade) {

	std::cout << "Creating bureaucrat..." << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

int 		const 	&Bureaucrat::getGrade(void) const {

	return this->_grade;
};

void				Bureaucrat::incrementGrade(void) {

	std::cout << "Attempting to increment grade..." << std::endl;
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Grade successfully incremented!" << std::endl;
};

void				Bureaucrat::decrementGrade(void) {

	std::cout << "Attempting to decrement grade..." << std::endl;
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Grade successfully decremented!" << std::endl;
};

void		Bureaucrat::signForm(Form &form) const {

	std::cout << "Bureaucrat " << _name << " attempts to sign form "
	<< form.getName() << "..." << std::endl;

	if (_grade > form.getSigningGrade()) {
		
		throw Form::GradeTooLowException();
	}

	form.beSigned(this);
	std::cout << _name << " signs " << form.getName() << std::endl;
};


char const *Bureaucrat::GradeTooHighException::what() const throw() {

	return "Grade too high!";
};


char const *Bureaucrat::GradeTooLowException::what() const throw() {

	return "Grade too Low!";
};

