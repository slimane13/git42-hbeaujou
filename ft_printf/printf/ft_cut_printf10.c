/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:53:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entiertx3_majl(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
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

void	ft_cut_entiertx3_majull(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl3 == '*')
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

void	ft_cut_entiertx3_majul(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl3 == '*')
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

void	ft_cut_entiertx3_mchar(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl4 == '*')
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

void	ft_cut_entiertx3_mshort(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
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
