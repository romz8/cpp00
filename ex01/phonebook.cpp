/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:50:29 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/08 21:33:05 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

std::string input_loader(void)
{
	std::string input;
	
	std::cout << "Choose your command : ADD, SEARCH, EXIT" << std::endl;
	std::cin >> input;
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
	input =  "starting";
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