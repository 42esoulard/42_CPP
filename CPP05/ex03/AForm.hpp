/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:20 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/05 15:18:35 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "customException.hpp"

# define YES 	1
# define NO 	0

class Bureaucrat;

class AForm {
	
	public:
		
		AForm(std::string const &name, int const &sGrade, int const eGrade, std::string const &target);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm & operator=(AForm const &rhs);


		std::string const 	&getName(void) const;
		int 				getSignedStatus(void) const;
		int const			&getSigningGrade(void) const;
		int const 			&getExecGrade(void) const;

		void				beSigned(Bureaucrat const *bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;
		void 		 tryExec(Bureaucrat const &executor) const;


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
					customException(str + ": form has already been signed!") {};
		};

		class NotSignedException : public customException {
			public:
				NotSignedException(std::string const &str) : 
					customException(str + ": form isn't signed!") {};
		};		




	protected:

		AForm(void);
		std::string const 	_name;
		int 				_signed;
		int const			_signGrade;
		int const 			_execGrade;
		std::string const	_target;
};

std::ostream & operator<<(std::ostream &o, AForm const &rhs);

#endif