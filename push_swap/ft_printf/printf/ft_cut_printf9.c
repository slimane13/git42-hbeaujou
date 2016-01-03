/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 20:37:05 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entiertx3_n(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL2 == '*')
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

void	ft_cut_entiertx3_ull(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL3 == '*')
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

void	ft_cut_entiertx3_ul(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL3 == '*')
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

void	ft_cut_entiertx3_char(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL4 == '*')
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

void	ft_cut_entiertx3_short(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL3 == '*')
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
