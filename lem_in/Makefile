# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <hbeaujou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 15:37:58 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/07 12:04:54 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem_in
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
DIR_INC	= includes/
DIR_SRC	= srcs/
SRC		= $(DIR_SRC)apply_line.c \
		  $(DIR_SRC)apply_map_adr.c \
		  $(DIR_SRC)calc_nbr.c \
		  $(DIR_SRC)check_file.c \
		  $(DIR_SRC)find_path.c \
		  $(DIR_SRC)find_path2.c \
		  $(DIR_SRC)is_valid.c \
		  $(DIR_SRC)lem_in.c \
		  $(DIR_SRC)list_work.c \

all: $(NAME)

$(NAME):
		make -C ./ft_printf
		$(CC) -L./ft_printf -lftprintf -o $(NAME) -I $(DIR_INC) $(SRC) $(CFLAGS)

clean:
		make clean -C ./ft_printf
		rm -rf $(OBJ)

fclean: clean
		make fclean -C ./ft_printf
		rm -rf $(NAME)

re:	fclean all

.PHONY: fclean clean re
