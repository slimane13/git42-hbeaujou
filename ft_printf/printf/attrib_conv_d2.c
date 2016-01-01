/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_d2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:22:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 16:16:04 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_flag_d4(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr + 1)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	if (var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	(*t_v).k = 0;
	(*t_v).nbr = ft_strlen(str[count[0]]);
	while ((*t_v).k > (*t_v).check + (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}

void	ft_cut_flag_d5(t_cut *t_v, t_var **var, char **str, int count[3])
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

void	ft_cut_flag_d6(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
	{
		while ((*t_v).k < (*t_v).c_d - (*t_v).nbr + (*t_v).neg)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			(*t_v).k++;
		}
		(*t_v).k = -(*t_v).k;
		if ((*t_v).z == '+' && var[count[2]]->entier > 0)
			(*t_v).nbr++;
		while ((*t_v).k > (*t_v).flag + (*t_v).nbr + (*t_v).neg)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
		if ((*t_v).z == '+' && var[count[2]]->entier > 0)
			str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if ((*t_v).flag > 0 && ((*t_v).c == '0' || (*t_v).c == '.'))
		ft_cut_flag_d6_1(t_v, var, str, count);
	else if ((*t_v).flag < -1 && (*t_v).c == '0')
		ft_cut_flag_d6_2(t_v, var, str, count);
	else
	{
		if ((*t_v).z == '+' && (*t_v).flag != 0 && var[count[2]]->entier > 0)
		{
			str[count[0]] = ft_strjoin("+", str[count[0]]);
			(*t_v).nbr++;
		}
		else if ((*t_v).z == '+' && (*t_v).flag == 0)
		{
			(*t_v).nbr++;
			if (var[count[2]]->entier < 0)
			{
				str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
				(*t_v).z = '-';
			}
			while ((*t_v).k < (*t_v).check - (*t_v).nbr)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				(*t_v).k++;
			}
			if ((*t_v).z == '-')
				str[count[0]] = ft_strjoin("-", str[count[0]]);
			else
				str[count[0]] = ft_strjoin("+", str[count[0]]);
		}
		if ((*t_v).g == ' ')
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
		while ((*t_v).k < (*t_v).flag - (*t_v).nbr - (*t_v).neg - ((*t_v).g == ' '))
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
		if ((*t_v).c == '-' && (*t_v).c_d > 0)
		{
			while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				(*t_v).k++;
			}
		}
	}
}

void	ft_cut_flag_d6_1(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->entier < 0)
		str[count[0]] = ft_strsub(str[count[0]], 1,
				ft_nbrlen(var[count[2]]->entier) + 1);
	while ((*t_v).k < (*t_v).flag - (*t_v).nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	if (var[count[2]]->entier < 0)
		str[count[0]] = ft_strjoin("-", str[count[0]]);
}

void	ft_cut_flag_d6_2(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).nbr + (var[count[2]]->entier < 0))
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}
