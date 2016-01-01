/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 18:42:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_print_x1(t_var **var, char **str, int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_long = va_arg(liste, unsigned int);
			attrib_x(str, var, count);
		}
		else
		{
			var[count[2]]->u_long = va_arg(liste, unsigned int);
			attrib_x(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
			((str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
			str[count[0]][ft_strlen(str[count[0]]) - 3] == 'l') ||
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z' ||
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j'))
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste,
					unsigned long long);
			attrib_x_l(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste,
					unsigned long long);
			attrib_x_l(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_long = va_arg(liste,
					unsigned long);
			attrib_x(str, var, count);
		}
		else
		{
			var[count[2]]->u_long = va_arg(liste,
					unsigned long);
			attrib_x(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
			str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_carac = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_char(str, var, count);
		}
		else
		{
			var[count[2]]->u_carac = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_char(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_short(str, var, count);
		}
		else
		{
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_short(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_long = va_arg(liste, unsigned int);
			attrib_x_maj(str, var, count);
		}
		else
		{
			var[count[2]]->u_long = va_arg(liste, unsigned int);
			attrib_x_maj(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
			((str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
			str[count[0]][ft_strlen(str[count[0]]) - 3] == 'l') ||
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z' ||
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j'))
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste,
					unsigned long long);
			attrib_x_lmaj(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste,
					unsigned long long);
			attrib_x_lmaj(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_long = va_arg(liste,
					unsigned long);
			attrib_x_maj(str, var, count);
		}
		else
		{
			var[count[2]]->u_long = va_arg(liste,
					unsigned long);
			attrib_x_maj(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
			str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_carac = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_maj_char(str, var, count);
		}
		else
		{
			var[count[2]]->u_carac = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_maj_char(str, var, count);
		}
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
	{
		if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_short(str, var, count);
		}
		else
		{
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned long);
			attrib_x_maj_short(str, var, count);
		}
	}
}
