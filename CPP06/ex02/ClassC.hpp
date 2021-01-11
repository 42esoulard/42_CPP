/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassC.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:50:35 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 17:25:03 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
#define C_HPP

#include <iostream>
#include "Base.hpp"

class C : public Base {
	
	public:
		C(void) {};
		C(C const &src) {};
		virtual ~C(void) {};

	private:
		C & operator=(C const &rhs) {};
};

#endif