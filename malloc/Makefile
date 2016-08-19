# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/18 12:17:21 by hbeaujou          #+#    #+#              #
#    Updated: 2016/08/18 14:48:28 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)
endif

NAME= libft_malloc_$(HOSTTYPE).so
LS = libft_malloc.so

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = ft_malloc.c\
	  ft_free.c\
	  ft_realloc.c\
	  show_alloc_mem.c\

SRC += get_params.c\
	   get_malloc.c

SRC += ft_bzero.c\
	   ft_memcpy.c\
	   ft_memset.c\
	   ft_putaddress.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putnbr.c\

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

CC = clang
CFLAGS = -Wall -Werror -Wextra -fpic

AR = ar
ARFLAGS = -rc

HEAD = -I ./includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@printf 'Makelib [\033[32mDONE\033[0m]\n'
	@gcc -shared -o $(NAME) $^
	@printf 'Lien symbolique [\033[32mDONE\033[0m]\n'
	@ln -s $(NAME) $(LS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf obj
	@printf 'Clean [\033[32mDONE\033[0m]\n'

fclean: clean
	@rm -rf $(NAME) $(LS)
	@printf 'Fclean [\033[32mDONE\033[0m]\n'

re: fclean all

.PHONY: all clean fclean re
