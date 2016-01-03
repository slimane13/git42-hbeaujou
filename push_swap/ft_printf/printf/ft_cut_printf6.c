/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 20:36:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entiertd3_char(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->carac = (char)va_arg(liste, int);
		attrib_d_char(str, var, count);
	}
	else
	{
		var[count[2]]->carac = (char)va_arg(liste, int);
		attrib_d_char(str, var, count);
	}
}

void	ft_cut_entiertd3_vll(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL3 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->v_l_long = va_arg(liste, size_t);
		attrib_d_z(str, var, count);
	}
	else
	{
		var[count[2]]->v_l_long = va_arg(liste, size_t);
		attrib_d_z(str, var, count);
	}
}

void	ft_cut_entiertd3_maj(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL2 == '*')
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

void	ft_cut_entiertd3_j(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (CL3 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_d_j(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_d_j(str, var, count);
	}
}
