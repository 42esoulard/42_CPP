/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:24:04 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 17:24:52 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
#define A_HPP

#include <iostream>
#include "Base.hpp"

class A : public Base {
	
	public:
		A(void) {};
		A(A const &src) {};
		virtual ~A(void) {};

	private:
		A & operator=(A const &rhs) {};
};

#endif