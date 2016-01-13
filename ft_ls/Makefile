# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 20:43:29 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/13 16:35:45 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SOURCES =	srcs/affiche_file.c		\
			srcs/argv_to_tab.c		\
			srcs/calcs1.c			\
			srcs/check_options.c	\
			srcs/check_path.c		\
			srcs/checkargv.c		\
			srcs/couleurs.c			\
			srcs/dir_join.c			\
			srcs/files.c			\
			srcs/format.c			\
			srcs/free_dir.c			\
			srcs/ft_ls.c			\
			srcs/getdir.c			\
			srcs/getname.c			\
			srcs/getnb_out.c		\
			srcs/hide_dir.c			\
			srcs/initlen.c			\
			srcs/initoption.c		\
			srcs/ls_islong.c		\
			srcs/lstadd.c			\
			srcs/lstnew.c			\
			srcs/lstsort.c			\
			srcs/lstswap.c			\
			srcs/makedir.c			\
			srcs/mode.c				\
			srcs/previous.c			\
			srcs/printdir.c			\
			srcs/recup.c			\
			srcs/rajouts2.c			\
			srcs/recupmass.c		\
			srcs/sortparams.c		\

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
