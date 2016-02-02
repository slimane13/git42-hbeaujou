# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 20:43:29 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/31 19:28:38 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SOURCES =	srcs/arithm.c \
			srcs/cpy_regs.c \
			srcs/eigth.c \
			srcs/fifth.c \
			srcs/first.c \
			srcs/forks_aff.c \
			srcs/fourth.c \
			srcs/live_zjmp.c \
			srcs/loads.c \
			srcs/logic.c \
			srcs/ninth.c \
			srcs/op.c \
			srcs/parsing.c \
			srcs/print_memory.c \
			srcs/second.c \
			srcs/seventh.c \
			srcs/sixth.c \
			srcs/stores.c \
			srcs/third.c \
			srcs/utils.c \

HEADERS	= -I./includes/

OBJECTS	= $(subst .c,.o,$(SOURCES))

WFLAGS	= -Wall -Werror -Wextra

CC		= gcc

.SILENT:

$(NAME): $(OBJECTS)
	make -C ../libft
	$(CC) $(WFLAGS) ../libft/libft.a $(OBJECTS) -o $(NAME)
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
	make clean -C ../libft
	rm -rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

.PHONY: re fclean clean all
