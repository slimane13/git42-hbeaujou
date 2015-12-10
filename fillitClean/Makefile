# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebouther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:24:09 by ebouther          #+#    #+#              #
#    Updated: 2015/12/10 18:30:00 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS += -Wall -Wextra -Werror
LIBFT = -L. -lft
SRCS = choix_boucle_1.c \
	choix_boucle_2.c \
	choix_boucle_3.c \
	error.c \
	fillit.c \
	fillit_define.c \
	ft_calc.c \
	ft_check_form_23.c \
	ft_check_form_23_2.c \
	ft_check_form_32.c \
	ft_check_form_32_2.c \
	ft_fct.c \
	ft_form.c \
	ft_infinite_final.c \
	ft_infinitef1_big.c \
	ft_infinitef1_special.c \
	ft_infinitef2_big.c \
	ft_infinitef3_big.c \
	ft_infinitef4_big.c \
	ft_infinitef5_big.c \
	ft_memalloc_int.c \
	ft_pos_23.c \
	ft_pos_32.c \
	ft_print.c \
	ft_put_try.c \
	ft_rajout.c \
	ft_strcpy_int.c \
	get_next_line_old.c \
	read.c \
	utils.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
