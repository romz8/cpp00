/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:48:13 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/08 20:02:03 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

Contact::Contact(std::string f, std::string l, std::string n, std::string p, std::string d)
	: firstname(f), lastname(l), nickname(n), phonenumber(p), darkest_secret(d){}

Contact::Contact()
{
	
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->phonenumber = "";
	this->darkest_secret = "";
}

void	Contact::Display(void)
{
	format_display(this->firstname);
	std::cout << "|";
	format_display(this->lastname);
	std::cout << "|";
	format_display(this->nickname);
}

void	Contact::Display_details(void)
{
	std::cout << "===============================================" << std::endl;
	std::cout << "Firstname: " <<this->firstname << std::endl;
	std::cout << "Lastname: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone: " << this->phonenumber << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
	std::cout << "===============================================" << std::endl;
}


	