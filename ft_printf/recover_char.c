/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recover_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:58:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/13 16:51:17 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conver(char *format, int var[3])
{
	int i;

	i = 1;
	while (i < 5 && (format[var[0] + i] == '.' || format[var[0] + i] == '-' ||
				format[var[0] + i] == '+' || format[var[0] + i] == ' ' ||
				format[var[0] + i] == '#' || ft_isdigit(format[var[0] + i]) ||
				format[var[0] + i] == 'j' || format[var[0] + i] == 'z' ||
				format[var[0] + i] == 't' || format[var[0] + i] == 'h' ||
				format[var[0] + i] == 'l'))
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
	else
	{
		ft_putstr("ERREUR");
		exit(0);
	}
}

void	recover_percent(char *format, char *str, int len)
{
	int var[3];

	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	while (var[0] < len)
	{
		if (format[var[0]] == '%' && format[var[0] + 1] != '%')
		{
			var[2] = check_conver(format, var);
			choix_add_flag(format, str, var);
		}
		else
			str[var[1]] = format[var[0]];
		var[0]++;
		var[1]++;
	}
	str[var[1]] = '\0';
}
