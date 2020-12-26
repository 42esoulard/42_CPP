/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:44:41 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/11 13:43:48 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

#include "Brain.hpp"

class Human {

	public:
		Human(void);
		~Human(void);

		const Brain	&getBrain(void) const;
		std::string identify(void) const;

	private:
		Brain _brain;	

};

#endif