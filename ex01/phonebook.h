/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:20:04 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/11 13:08:56 by rjobert          ###   ########.fr       */
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

void		format_display(std::string text);
void		display_line(int index, Contact contact);
bool		all_digit(const std::string str);
std::string	readline_wrapper(std::string input);

#endif