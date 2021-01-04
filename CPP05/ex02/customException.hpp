/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:43:04 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 14:49:45 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOMEXCEPTION_HPP
#define CUSTOMEXCEPTION_HPP

#include <string>

class customException : public std::exception {
			
	public:
		customException(std::string const &str) : _err(str) {};
		virtual char const *what() const throw();

	protected:
		std::string const _err;	
};

#endif