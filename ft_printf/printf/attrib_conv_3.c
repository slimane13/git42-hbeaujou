/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:46:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 11:19:40 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_c_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_c_maj(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->w_entier > 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000 && var[count[2]]->w_entier >= 0)
	{
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_c1_maj(&t_v, var, str, count);
	else if (t_v.c == '.')
	{
	}
	else if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000
			&& t_v.flag != 5000 && t_v.c != '.')
		ft_cut_flag_c2_maj(&t_v, str, count);
	if (var[count[2]]->w_entier == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_u(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
	}
	else if (t_v.flag == 2000)
	{
	}
	else if (t_v.flag == 4000)
		ft_cut_flag_u1(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_u3(&t_v, var, str, count);
	else if (t_v.flag == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u4(&t_v, str, count);
	count[2]++;
}

void	attrib_o_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_maj(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
		ft_cut_flag_o4_maj(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_o1_maj(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_o2_maj(&t_v, var, str, count);
	if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 3500 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o3_maj(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.' && t_v.spec == 0)
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_d_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_maj(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->v_long >= 0)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d1_maj(&t_v, var, str, count);
	else if (t_v.flag == 2000 && var[count[2]]->v_long >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d2_maj(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d3_maj(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_maj(&t_v, var, str, count);
	count[2]++;
}

void	attrib_x_l(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_l(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1_l(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_x2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_x3(&t_v, var, str, count);
	if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3500 &&
			t_v.flag != 3000 && t_v.flag != 5000 && t_v.spec == 0)
		ft_cut_flag_x4(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.' && t_v.spec == 0)
		str[count[0]][0] = '\0';
	count[2]++;
}
