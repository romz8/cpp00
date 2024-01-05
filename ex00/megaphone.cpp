/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:30:57 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/05 14:01:01 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string word = argv[i];
			for (size_t j = 0; j < word.length(); j++)
				word[j] = std::toupper(word[j]);
			std::cout << word;
		}
	}
	std::cout << std::endl;
	return (0);
}