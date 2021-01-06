/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:20 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 12:27:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "customException.hpp"

# define YES 	1
# define NO 	0

class Bureaucrat;

class Form {
	
	public:
		
		Form(std::string const &name, int const &sGrade, int const eGrade);
		Form(Form const &src);
		~Form(void);

		std::string const 	&getName(void) const;
		int 				getSignedStatus(void) const;
		int const			&getSigningGrade(void) const;
		int const 			&getExecGrade(void) const;

		void				beSigned(Bureaucrat const *bureaucrat);

		class GradeTooHighException : public customException {
			public:
				GradeTooHighException(std::string const &str) : 
					customException(str + ": grade is too high!") {};
		};

		class GradeTooLowException : public customException {
			public:
				GradeTooLowException(std::string const &str) : 
					customException(str + ": grade is too low!") {};
		};

		class AlreadySignedException : public customException {
			
			public:
				AlreadySignedException(std::string const &str) : 
					customException(str + ": it has already been signed") {};
		};	


	private:

		Form(void);
		Form & operator=(Form const &rhs);
		
		std::string const 	_name;
		int 				_signed;
		int const			_signGrade;
		int const 			_execGrade;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs);

#endif