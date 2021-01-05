/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:50:46 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:47:43 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include "customException.hpp"

class AForm;

class Bureaucrat {
	
	public:

		Bureaucrat(std::string const &name, int const &grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const &rhs);

		std::string const 	&getName(void) const;
		int 		const 	&getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				signForm(AForm &form) const;
		void 				executeForm(AForm const & form);


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
		
	private:
		
		Bureaucrat(void);
		std::string const 	_name;
		int 				_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif