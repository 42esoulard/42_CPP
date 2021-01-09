/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:22:37 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/09 13:45:59 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

#define T_CHAR 		0
#define T_INT 		1
#define T_FLOAT 	2
#define T_DOUBLE 	3

class Convert {
	
	public:
		Convert(std::string const &input);
		Convert(Convert const &src);
		~Convert(void);

		char const & getCharConv(void) const;
		int const & getIntConv(void) const;
		float const & getFloatConv(void) const;
		double const & getDoubleConv(void) const;

	private:
		Convert(void);
		Convert & operator=(Convert const &rhs);
		
		char 	_charConv;
		int 	_intConv;
		float 	_floatConv;
		double 	_doubleConv;
		int 	_type;

		int 	parseInput(std::string const &input) const;

		void	fromChar(std::string const &input);
		void	fromInt(std::string const &input);
		void	fromFloat(std::string const &input);
		void	fromDouble(std::string const &input);

		typedef void (Convert::*_convUtils)(std::string const &);
	
		_convUtils 	_makeConv[4] 	= 	{	
											&Convert::fromChar, 
											&Convert::fromInt,
											&Convert::fromFloat,
											&Convert::fromDouble,
										};

};

std::ostream & operator<<(std::ostream &o, Convert const &rhs);

#endif
