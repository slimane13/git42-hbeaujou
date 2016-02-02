# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/01 20:43:29 by hbeaujou          #+#    #+#              #
#    Updated: 2016/01/31 19:47:01 by hbeaujou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM	=	./assembleur
COREWAR	=	./corewar
LIB	=	./libft/

MAKE	=	make -C

all: asm corewar libft

libft:
		$(MAKE) $(LIB)

asm: libft
		$(MAKE) $(ASM)

corewar: libft
		$(MAKE) $(COREWAR)

clean:
		$(MAKE) $(ASM) clean
		$(MAKE) $(COREWAR) clean
		$(MAKE)	$(LIB) clean

fclean:
		$(MAKE) $(ASM) fclean
		$(MAKE) $(COREWAR) fclean
		$(MAKE)	$(LIB) fclean

re:		fclean all

.PHONY:		libft re all fclean clean $(LIB) $(ASM) $(COREWAR)
