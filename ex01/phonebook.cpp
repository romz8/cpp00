/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:50:29 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/09 17:49:37 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string input_loader(void)
{
	std::string input;
	
	std::cout << "Choose your command : ADD, SEARCH, EXIT then press enter" << std::endl;
	std::cout << ">";
	std::getline(std::cin, input);
	if (input != "ADD" && input != "SEARCH" && input != "EXIT")
		std::cout << "invalid input, pls enter ADD, SEARCH or EXIT" << std::endl;
	return (input);
}

void	format_display(std::string text)
{
	int text_len;
	
	text_len = text.length();
	if (text_len > 10)
	{
		std::cout << text.substr(0, 9);
		std::cout << ".";
		return;
	}	
	std::cout << std::right << std::setw(10) << text;
	return ;
}
void	display_line(int index, Contact contact)
{
	format_display(std::to_string(index));
	std::cout << "|";
	contact.Display();
	std::cout << std::endl;
}

bool	all_digit(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0)
		{
			if (str[i] != '+' && !isdigit(str[i]))
				return(false);
		}
		else if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
void start_greeting(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\t" << "*******************************************" << std::endl;
	std::cout << "\t" <<  "** WELCOME TO THE PHONEBOOK OF THE 1980s **" << std::endl;
	std::cout << "\t" <<  "*******************************************" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	std::string input;
	PhoneBook phonebk;

	(void) argv[0];
	if (argc != 1)
	{
		std::cout << "this program takes no argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	start_greeting();
	input.clear();
	while (input != "EXIT")
	{
		input = input_loader();
		if (input == "ADD")
			phonebk.Add();
		else if (input == "SEARCH")
			phonebk.Search();
		else if (input == "EXIT")
			std::cout << "Erasing all contacts, Goodbye !" << std::endl;
		else
			std::cout << "Unknown command, try again" << std::endl;
	}
	exit(EXIT_SUCCESS);
}