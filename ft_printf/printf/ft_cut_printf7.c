/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:39:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entiertd3_maj2(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl3 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->v_long = va_arg(liste, long);
		attrib_d_maj(str, var, count);
	}
	else
	{
		var[count[2]]->v_long = va_arg(liste, long);
		attrib_d_maj(str, var, count);
	}
}

void	ft_cut_entiertu3_uint(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
		attrib_u(str, var, count);
	}
	else
	{
		var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
		attrib_u(str, var, count);
	}
}

void	ft_cut_entiertu3_z(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl3 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, size_t);
		attrib_u_z(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, size_t);
		attrib_u_z(str, var, count);
	}
}

void	ft_cut_entiertu3_j(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl3 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_u_j(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_u_j(str, var, count);
	}
}

void	ft_cut_entiertu3_char(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_carac = (unsigned char)va_arg(liste,
				unsigned int);
		attrib_u_char(str, var, count);
	}
	else
	{
		var[count[2]]->u_carac = (unsigned char)va_arg(liste,
				unsigned int);
		attrib_u_char(str, var, count);
	}
}
