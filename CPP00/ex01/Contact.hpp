/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoulard <esoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:55:56 by esoulard          #+#    #+#             */
/*   Updated: 2020/12/01 12:17:46 by esoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public:

	Contact(void);
	~Contact(void);

	void 				fillContact(void);

	void 				formatPhonebook(int i) const;
	void 				displayContact(int i) const;

	static void 		Add(Contact *phonebook);
	static void 		phonebookFull(Contact *phonebook);

	static void 		Search(Contact *phonebook);
	static void 		displayPhonebook(Contact *phonebook);

	static int 			getTotal(void);
	static int 			inputIndex(void);
	static std::string 	truncate(std::string str);

private:

	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _login;
	std::string _postal;
	std::string _email;
	std::string _phone;
	std::string _bday;
	std::string _favMeal;
	std::string _underwear;
	std::string _secret;

	static int	_total;
};

#endif
