#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sksourou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/27 20:05:53 by sksourou          #+#    #+#              #
#    Updated: 2015/07/27 20:05:55 by sksourou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = FdF

SRCS = srcs/main.c srcs/tools.c srcs/draw.c srcs/hook.c srcs/bresenham.c

OBJS =		$(SRCS:.c=.o)

##INC_FILES =	-I includes/fdf.h \

INCLUDES =	-I libft/ \
		   		-I mini/ \
		   		-I includes/

LIBS =		-L libft/ -lft \
			-L mini/ -lmlx -framework OpenGL -framework AppKit

FLAGS =		-g -Wall -Wextra -Werror


$(NAME):	$(OBJS)
				@make -C libft/ fclean
				@make -C libft/
				@make -C mini/ clean
				@make -C mini/
				@echo "Create binary"
				@gcc -o $(NAME) $(OBJS) $(LIBS)
				@echo "Complitation ok"

$(OBJS): %.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

clean:
	rm -f	$(OBJS)

fclean: clean
	rm -f	$(NAME)

re: fclean all

.PHONY:	 all clean fclean re
