/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:08:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/14 19:49:29 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP 

#include <iostream>

class Fixed {
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

	private:
		int 				_fixedPointValue;
		static int const	_bits;
		
};

#endif