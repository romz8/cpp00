/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:04:26 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/08 21:32:57 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
void	phone_header(void);
int		read_index(int total);

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	this->index = 0;	
}
std::string	contact_input(std::string contact_type)
{
	std::string input;
	int	n;
	
	n = -1;
	std::cout << "please enter contact " << contact_type << std::endl;
	while(n < 0)
	{
		input.clear();
		std::getline(std::cin, input);
		if (input.length() == 0)
			std::cout << contact_type << " cannot be empty, enter again:" << std::endl;
		else
			n = 0;
	}
	return input;
}

/* CAREFUL EXPLAINATION HERE ABOUT INDEX ROLLING VS TOTAL FOR DISPLAY LIST*/
void	PhoneBook::Add(void)
{
	std::string contact_info[5];
	int	index;
	
	contact_info[0] = contact_input("firstname");
	contact_info[1] = contact_input("lastname");
	contact_info[2] = contact_input("nickname");
	contact_info[3] = contact_input("phonenumber");
	contact_info[4] = contact_input("darkest_secret");
	
	index = this->index;
	this->contacts[index] = Contact(contact_info[0], contact_info[1], contact_info[2], 
	contact_info[3], contact_info[4]);
	index++;
	if (this->count < 8)
		this->count = index;
	if (index > 7)
		index = 0;
	this->index = index;
}
void	PhoneBook::Search(void)
{
	int	total;
	int	index_s;
	
	total = this->count;
	if (total == 0)
	{
		std::cout << "No saved contact" << std::endl;
		return;
	}
	phone_header();
	for (int i = 0; i < total; i++)
		display_line(i, contacts[i]);
	index_s = read_index(total);
	contacts[index_s].Display_details();
}

void	phone_header(void)
{
	format_display("index");
	std::cout << "|";
	format_display("firstname");
	std::cout << "|";
	format_display("lastname");
	std::cout << "|";
	format_display("nickname");
	std::cout << std::endl;
}

int	read_index(int total)
{
	std::string input;
	int	index;

	index = -1;
	std::cout << "Enter index to lookup: " << std::endl;
	while (index > 7 || index < 0 || input.empty() || input.length() != 1)
	{
		input.erase();
		std::getline(std::cin, input);
		if (input.length() != 1 || !(input[0] >= '0' && input[0] <= '7'))
			std::cout << "incorrect index input try again" << std::endl;
		else
		{
			std::stringstream ss(input);
			ss >> index;
			ss.clear();
			if (index > 7 || index < 0 || index >= total)
			{
				std::cout << "incorrect index input try again" << std::endl;
				index = -1;
			}
			else 
				break;
		}
	}
	std::cout << "TEST index is " <<  index << std::endl;
	return (index);
}