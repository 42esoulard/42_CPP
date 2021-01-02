/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:50:46 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/02 17:52:40 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

		class GradeTooHighException : public std::exception {
			
			public:
				virtual char const *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			
			public:
				virtual char const *what() const throw();
		};

	private:
		
		Bureaucrat(void);
		std::string const 	_name;
		int 				_grade;
};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif