/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:50:46 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/06 09:23:40 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "customException.hpp"

class Bureaucrat {
	
	public:

		Bureaucrat(std::string const &name, int const &grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const &rhs);

		std::string const 	&getName(void) const;
		int 		 		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

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