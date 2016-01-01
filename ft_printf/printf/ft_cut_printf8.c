/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:41:27 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entiertu3_short(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_short = (unsigned short)va_arg(liste,
				unsigned int);
		attrib_u_short(str, var, count);
	}
	else
	{
		var[count[2]]->u_short = (unsigned short)va_arg(liste,
				unsigned int);
		attrib_u_short(str, var, count);
	}
}

void	ft_cut_entiertu3_ul(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_long = va_arg(liste, unsigned long);
		attrib_u_maj(str, var, count);
	}
	else
	{
		var[count[2]]->u_long = va_arg(liste, unsigned long);
		attrib_u_maj(str, var, count);
	}
}

void	ft_cut_entiertu3_ull(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
		attrib_u_ll(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
		attrib_u_ll(str, var, count);
	}
}
