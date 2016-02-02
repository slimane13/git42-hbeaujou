# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 20:43:29 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/31 19:27:55 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SOURCES =	srcs/add_fct.c	\
			srcs/add_fct_2.c	\
			srcs/add_header_to_bytes.c \
			srcs/check_file.c \
			srcs/check_params.c \
			srcs/convert_file.c \
			srcs/convert_to_bytecode.c \
			srcs/convert_to_bytecode_utils.c \
			srcs/convert_to_bytecode_utils2.c \
			srcs/cut_add_5.c \
			srcs/errors.c \
			srcs/ft_rajout.c \
			srcs/ft_rajout2.c \
			srcs/ft_rajout3.c \
			srcs/ft_rajout4.c \
			srcs/ft_rajout5.c \
			srcs/list_work.c \
			srcs/main.c \
			srcs/make_line.c \
			srcs/make_line_2.c \
			srcs/op.c \
			srcs/parsing.c \
			srcs/parsing_2.c \
			srcs/resolve_labels.c \
			srcs/write_line_to_bytecode.c \
			srcs/write_line_to_bytecode2.c \
			srcs/write_line_to_bytecode3.c \
			srcs/good_file_format.c \
			srcs/good_file_format2.c

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
