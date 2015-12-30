/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_u_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 14:52:58 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 15:02:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_init_u_char(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).c = 't';
	(*t_v).neg = 0;
	(*t_v).nbr = ft_nbrlen(var[count[2]]->u_carac);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		(*t_v).nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * ((*t_v).nbr * 5));
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_carac, "0123456789");
	(*t_v).s_nbr = ft_strlen(str[count[0]]);
}

void    ft_cut_flag_u1_char(t_cut *t_v, char **str, int count[3])
{
	str[count[0]] = ft_strjoin("+", str[count[0]]);
	while ((*t_v).k < (*t_v).check - (*t_v).s_nbr)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k++;
	}
}

void    ft_cut_flag_u2_char(t_cut *t_v, t_var **var, char **str, int count[3])
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

void    ft_cut_flag_u3_char(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
		ft_cut_flag_u3_1char(t_v, str, count);
	else if ((*t_v).flag > 0 && ((*t_v).c == '0' || (*t_v).c == '.'))
		ft_cut_flag_u3_2char(t_v, str, count);
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
		while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}

void    ft_cut_flag_u3_1char(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).s_nbr + (*t_v).neg)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}

void    ft_cut_flag_u3_2char(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}
