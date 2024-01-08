/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:46:48 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/08 16:35:51 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "phonebook.h"

class Contact
{
private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string	phonenumber;
	std::string	darkest_secret;

public:
	Contact();
	Contact(std::string firstname, std::string lastname, std::string nickname, 
	std::string	phonenumber, std::string darkest_secret);
	void	Display();
	void	Display_details();
};

#endif