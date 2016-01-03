# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <hbeaujou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 15:37:58 by hbeaujou          #+#    #+#              #
#    Updated: 2015/08/26 18:46:39 by rfixot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
DIR_INC	= includes/
DIR_SRC	= srcs/
SRC		= $(DIR_SRC)bsq.c \
		  $(DIR_SRC)ft_process_file.c \
		  $(DIR_SRC)ft_write.c \
		  $(DIR_SRC)ft_process_std_input.c \
		  $(DIR_SRC)ft_funct_malloc.c \
		  $(DIR_SRC)ft_funct_malloc_stdin.c \
		  $(DIR_SRC)ft_checkerrors.c
OBJ		= bsq.o ft_funct_malloc.o ft_process_file.o ft_write.o \
		  ft_process_std_input.o ft_checkerrors.o ft_funct_malloc_stdin.o

all: $(NAME)

$(NAME):
		$(CC) -I $(DIR_INC) -c $(SRC) $(CFLAGS)
		$(CC) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all
