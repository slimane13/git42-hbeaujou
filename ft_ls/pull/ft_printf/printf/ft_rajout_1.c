/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:07:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 19:18:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_flag_u3_2char(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}

void	ft_cut_flag_u3_2j(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}

void	ft_cut_flag_u3_2z(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}

void	ft_cut_cut_p2(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag > 0 && (*t_v).c != '0')
	{
		(*t_v).k = 3;
		while ((*t_v).k < (*t_v).flag)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
	else
	{
		if ((*t_v).flag < 0)
			(*t_v).flag = -(*t_v).flag;
		(*t_v).k = 3;
		while ((*t_v).k < (*t_v).flag)
		{
			if ((*t_v).c == '0')
				str[count[0]] = ft_strjoin(str[count[0]], "0");
			else
				str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k++;
		}
	}
}
