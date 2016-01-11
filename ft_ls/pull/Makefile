CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_verrif_option.c \
	  ft_recup.c \
	  ft_lstnew_ls.c \
	  ft_lstadd_ls.c \
	  ft_lstswap.c \
	  ft_lstsort.c \
	  ft_ls_long_or_not.c \
	  ft_printdir.c \
	  ft_mode.c \
	  ft_initlen.c \
	  ft_strjoin_dir.c \
	  \
	  ft_getdir.c \
	  ft_getname.c \
	  ft_makeabsolute.c \
	  ft_makedir.c \
	  ft_maketab_of_argv.c \
	  ft_checkargv.c \
	  ft_previous.c \
	  ft_initoption.c \
	  ft_getnb_out.c \
	  ft_printfile.c \
	  ft_recup_long.c \
	  ft_putstr_chem.c \
	  ft_hide_dir.c \
	  ft_free_dir.c \
	  ft_format.c \
	  ft_sort_params_dir.c \
	  ft_nbfiles.c \
	  ft_putcolors.c \
	  \
	  main.c
OBJ = $(SRC:.c=.o)
LIB = -L libft/ -lft
LIB_HEADER = ./libft/includes/
NAME = ft_ls


all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(CFLAGS) -I ./includes/ -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean 
	gcc -g3 $(SRC) $(LIB) -o $(NAME)
