/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_x2_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:23:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 13:46:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_flag_x4_maj(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
		ft_cut_flag_x4_1maj(t_v, str, count);
	else if ((*t_v).flag > 0 && ((*t_v).c == '0' || (*t_v).c == '.'))
		ft_cut_flag_x4_2maj(t_v, str, count);
	else if ((*t_v).flag < -1 && (*t_v).c == '0')
	{
		while ((*t_v).k > (*t_v).flag)
		{
			str[count[0]] = ft_strjoin("0", str[count[0]]);
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

void    ft_cut_flag_x4_1maj(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}

void    ft_cut_flag_x4_2maj(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}
