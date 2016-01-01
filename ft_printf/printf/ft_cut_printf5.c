/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:21:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:30:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entierto3_short(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_short = (unsigned short)va_arg(liste,
				unsigned int);
		attrib_o_short(str, var, count);
	}
	else
	{
		var[count[2]]->u_short = (unsigned short)va_arg(liste,
				unsigned int);
		attrib_o_short(str, var, count);
	}
}

void	ft_cut_entierto3_maj(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_long = va_arg(liste, unsigned long);
		attrib_o_maj(str, var, count);
	}
	else
	{
		var[count[2]]->u_long = va_arg(liste, unsigned long);
		attrib_o_maj(str, var, count);
	}
}

void	ft_cut_entiertd3_ll(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl4 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
		attrib_d_ll(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
		attrib_d_ll(str, var, count);
	}
}

void	ft_cut_entiertd3_short(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->v_short = (short)va_arg(liste, unsigned int);
		attrib_d_short(str, var, count);
	}
	else
	{
		var[count[2]]->v_short = (short)va_arg(liste, unsigned int);
		attrib_d_short(str, var, count);
	}
}

void	ft_cut_entiertd3_int(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->entier = va_arg(liste, int);
		attrib_d(str, var, count);
	}
	else
	{
		var[count[2]]->entier = va_arg(liste, int);
		attrib_d(str, var, count);
	}
}
