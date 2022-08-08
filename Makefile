# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mruiz-sa <mruiz-sa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 19:11:27 by mruiz-sa          #+#    #+#              #
#    Updated: 2022/08/08 12:13:10 by mruiz-sa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = ./srcs/check_and_convert_args.c \
		./srcs/ft_atoi.c \
		./srcs/set_philo_stats.c \
		./main.c
		

OBJECTS = $(SRC:.c=.o)

FLAGS = gcc -Wall -Werror -Wextra -g3

$(NAME): $(OBJECTS)
		@clear
		@$(FLAGS) -o $(NAME) $(OBJECTS)
		@echo "\n\033[92m"-------------\\n👌 COMPILED 👌\\n-------------\\n"\033[0m\n"

all: $(NAME)

clean: 
		@clear
		@echo "\n\033[31m"-------------------\\n💣 DELETED FILES 💣\\n-------------------\\n"\033[0m\n"
		@rm -f $(OBJECTS)

fclean: clean
		@rm -rf $(NAME)
		@rm -rf philo

re: fclean all

.PHONY: all clean re