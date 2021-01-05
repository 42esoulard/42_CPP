/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 12:02:54 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 15:17:47 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm {
	
	public:
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm(void);

		virtual void execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const &rhs);
		
};

#endif
