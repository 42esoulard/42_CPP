/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:30:32 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 18:56:17 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Victim.hpp"

class Cat : public Victim {
	
	public:
		Cat(std::string const &name);
		Cat(Cat const &src);
		virtual ~Cat(void);

		Cat & 			operator=(Cat const &rhs);
		virtual void 	getPolymorphed(void) const;

	private:
		Cat(void);
		
};

#endif