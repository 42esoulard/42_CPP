/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:50:27 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 17:24:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
#define B_HPP

#include <iostream>
#include "Base.hpp"

class B : public Base {
	
	public:
		B(void) {};
		B(B const &src) {};
		virtual ~B(void) {};

	private:
		B & operator=(B const &rhs) {};
};

#endif