/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:50:29 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/09 18:46:40 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.h"

/*
input_loader: This function prompts the user to input a command and validates it.
It supports commands like ADD, SEARCH, and EXIT. If the user inputs an invalid
command, it displays an error message. The function returns the user's input.
*/
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

/*
format_display: This function is responsible for formatting and displaying text
in a specific way. If the text is longer than 10 characters, it truncates the text
and appends an ellipsis ('.'). Otherwise, it displays the text right-aligned within
a field of width 10 characters. This function is used to ensure consistent display
of text data.
*/
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

/*
display_line: This function takes an index and a Contact object as parameters.
It uses the format_display function to display the index and then calls the Display
method of the Contact object. This function is used to display a line of contact
information in a formatted manner.
*/
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

/*
all_digit: This function checks if a given string consists only of digits.
It allows a '+' symbol as the first character, making it suitable for phone
numbers validation. The function returns true if the string meets the criteria,
and false otherwise.
*/
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

/*
main: The main function of the program. It initializes the PhoneBook object
and handles the main application loop. It processes user input and executes
corresponding actions such as adding or searching contacts in the phonebook.
The program exits if the user inputs 'EXIT'.
*/
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