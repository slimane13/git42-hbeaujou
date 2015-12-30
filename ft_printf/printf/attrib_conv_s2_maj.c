/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_s2_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 16:17:42 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 16:25:40 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_flag_s4_maj(t_cut *t_v, char **str, int count[3])
{
	(*t_v).flag = (*t_v).flag - (*t_v).flag % 3;
	str[count[0]][(*t_v).flag] = '\0';
}

void    ft_cut_flag_s5_maj(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).c_d < 3)
		(*t_v).c_d = (*t_v).c_d % 3;
	else
		(*t_v).c_d = (*t_v).c_d - (*t_v).c_d % 3;
	str[count[0]][(*t_v).c_d] = '\0';
	(*t_v).k = 0;
	(*t_v).nbr = ft_strlen(str[count[0]]);
	while ((*t_v).k < (*t_v).check - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}

void    ft_cut_flag_s6_maj(t_cut *t_v, char **str, int count[3])
{
	(*t_v).k = 0;
	str[count[0]][0] = '\0';
	while ((*t_v).k < (*t_v).check)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}
