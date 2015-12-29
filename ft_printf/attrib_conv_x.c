/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 12:09:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 12:20:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_init_x(t_cut *t_v, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).p = 1;
	(*t_v).diff = 0;
	(*t_v).spec = 0;
	(*t_v).c = 't';
	(*t_v).nbr = ft_nbrlen(var[count[2]]->u_long);
	(*t_v).l = ft_atoi_spec_o(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789abcdef");
	(*t_v).nbr = ft_strlen(str[count[0]]);
}

void    ft_cut_flag_x1(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while (k < check_double - nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		k++;
	}
	if (var[count[2]]->u_long != 0)
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
	flag = l;
	if (var[count[2]]->u_long == 0)
		spec = 0;
	else
		spec = 1;
	nbr++;
}

void    ft_cut_flag_x2(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->stars < 0)
	{
		while (k > var[count[2]]->stars + nbr - 1)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			k--;
		}
	}
	else
	{
		while (k < var[count[2]]->stars - nbr + 1)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
}

void    ft_cut_flag_x3(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (check_double >= nbr)
		diff = check_double;
	else
		diff = nbr;
	if (var[count[2]]->entier < 0)
	{
		str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
		if (check < check_double)
			k = -1;
		while (k < check_double - nbr - 1)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			k++;
			p = 0;
		}
		str[count[0]] = ft_strjoin("-", str[count[0]]);
		while (p < check - diff)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			p++;
		}
	}
	else
	{
		while (k < check_double - nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			k++;
		}
		k = 0;
		while (k < check - diff)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
}
