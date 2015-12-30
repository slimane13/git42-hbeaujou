/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:49 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:14:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_u_j(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_j(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_u1_j(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2_j(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u3_j(&t_v, str, count);
	count[2]++;
}

void	attrib_o_j(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_j(&t_v, var, str, count);
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
		ft_cut_flag_o1_j(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o2_j(&t_v, str, count);
	count[2]++;
}

void	attrib_d_z(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_z(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d1_z(&t_v, str, count);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d2_z(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d3_z(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_z(&t_v, str, count);
	count[2]++;
}

void	attrib_u_z(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_z(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_u1_z(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2_z(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u3_z(&t_v, str, count);
	count[2]++;
}

void	attrib_o_z(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_z(&t_v, var, str, count);
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
		ft_cut_flag_o1_z(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o2_z(&t_v, str, count);
	count[2]++;
}
