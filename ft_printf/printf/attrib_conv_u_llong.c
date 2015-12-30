/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_u_llong.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:41:24 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 16:53:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_init_u_llong(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).c = 't';
	(*t_v).neg = 0;
	(*t_v).nbr = ft_nbrlen_ll(var[count[2]]->u_l_long);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		(*t_v).nbr--;
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long, "0123456789");
	(*t_v).s_nbr = ft_strlen(str[count[0]]);
}

void    ft_cut_flag_u1_llong(t_cut *t_v, char **str, int count[3])
{
	str[count[0]] = ft_strjoin("+", str[count[0]]);
	while ((*t_v).k < (*t_v).check - (*t_v).s_nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k++;
	}
}

void    ft_cut_flag_u2_llong(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->stars < 0)
		ft_cut_flag_u2_1llong(t_v, var, str, count);
	else
	{
		while ((*t_v).k < var[count[2]]->stars - (*t_v).nbr + 1)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void    ft_cut_flag_u2_1llong(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while ((*t_v).k > var[count[2]]->stars + (*t_v).nbr - 1)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}
