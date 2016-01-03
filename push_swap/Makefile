# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <hbeaujou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 15:37:58 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/03 16:16:10 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
DIR_INC	= includes/
DIR_SRC	= srcs/
SRC		= $(DIR_SRC)fonctions_1.c \
		  $(DIR_SRC)fonctions_2.c \
		  $(DIR_SRC)fonctions_3.c \
		  $(DIR_SRC)ft_rajout.c \
		  $(DIR_SRC)pushswap.c \

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
