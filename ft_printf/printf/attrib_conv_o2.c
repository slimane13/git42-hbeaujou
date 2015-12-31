/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_o2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:24:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 15:24:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_flag_o4(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
		ft_cut_flag_o4_1(t_v, str, count);
	else if ((*t_v).flag > 0 && ((*t_v).c == '0' || (*t_v).c == '.'))
		ft_cut_flag_o4_2(t_v, str, count);
	else if ((*t_v).flag < -1 && (*t_v).c == '0')
	{
		while ((*t_v).k > (*t_v).flag + (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
	}
	else
	{
		while ((*t_v).k < (*t_v).flag - (*t_v).nbr)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void	ft_cut_flag_o4_1(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	(*t_v).k = 0;
	(*t_v).nbr = ft_strlen(str[count[0]]);
	while ((*t_v).k > (*t_v).flag + (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}

void	ft_cut_flag_o4_2(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}
