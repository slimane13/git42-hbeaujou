/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 18:12:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:33:48 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_u_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_maj(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_u1_maj(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2_maj(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u3_maj(&t_v, str, count);
	count[2]++;
}

void	attrib_d_short(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_short(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->v_short >= 0)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d1_short(&t_v, var, str, count);
	else if (t_v.flag == 2000 && var[count[2]]->v_short >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 2000 && var[count[2]]->v_short >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d2_short(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d3_short(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_short(&t_v, var, str, count);
	count[2]++;
}

void	attrib_u_short(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_short(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
	{
		str[count[0]] = ft_strjoin("+", str[count[0]]);
		while (t_v.k < t_v.check - t_v.s_nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			t_v.k++;
		}
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_u1_short(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u2_short(&t_v, str, count);
	count[2]++;
}

void	attrib_o_short(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_short(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		t_v.flag = t_v.l;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_o1_short(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o2_short(&t_v, str, count);
	count[2]++;
}

void	attrib_u_ll(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_llong(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_u1_llong(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2_llong(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u3_llong(&t_v, str, count);
	count[2]++;
}
