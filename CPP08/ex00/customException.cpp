/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   customException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 14:48:42 by esoulard          #+#    #+#             */
/*   Updated: 2021/01/04 14:50:19 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "customException.hpp"

char const *customException::what() const throw() {

	return _err.c_str();
}