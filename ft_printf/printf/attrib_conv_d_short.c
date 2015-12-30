/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_d_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 16:05:28 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 16:17:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_init_d_short(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).c = 't';
	(*t_v).neg = 0;
	(*t_v).nbr = ft_nbrlen(var[count[2]]->v_short);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	if ((*t_v).flag == 3500)
		(*t_v).c_d = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.' && var[count[2]]->v_short < 0)
		(*t_v).nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * (*t_v).nbr);
	str[count[0]] = ft_itoa(var[count[2]]->v_short);
	if (var[count[2]]->v_short < 0 && str[count[0]][0] != '0')
		(*t_v).neg = 1;
}

void    ft_cut_flag_d1_short(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->v_short < 0)
		ft_cut_flag_d1_1short(t_v, var, str, count);
	else
	{
		while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			(*t_v).k++;
		}
		(*t_v).k = 0;
		while ((*t_v).k < (*t_v).check - (*t_v).c_d)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void    ft_cut_flag_d1_1short(t_cut *t_v, t_var **var, char **str, int count[3])
{
	str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr - 1)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	(*t_v).k = 0;
	str[count[0]] = ft_strjoin("-", str[count[0]]);
	while ((*t_v).k < (*t_v).check - (*t_v).c_d)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}

void    ft_cut_flag_d2_short(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->v_short >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	while ((*t_v).k < (*t_v).check - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k++;
	}
}

void    ft_cut_flag_d3_short(t_cut *t_v, t_var **var, char **str, int count[3])
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
