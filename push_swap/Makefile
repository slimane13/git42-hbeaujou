# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 20:43:29 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/09 15:39:41 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SOURCES =	srcs/fonctions_1.c	\
			srcs/fonctions_2.c	\
			srcs/fonctions_3.c	\
			srcs/ft_rajout.c	\
			srcs/pushswap.c	\


HEADERS	= -I./includes/

OBJECTS	= $(subst .c,.o,$(SOURCES))

WFLAGS	= -Wall -Werror -Wextra

CC		= gcc

.SILENT:

$(NAME): $(OBJECTS)
	make -C ./ft_printf
	$(CC) $(WFLAGS) -L./ft_printf/ -lftprintf $(OBJECTS) -o $(NAME)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

all: $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) $(HEADERS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@ "
	printf "\033[0m\n"

clean:
	make -C ./ft_printf clean
	rm -rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	make -C ./ft_printf fclean
	rm -rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

.PHONY: re fclean clean all
