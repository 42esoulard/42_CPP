/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:09:20 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/02 21:03:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

# define YES 	1
# define NO 	0

class Bureaucrat;

class Form {
	
	public:
		
		Form(std::string const &name, int const &sGrade, int const eGrade);
		Form(Form const &src);
		~Form(void);

		Form & operator=(Form const &rhs);

		std::string const 	&getName(void) const;
		int 				getSignedStatus(void) const;
		int const			&getSigningGrade(void) const;
		int const 			&getExecGrade(void) const;

		void				beSigned(Bureaucrat const *bureaucrat);

		class GradeTooHighException : public std::exception {
			
			public:
				virtual char const *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:
				virtual char const *what() const throw();
		};

		class AlreadySignedException {
			
			public:
				virtual std::string const what(std::string const str) const throw();
		};	


	private:

		Form(void);
		std::string const 	_name;
		int 				_signed;
		int const			_signGrade;
		int const 			_execGrade;
};

std::ostream & operator<<(std::ostream &o, Form const &rhs);

#endif