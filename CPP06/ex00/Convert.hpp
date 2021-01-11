/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:22:37 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/11 15:42:51 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>

#define T_CHAR 		0
#define T_DOUBLE 	1
#define T_INVALID	2
#define T_NAN 		3


class Convert {
	
	public:
		Convert(std::string const &input);
		Convert(Convert const &src);
		~Convert(void);

		//---------GETTERS----------
		char const 		& getCharConv(void) const;
		int const 		& getIntConv(void) const;
		float const 	& getFloatConv(void) const;
		double const 	& getDoubleConv(void) const;
		int const 		& getType(void) const;

		std::string 	*getOutput(void) const;
		//---------------------------


	private:
		Convert(void);
		Convert & operator=(Convert const &rhs);
		
		char 		_charConv;
		int 		_intConv;
		float 		_floatConv;
		double 		_doubleConv;
		int 		_type;
		std::string *_output;

		//-------PARSING--------
		int 	_parseInput(std::string const &input);
		int 	_isZero(int idx) const;

		//-------CONVERSION------------
		void	fromChar(std::string const &input);
		void	fromDouble(std::string const &input);
		void	fromInvalid(std::string const &input);

		typedef void (Convert::*_convUtils)(std::string const &);
	
		_convUtils 	_makeConv[3] 	= 	{	
											&Convert::fromChar, 
											&Convert::fromDouble,
											&Convert::fromInvalid,
										};
};

std::ostream & operator<<(std::ostream &o, Convert const &rhs);

#endif
