/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:15:38 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:48:22 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_c(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).nbr = 0;
	(*t_v).c = 't';
	(*t_v).diff = 0;
	(*t_v).p = 1;
	(*t_v).check = ft_atoi(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	if (ft_atoi(var[count[2]]->string) == 0)
		rajout = 1;
	str[count[0]] = (char *)malloc(sizeof(char) * 2);
	str[count[0]][0] = ft_atoi(var[count[2]]->string);
	str[count[0]][1] = '\0';
	if (ft_atoi(var[count[2]]->string) == 0)
		char_nul = count[0];
}

void	ft_cut_flag_c1(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (var[count[2]]->stars < 0)
	{
		while ((*t_v).k > var[count[2]]->stars + (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
	}
	else
	{
		while ((*t_v).k < var[count[2]]->stars - (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_flag_c2(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if ((*t_v).c_d >= (*t_v).nbr)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).nbr;
	if (var[count[2]]->entier < 0)
		ft_cut_flag_c2_1(t_v, var, str, count);
	else
	{
		(*t_v).k = 0;
		while ((*t_v).k < (*t_v).check - (*t_v).diff - 1)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_flag_c2_1(t_cut *t_v, t_var **var, char **str, int count[3])
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

void	ft_cut_flag_c3(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
	{
		while ((*t_v).k > (*t_v).flag + 1)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
	}
	else
	{
		while ((*t_v).k < (*t_v).flag - 1)
		{
			if ((*t_v).c == '0')
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			else
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}
