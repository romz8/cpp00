/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:04:26 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/11 13:27:24 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"
void		phone_header(void);
int			read_index(int total);
std::string trim_string(std::string str);
std::string	contact_input(std::string contact_type);
std::string number_input(void);
bool empty_or_spaces(const std::string& str);

PhoneBook::PhoneBook(void)
{
	this->count = 0;
	this->index = 0;	
}

/*
Add: This method allows adding a new contact to the PhoneBook.
It prompts for contact details (first name, last name, nickname, phone number, darkest secret),
and adds the new contact to the PhoneBook. It handles the rolling index functionality to maintain
a maximum of 8 contacts, replacing the oldest contact when the limit is reached.
*/
void	PhoneBook::Add(void)
{
	std::string contact_info[5];
	int	index;
	
	contact_info[0] = contact_input("firstname");
	contact_info[1] = contact_input("lastname");
	contact_info[2] = contact_input("nickname");
	contact_info[3] = number_input();
	contact_info[4] = contact_input("darkest secret");
	
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

/*
Search: This method displays the list of contacts and allows the user to select one for more details.
If no contacts are stored, it informs the user. Otherwise, it displays a list of contacts and prompts
for an index to view detailed information about the selected contact.
*/
void	PhoneBook::Search(void)
{
	int	total;
	int	index_s;
	
	total = this->count;
	if (total == 0)
	{
		std::cout << "No saved contact, please enter one" << std::endl;
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

/*
read_index: This function prompts the user to enter an index to look up a contact.
It performs validation to ensure the input is a valid index (within the range of stored contacts).
Returns the integer index if valid, or continues to prompt the user until a valid input is provided.
*/
int	read_index(int total)
{
	std::string input;
	int	index;

	index = -1;
	std::cout << "Enter index to lookup: " << std::endl;
	while (index > 7 || index < 0 || input.empty() || input.length() != 1)
	{
		input.erase();
		input = readline_wrapper(input);
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
	return (index);
}

/*
trim_string: This function removes leading and trailing whitespace from a string.
Utilizes standard string methods find_first_not_of and find_last_not_of for trimming.
Returns the trimmed string.
*/
std::string trim_string(const std::string str)
{
	size_t start;
	size_t end;
	std::string trimmed;

	start = str.find_first_not_of(" \t\n\r\f\v");
	end = str.find_last_not_of(" \t\n\r\f\v");
	trimmed = str.substr(start, end - start + 1);
	return(trimmed);
}

/*
contact_input: This function prompts the user for input regarding a specific contact detail.
It repeatedly prompts the user until a non-empty string is entered.
The input is then trimmed of leading and trailing whitespace and returned.
*/
std::string	contact_input(std::string contact_type)
{
	std::string input;

	std::cout << "please enter contact " << contact_type << std::endl;
	while(42)
	{
		input.clear();
		input = readline_wrapper(input);
		if (input.length() == 0 || input.empty())
			std::cout << contact_type << " cannot be empty, enter again:" << std::endl;
		else if ((empty_or_spaces(input)))
			std::cout << contact_type << " cannot be only space:" << std::endl;
		else
			break;
	}
	return (trim_string(input));
}

/*
same but check for phone number (digit only and first can be + for international phnenber)
*/
std::string number_input(void)
{
	std::string	input;
	
	std::cout << "please enter contact's phone number" << std::endl;
	while (42)
	{
		input.clear();
		input = readline_wrapper(input);
		if (input.empty() || input.length() == 0)
			std::cout  << "phone number cannot be empty, enter again:" << std::endl;
		else if ((empty_or_spaces(input)))
			std::cout << "phone number cannot be only space:" << std::endl;
		else if (input[0] != '+' && !isdigit(input[0]))
			std::cout  << "phone number can only start by a number or +" << std::endl;
		else if (!all_digit(input))
			std::cout  << "phone number can only be made of numbers" << std::endl;
		else
			break;
	}
	return (trim_string(input));
}

bool empty_or_spaces(const std::string& str)
{
    int n = str.length();
	if (n == 0)
		return (true);
	for (int i = 0; i < n; ++i)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}