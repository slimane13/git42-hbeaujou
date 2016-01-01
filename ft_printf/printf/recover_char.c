/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:58:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 16:06:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conver(char *format, int var[3])
{
	int i;

	i = 1;
	while (i < 7 && (format[var[0] + i] == '.' || format[var[0] + i] == '-' ||
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
	else if (var[2] == 7)
		add_flag_seven(format, str, var);
	else
	{
		ft_putstr("ERREUR");
		exit(0);
	}
}

void	recover_percent(char *format, char *str, int len, int *tab)
{
	int var[3];

	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	g_tt[0] = 1;
	tab[0] = 0;
	tab[1] = -1;
	tab[2] = -1;
	tab[3] = -1;
	g_tt[1] = 0;
	if (format[0] == '%' && format[1] != '%')
		g_tt[2] = -1;
	else
		g_tt[2] = 0;
	while (var[0] < len)
	{
		cut_recover_1(format, tab, str, var);
		var[0]++;
		var[1]++;
	}
	str[var[1]] = '\0';
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
