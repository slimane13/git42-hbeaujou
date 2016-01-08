/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_d_cc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:55:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 17:25:05 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_c_init_d(t_cut *t_v, t_var **var, char **str, int count[3])
{
	if (((str[count[0]][0] == '0' && str[count[0]][1] == ' ') ||
				(str[count[0]][0] == ' ' && str[count[0]][1] == '0')) &&
			var[count[2]]->entier != 0)
	{
		if (var[count[2]]->entier < 0)
			(*t_v).g = 'l';
		else
			(*t_v).g = ' ';
	}
	if (str[count[0]][0] == '+' || str[count[0]][1] == '+' ||
			str[count[0]][2] == '+')
		(*t_v).z = '+';
	if (str[count[0]][0] == '.' && var[count[2]]->entier < 0)
		(*t_v).nbr--;
}

void	ft_c_c_flag_d3(t_cut *t_v, char **str, int count[3])
{
	str[count[0]] = ft_strjoin("+", str[count[0]]);
	(*t_v).nbr--;
	(*t_v).check--;
}

void	ft_c_c_flag_o1(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).check - (*t_v).nbr - 1)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}

void	ft_c_c_flag_o12(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).neg - (*t_v).nbr - 1)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k++;
	}
}

void	ft_c_c_flag_s2(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}
