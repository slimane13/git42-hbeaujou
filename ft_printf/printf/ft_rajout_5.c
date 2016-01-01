/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 18:34:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 18:40:53 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_c_f_d21(t_cut *t_v, t_var **var, char **str, int count[3])
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

void	ft_c_c_f_d23(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).z == '+' && (*t_v).flag != 0 && var[count[2]]->entier > 0)
	{
		str[count[0]] = ft_strjoin("+", str[count[0]]);
		(*t_v).nbr++;
	}
	else if ((*t_v).z == '+' && (*t_v).flag == 0)
		ft_c_c_f_d231(t_v, var, str, count);
	if ((*t_v).g == ' ')
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	while ((*t_v).k <
			(*t_v).flag - (*t_v).nbr - (*t_v).neg - ((*t_v).g == ' '))
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

void	ft_c_c_f_d231(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).nbr++;
	if (var[count[2]]->entier < 0)
	{
		str[count[0]] = ft_strsub(str[count[0]], 1,
				ft_strlen(str[count[0]]));
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
