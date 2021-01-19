/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:05 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/19 19:36:07 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

class Span {

	public:

		Span(unsigned int const N);
		Span(Span const &src);
		~Span(void);

		Span & operator=(Span const &rhs);

		void 		addNumber(int const &nb);
		int const 	&shortestSpan(void);
		int const 	&longestSpan(void);

		int const 	&getSize(void) const;
		int const 	&getCur(void) const;
		int const 	&getEntry(void) const;

	private:

		Span(void);
		int *_tab;
		int _size;
		int _cur;


};

// std::ostream & operator<<(std::ostream &o, Span const &rhs);

#endif
