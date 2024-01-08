/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:08:16 by rjobert           #+#    #+#             */
/*   Updated: 2024/01/08 20:26:59 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "phonebook.h"

class PhoneBook
{
private:
	Contact			contacts[8];
	unsigned int	count;
	unsigned int	index;
	
public:
	PhoneBook();
	void	Add();
	void	Search();
};

#endif
