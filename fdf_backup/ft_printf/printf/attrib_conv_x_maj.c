/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_x_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:29:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:52:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_x_maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).diff = 0;
	(*t_v).p = 0;
	(*t_v).c = 't';
	(*t_v).nbr = ft_nbrlen(var[count[2]]->u_long);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "0123456789ABCDEF");
	(*t_v).nbr = ft_strlen(str[count[0]]);
}

void	ft_cut_flag_x1_maj(t_var **var, char **str, int count[3])
{
	if (var[count[2]]->u_long != 0)
		str[count[0]] = ft_strjoin("0X", str[count[0]]);
}

void	ft_cut_flag_x2_maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->stars < 0)
	{
		while ((*t_v).k > var[count[2]]->stars + (*t_v).nbr - 1)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
	}
	else
	{
		while ((*t_v).k < var[count[2]]->stars - (*t_v).nbr + 1)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_flag_x3_maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).c_d >= (*t_v).nbr)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).nbr;
	if (var[count[2]]->entier < 0)
		ft_cut_flag_x3_1maj(t_v, var, str, count);
	else
	{
		while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			(*t_v).k++;
		}
		(*t_v).k = 0;
		while ((*t_v).k < (*t_v).check - (*t_v).diff)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_flag_x3_1maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	str[count[0]] = ft_strsub(str[count[0]], 1,
			ft_nbrlen(var[count[2]]->entier) + 1);
	if ((*t_v).check < (*t_v).c_d)
		(*t_v).k = -1;
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr - 1)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
		(*t_v).p = 0;
	}
	str[count[0]] = ft_strjoin("-", str[count[0]]);
	while ((*t_v).p < (*t_v).check - (*t_v).diff)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).p++;
	}
}
