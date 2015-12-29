#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aemebiku <aemebiku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/06/26 15:32:35 by aemebiku          #+#    #+#              #
#    Updated: 2015/12/29 16:16:18 by hbeaujou         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SOURCES =	libft/ft_memset.c				\
			libft/add_flag.c				\
			libft/attrib_conv_c.c			\
			libft/attrib_conv_p.c			\
			libft/attrib_conv_s.c			\
			libft/attrib_conv_d_short.c		\
			libft/attrib_conv_d2_short.c	\
			libft/attrib_conv_d_maj.c		\
			libft/attrib_conv_d2_maj.c		\
			libft/attrib_conv_u_maj.c		\
			libft/attrib_conv_u2_maj.c		\
			libft/attrib_conv_o_maj.c		\
			libft/attrib_conv_o2_maj.c		\
			libft/attrib_conv_u.c			\
			libft/attrib_conv_u2.c			\
			libft/attrib_conv_c_maj.c		\
			libft/attrib_conv_x_maj.c		\
			libft/attrib_conv_x2_maj.c		\
			libft/attrib_conv_x.c			\
			libft/attrib_conv_x2.c			\
			libft/attrib_conv_o.c			\
			libft/attrib_conv_o2.c			\
			libft/attrib_conv_d.c			\
			libft/attrib_conv_d2.c			\
			libft/attrib_conv.c				\
			libft/attrib_conv_2.c			\
			libft/attrib_conv_3.c			\
			libft/attrib_conv_4.c			\
			libft/attrib_conv_5.c			\
			libft/attrib_conv_6.c			\
			libft/attrib_conv_7.c			\
			libft/attrib_conv_8.c			\
			libft/ft_printf.c				\
			libft/recover_char.c			\
			libft/ft_bzero.c				\
			libft/ft_nbrlen.c				\
			libft/ft_memcpy.c				\
			libft/ft_memccpy.c				\
			libft/ft_memmove.c				\
			libft/ft_memchr.c				\
			libft/ft_memcmp.c				\
			libft/ft_strlen.c				\
			libft/ft_strdup.c				\
			libft/ft_strcpy.c				\
			libft/ft_strncpy.c				\
			libft/ft_strcat.c				\
			libft/ft_strncat.c				\
			libft/ft_strlcat.c				\
			libft/ft_strchr.c				\
			libft/ft_strrchr.c				\
			libft/ft_strstr.c				\
			libft/ft_strnstr.c				\
			libft/ft_strcmp.c				\
			libft/ft_strncmp.c				\
			libft/ft_atoi.c					\
			libft/ft_atoi_double.c			\
			libft/ft_atoi_ultra.c			\
			libft/ft_atoi_spec.c			\
			libft/ft_atoi_spec_o.c			\
			libft/ft_atoi_length.c			\
			libft/ft_ulltstr_base.c			\
			libft/ft_isalpha.c				\
			libft/ft_isalnum.c				\
			libft/ft_isascii.c				\
			libft/ft_isdigit.c				\
			libft/ft_isprint.c				\
			libft/ft_toupper.c				\
			libft/ft_tolower.c				\
			libft/ft_memdel.c				\
			libft/ft_strnew.c				\
			libft/ft_strdel.c				\
			libft/ft_strclr.c				\
			libft/ft_striter.c				\
			libft/ft_striteri.c				\
			libft/ft_strequ.c				\
			libft/ft_strnequ.c				\
			libft/ft_strsub.c				\
			libft/ft_strmap.c				\
			libft/ft_strmapi.c				\
			libft/ft_itoa.c					\
			libft/ft_itoa_base.c			\
			libft/ft_ntoa_base.c			\
			libft/ft_itoa_base_maj.c		\
			libft/ft_strsplit.c				\
			libft/ft_strsplit_esc.c			\
			libft/ft_strjoin.c				\
			libft/ft_charjoin.c				\
			libft/ft_strtrim.c				\
			libft/ft_putchar.c				\
			libft/ft_putstr.c				\
			libft/ft_putstr_spec.c			\
			libft/ft_putnbr.c				\


HEADERS	= -I/libft/includes/

OBJECTS	= $(subst .c,.o,$(SOURCES))

WFLAGS	= -g -Wall -Werror -Wextra

CC		= gcc

.SILENT:

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
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
	rm -rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

.PHONY: re fclean clean all
