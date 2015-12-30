/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 11:34:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 11:47:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_init_s(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).diff = 0;
	(*t_v).c = 't';
	(*t_v).z = 'o';
	(*t_v).str_len = 7;
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).str_len, &(*t_v).c);
	if (str[count[0]][0] == '.' || str[count[0]][1] == '.' ||
			str[count[0]][2] == '.')
		(*t_v).c = '.';
	if (str[count[0]][0] == '0')
		(*t_v).z = '0';
	if (var[count[2]]->string == NULL && (*t_v).c != '.')
		(*t_v).flag = -1;
	if (var[count[2]]->string != NULL)
		(*t_v).str_len = ft_strlen(var[count[2]]->string);
	str[count[0]] = (char *)malloc(sizeof(char) * (*t_v).str_len);
	if (var[count[2]]->string != NULL)
		str[count[0]] = ft_strcpy(str[count[0]], var[count[2]]->string);
}

void    ft_cut_flag_s1(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).c_d < (*t_v).str_len)
		str[count[0]] = ft_strsub(str[count[0]], 0, (*t_v).c_d);
	(*t_v).str_len = ft_strlen(str[count[0]]);
	if ((*t_v).c_d >= (*t_v).str_len)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).str_len;
	if ((*t_v).check < (*t_v).c_d)
		(*t_v).c_d = (*t_v).check;
	while ((*t_v).k < (*t_v).c_d - (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
	(*t_v).k = 0;
	while ((*t_v).k < (*t_v).check - (*t_v).diff)
	{
		if ((*t_v).z == '0')
			str[count[0]] = ft_strjoin("0", str[count[0]]);
		else
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}

void    ft_cut_flag_s2(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
	{
		while ((*t_v).k > (*t_v).flag + (*t_v).str_len)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			(*t_v).k--;
		}
	}
	else if ((*t_v).flag == 0 && (*t_v).c == '.')
		str[count[0]][0] = '\0';
	else if ((*t_v).flag > 0 && (*t_v).c == '.')
	{
		if ((*t_v).flag < 0)
			(*t_v).flag = -(*t_v).flag;
		str[count[0]] = ft_strsub(str[count[0]], 0, (*t_v).flag);
	}
	else if ((*t_v).c == '0')
		ft_cut_flag_s2_1(t_v, str, count);
	else
		ft_cut_flag_s2_2(t_v, str, count);
}

void    ft_cut_flag_s2_1(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}

void    ft_cut_flag_s2_2(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}
