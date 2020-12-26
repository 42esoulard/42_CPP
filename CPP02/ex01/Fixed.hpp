/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:08:27 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/14 20:28:18 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP 

#include <iostream>

class Fixed {
	
	public:
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const &src);
		Fixed(float const &src);
		~Fixed(void);

		Fixed & operator=(Fixed const &rhs);

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

		float 	toFloat(void) const;
		int		toInt(void) const;

	private:
		int 				_fixedPointValue;
		static int const	_bits;
		
};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

#endif