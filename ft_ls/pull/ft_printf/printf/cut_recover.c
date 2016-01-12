/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_recover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 20:00:04 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 20:27:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cut_recover_1(char *format, int tab[3], char *str, int var[3])
{
	if (format[var[0]] == '%' && format[var[0] + 1] == '%')
		cut_recover_2(tab, str, var);
	else if (format[var[0]] == '%' && format[var[0] + 1] == ' ' &&
			format[var[0] + 2] == '%')
		cut_recover_3(tab, str, var);
	else if ((format[var[0]] == '%' &&
				format[var[0] + 1] != '%') ||
			(format[var[0]] == '%' && g_tt[1] == 1))
		cut_recover_4(format, tab, str, var);
	else if (format[var[0]] != '%' && g_tt[1] == 1)
		cut_recover_5(format, str, var);
	else
		str[var[1]] = format[var[0]];
}

void	cut_recover_2(int tab[3], char *str, int var[3])
{
	if (var[0] != 0)
		g_tt[2]++;
	tab[g_tt[0]] = g_tt[2];
	tab[0]++;
	g_tt[1] = 1;
	g_tt[0]++;
	add_flag_zero(str, var);
}

void	cut_recover_3(int tab[3], char *str, int var[3])
{
	if (var[0] != 0)
		g_tt[2]++;
	tab[g_tt[0]] = g_tt[2];
	tab[0]++;
	g_tt[1] = 1;
	g_tt[0]++;
	add_flag_special(str, var);
}

void	cut_recover_4(char *format, int tab[3], char *str, int var[3])
{
	g_tt[2]++;
	tab[g_tt[0]] = g_tt[2];
	tab[0]++;
	g_tt[1] = 1;
	g_tt[0]++;
	var[2] = check_conver(format, var);
	choix_add_flag(format, str, var);
}

void	cut_recover_5(char *format, char *str, int var[3])
{
	g_tt[2]++;
	g_tt[1] = 0;
	str[var[1]] = format[var[0]];
}
