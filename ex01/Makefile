# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 16:48:54 by rjobert           #+#    #+#              #
#    Updated: 2024/01/08 16:50:15 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := g++

SRC = phonebook.cpp Contact.class.cpp PhoneBook.class.cpp
NAME = phonebook
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -MMD -I ./

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.phony: clean re all fclean