/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 12:48:44 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 14:30:13 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>	// pour iscntrl() a recoder
#include <stdarg.h>

int		run_ctrl(char *str)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

void	ft_printf(char *format ,...)
{
	va_list		liste;
	int			nbr_ctrl;
	int			i;
	int			j;
	int			size;

	size = 0;
	j = 0;
	i = 0;
	size = ft_strlen(format);
	size++;

	va_start(liste, format);
	nbr_ctrl = run_ctrl(format);
	while (i < nbr_ctrl)
	{
		ft_putchar((char)va_arg(liste, int));
		i++;
	}
	va_end(liste);
}

int		main(void)
{
	int i;
	char c;
	char c2;

	i = 21;
	c2 = 'F';
	ft_printf("c = %c\n c2 = %c\n", 'A', c2);
}
