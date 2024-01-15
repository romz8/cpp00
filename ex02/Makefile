# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 13:28:58 by rjobert           #+#    #+#              #
#    Updated: 2024/01/15 13:34:27 by rjobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
NAME = GlobalBankster
HEADER = Account.hpp
SRC = tests.cpp Account.cpp
OBJS = $(SRC:.cpp=.o)
DEPS = $(SRC:.cpp=.d)
FLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -I ./
RM = rm -rf

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean	
	$(RM) $(NAME)

re: fclean all

.phony: re all clean fclean
