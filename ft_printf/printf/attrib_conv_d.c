/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:21:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 17:01:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_d(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).c = 't';
	(*t_v).diff = 0;
	(*t_v).neg = 0;
	(*t_v).p = 1;
	(*t_v).nbr = ft_nbrlen(var[count[2]]->entier);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).g = 'q';
	ft_c_c_init_d(t_v, var, str, count);
	if (str[count[0]][2] == '.' && var[count[2]]->entier < 0)
	{
		(*t_v).nbr--;
		(*t_v).check--;
	}
	if ((*t_v).z == '+' && str[count[0]][0] == '-' && (*t_v).c == '0')
		(*t_v).c = '-';
	str[count[0]] = (char *)malloc(sizeof(char) * (*t_v).nbr);
	str[count[0]] = ft_itoa(var[count[2]]->entier);
	if (var[count[2]]->entier < 0 && str[count[0]][0] != '0')
		(*t_v).neg = 1;
}

void	ft_cut_flag_d1(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).flag == 1000 && var[count[2]]->entier >= 0)
	{
		(*t_v).neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if ((*t_v).flag == 4500)
	{
		if ((*t_v).check < 0)
			(*t_v).check = -(*t_v).check;
		while ((*t_v).k < (*t_v).check - 1)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k++;
		}
	}
	else if ((*t_v).flag == 2500)
	{
		if ((*t_v).g == 'q')
			str[count[0]] = ft_strjoin("0", str[count[0]]);
		if ((*t_v).g != 'l')
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
	}
}

void	ft_cut_flag_d2(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).neg = 1;
	if (var[count[2]]->entier == 0)
		(*t_v).nbr = 2;
	else
		(*t_v).nbr = ft_nbrlen(var[count[2]]->entier) + 1;
	while ((*t_v).nbr < (*t_v).check)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).nbr++;
	}
	str[count[0]] = ft_strjoin("+", str[count[0]]);
}

void	ft_cut_flag_d3(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).c_d >= (*t_v).nbr)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).nbr;
	if (var[count[2]]->entier < 0)
		ft_cut_cut_d3_1(t_v, var, str, count);
	else
	{
		if (var[count[2]]->entier == 0 && (*t_v).c_d == 0)
			str[count[0]] = ft_strdup(" ");
		while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			(*t_v).k++;
		}
		if ((*t_v).z == '+')
			ft_c_c_flag_d3(t_v, str, count);
		(*t_v).k = 0;
		while ((*t_v).k < (*t_v).check - (*t_v).diff)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_cut_d3_1(t_cut *t_v, t_var **var, char **str, int count[3])
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
