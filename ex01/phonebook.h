/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:20:04 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/09 16:14:19 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <iomanip>
# include <cctype>
# include <sstream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

void	format_display(std::string text);
void	display_line(int index, Contact contact);
bool    all_digit(const std::string str);

#endif