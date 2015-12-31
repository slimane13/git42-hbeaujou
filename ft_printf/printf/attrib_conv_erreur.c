/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_erreur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:02:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 11:43:19 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_erreur(t_cut *t_v, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).diff = 0;
	(*t_v).p = 1;
	(*t_v).c = 't';
	(*t_v).g = 'r';
	(*t_v).z = 'y';
	(*t_v).last = 'u';
	(*t_v).str_len = ft_strlen(str[count[0]]);
	(*t_v).check = ft_atoi(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).str_len, &(*t_v).c);
	(*t_v).nbrlen = ft_nbrlen((*t_v).flag);
	ft_cut_init_erreur2(t_v, str, count);
	str[count[0]] = ft_strsub(str[count[0]], (*t_v).nbrlen, (*t_v).str_len);
	(*t_v).str_len = (*t_v).str_len - (*t_v).nbrlen;
}

void	ft_cut_init_erreur2(t_cut *t_v, char **str, int count[3])
{
	if (ft_isalpha(str[count[0]][ft_strlen(str[count[0]]) - 1]) != 1)
		(*t_v).g = 'q';
	if ((*t_v).flag < 0)
		(*t_v).nbrlen++;
	if ((*t_v).flag < 0)
		(*t_v).nbr = -(*t_v).flag;
	if (str[count[0]][0] == '0')
		(*t_v).z = '0';
	if (ft_strlen(str[count[0]]) == 4)
		(*t_v).last = str[count[0]][3];
	if ((*t_v).flag == 0 || (*t_v).g == 'q')
		(*t_v).nbrlen = 0;
	if (str[count[0]][0] == ' ')
		(*t_v).nbrlen = (*t_v).str_len - 2;
}

void	ft_cut_flag_erreur1(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).c_d == 0)
		str[count[0]] = ft_strsub(str[count[0]], 0, 1);
	(*t_v).str_len = ft_strlen(str[count[0]]);
	if ((*t_v).c_d >= (*t_v).str_len)
		(*t_v).diff = (*t_v).c_d;
	else
		(*t_v).diff = (*t_v).str_len;
	(*t_v).k = 1;
	while ((*t_v).k < (*t_v).check - (*t_v).diff)
	{
		if ((*t_v).z == '0')
			str[count[0]] = ft_strjoin("0", str[count[0]]);
		else
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
	if ((*t_v).last == 'u')
		str[count[0]] = ft_strjoin(str[count[0]], "%");
	else
		str[count[0]] = ft_charjoin(str[count[0]], (*t_v).last);
}

void	ft_cut_flag_erreur2(t_cut *t_v, char **str, int count[3])
{
	if ((*t_v).flag < -1 && (*t_v).c != '0')
		ft_cut_flag_erreur2_1(t_v, str, count);
	else if ((*t_v).flag == 0 && (*t_v).c == '.')
		str[count[0]][0] = '\0';
	else if ((*t_v).flag > 0 && (*t_v).c == '.')
	{
		if ((*t_v).flag < 0)
			(*t_v).flag = -(*t_v).flag;
		str[count[0]] = ft_strsub(str[count[0]], 0, (*t_v).flag);
	}
	else if (ft_isalldigit(str[count[0]]) != 1)
	{
		while ((*t_v).k < (*t_v).flag - (*t_v).str_len)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			(*t_v).k++;
		}
	}
	else
		;
}

void	ft_cut_flag_erreur2_1(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}
