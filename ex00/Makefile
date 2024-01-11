# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 14:09:50 by rjobert           #+#    #+#              #
#    Updated: 2024/01/10 18:34:16 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC := c++

SRC = megaphone.cpp
NAME = megaphone
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

