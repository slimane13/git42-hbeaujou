/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 20:36:33 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_entierto_o(char **str, t_var **var, int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->entier = va_arg(liste, int);
		attrib_o(str, var, count);
	}
	else
	{
		var[count[2]]->entier = va_arg(liste, int);
		attrib_o(str, var, count);
	}
}

void	ft_cut_entierto3_ll(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, size_t);
		attrib_o_z(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, size_t);
		attrib_o_z(str, var, count);
	}
}

void	ft_cut_entierto3_ull(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_o_j(str, var, count);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
		attrib_o_j(str, var, count);
	}
}

void	ft_cut_entierto3_char(char **str, t_var **var,
		int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_carac = (unsigned char)va_arg(liste,
				unsigned int);
		attrib_o_char(str, var, count);
	}
	else
	{
		var[count[2]]->u_carac = (unsigned char)va_arg(liste,
				unsigned int);
		attrib_o_char(str, var, count);
	}
}

void	ft_cut_print_o1(t_var **var, char **str, int count[3], va_list liste)
{
	if (str[count[0]][0] == 'o' && ft_strlen(str[count[0]]) != 1)
		;
	else if (CL1 == 'o' && CL2 != 'h' && CL2 != 'l' && CL2 != 'j' && CL2 != 'z')
		ft_cut_entierto_o(str, var, count, liste);
	else if (CL1 == 'o' && CL2 == 'z')
		ft_cut_entierto3_ll(str, var, count, liste);
	else if (CL1 == 'o' && CL2 == 'j')
		ft_cut_entierto3_ull(str, var, count, liste);
	else if (CL1 == 'o' && CL2 == 'h' && CL3 == 'h')
		ft_cut_entierto3_char(str, var, count, liste);
	else if (CL1 == 'o' && CL2 == 'h')
		ft_cut_entierto3_short(str, var, count, liste);
	else if (CL1 == 'O' || (CL1 == 'o' && CL2 == 'l'))
		ft_cut_entierto3_maj(str, var, count, liste);
}
