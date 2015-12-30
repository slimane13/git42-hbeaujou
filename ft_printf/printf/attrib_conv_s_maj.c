/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_s_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:26:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:26:22 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_s_maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).compteur = 0;
	(*t_v).i = 0;
	(*t_v).diff = 0;
	(*t_v).p = 1;
	(*t_v).nbr = 0;
	(*t_v).c = 't';
	(*t_v).check = ft_atoi(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	if (str[count[0]][1] == '.' || str[count[0]][2] == '.')
		(*t_v).c = '.';
	if (str[count[0]][0] == '0')
		(*t_v).m = '0';
	str[count[0]] = (char *)malloc(sizeof(char) * 20);
	(*t_v).str_2 = (char *)malloc(sizeof(char) * 20);
	if (var[count[2]]->w_string != 0)
		ft_cut_init_s2_maj(t_v, var, str, count);
}

void	ft_cut_init_s2_maj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while (var[count[2]]->w_string[(*t_v).i])
	{
		utf8encode((*t_v).str_2, var[count[2]]->w_string[(*t_v).i]);
		if ((*t_v).str_2[0] == 32)
			str[count[0]] = ft_strjoin(str[count[0]], " ");
		else
			str[count[0]] = ft_strjoin(str[count[0]], (*t_v).str_2);
		(*t_v).i++;
		(*t_v).compteur++;
	}
}

void	ft_cut_flag_s1_maj(t_cut *t_v, t_var **var, char **str, int count[3])
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

void	ft_cut_flag_s2_maj(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).c_d >= (*t_v).compteur)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).compteur;
	(*t_v).k = 0;
	if ((*t_v).c_d == 0)
		str[count[0]] = ft_strdup("\0");
	while ((*t_v).k < (*t_v).check && (*t_v).c_d == 0)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).compteur++;
		(*t_v).k++;
	}
	if ((*t_v).m == '0')
		(*t_v).p = 0;
}

void	ft_cut_flag_s3_maj(t_cut *t_v, char **str, int count[3])
{
	(*t_v).nbr = ft_strlen(str[count[0]]);
	if ((*t_v).flag < -1 && (*t_v).c != '0')
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
			if ((*t_v).c == '0')
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			else
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
}
