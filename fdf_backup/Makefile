# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <hbeaujou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/18 15:37:58 by hbeaujou          #+#    #+#              #
#    Updated: 2016/02/02 10:49:44 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -o fdf srcs/*.c libft.a -L./minilibx_macos -lmlx -I./minilibx_macos -framework OpenGL -framework AppKit

NAME_MINILIBX = mlx2_$(HOSTTYPE)
DIR_MINILIBIX = ...
CFLAGS += -I$(DIR_MINILIBIX)/include
LDFLAGS += -L/usr/X11/lib -lXext -lX11 -L$(DIR_MINILIBIX)/$(NAME_MINILIBX)
NAME = fdf
CC		= gcc
DIR_SRC	= srcs/
SRC		= $(DIR_SRC)test.c \

all: $(NAME)

$(NAME):
		$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all

.PHONY: fclean clean re
