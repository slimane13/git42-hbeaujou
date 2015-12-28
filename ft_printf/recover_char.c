/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:58:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 16:40:00 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conver(char *format, int var[3])
{
	int i;

	i = 1;
	while (i < 6 && (format[var[0] + i] == '.' || format[var[0] + i] == '-' ||
				format[var[0] + i] == '+' || format[var[0] + i] == ' ' ||
				format[var[0] + i] == '#' || ft_isdigit(format[var[0] + i]) ||
				format[var[0] + i] == 'j' || format[var[0] + i] == 'z' ||
				format[var[0] + i] == 'h' || format[var[0] + i] == 'l' ||
				format[var[0] + i] == '*'))
	{
		i++;
	}
	return (i);
}

void	choix_add_flag(char *format, char *str, int var[3])
{
	if (var[2] == 1)
		add_flag_one(format, str, var);
	else if (var[2] == 2)
		add_flag_two(format, str, var);
	else if (var[2] == 3)
		add_flag_three(format, str, var);
	else if (var[2] == 4)
		add_flag_four(format, str, var);
	else if (var[2] == 5)
		add_flag_five(format, str, var);
	else if (var[2] == 6)
		add_flag_six(format, str, var);
	else
	{
		ft_putstr("ERREUR");
		exit(0);
	}
}

void	recover_percent(char *format, char *str, int len, int *tab)
{
	int var[3];
	int indice;
	int flag;
	int k;

	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	indice = 1;
	tab[0] = 0;
	tab[1] = -1;
	tab[2] = -1;
	tab[3] = -1;
	flag = 0;
	if (format[0] == '%' && format[1] != '%')
		k = -1;
	else
		k = 0;
	while (var[0] < len)
	{
		if (format[var[0]] == '%' && format[var[0] + 1] == '%')
		{
			if (var[0] != 0)
				k++;
			tab[indice] = k;
			tab[0]++;
			flag = 1;
			indice++;
			add_flag_zero(str, var);
		}
		else if (format[var[0]] == '%' && format[var[0] + 1] == ' ' && format[var[0] + 2] == '%')
		{
			if (var[0] != 0)
				k++;
			tab[indice] = k;
			tab[0]++;
			flag = 1;
			indice++;
			add_flag_special(str, var);
		}
		else if ((format[var[0]] == '%' && format[var[0] + 1] != '%') || (format[var[0]] == '%' && flag == 1))
		{
			k++;
			tab[indice] = k;
			tab[0]++;
			flag = 1;
			indice++;
			var[2] = check_conver(format, var);
			choix_add_flag(format, str, var);
		}
		else if (format[var[0]] != '%' && flag == 1)
		{
			k++;
			flag = 0;
			str[var[1]] = format[var[0]];
		}
		else
			str[var[1]] = format[var[0]];
		var[0]++;
		var[1]++;
	}
	str[var[1]] = '\0';
//	printf("indice %d\nflag %d\ntab[0] %d\ntab[1] %d\ntab[2] %d\n", indice, flag, tab[0], tab[1], tab[2]);
}

int		is_indice(int nb, int *tab)
{
	int i;

	i = 0;
	while (i <= tab[0])
	{
		if (nb == tab[i])
			return (1);
		i++;
	}
	return (0);
}
