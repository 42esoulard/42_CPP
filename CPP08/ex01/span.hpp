/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:37:05 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/21 16:09:20 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <list>

class Span {

	public:

		Span(unsigned int const N);
		Span(Span const &src);
		~Span(void);

		Span & operator=(Span const &rhs);

		void 		addNumber(int const &nb);
		void 		addNumber(std::list<int>::iterator &ita, std::list<int>::iterator &itb);
		
		int const 	shortestSpan(void);
		int const 	longestSpan(void);

		std::list<int> const &getTab(void) const;

	private:

		Span(void);
		std::list<int> _tab;
		int _size;


};

std::ostream & operator<<(std::ostream &o, Span const &rhs);

#endif
