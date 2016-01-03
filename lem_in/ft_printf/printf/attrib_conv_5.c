/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:56:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:34:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_d_ll(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_ll(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d1_ll(&t_v, str, count);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d2_ll(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d3_ll(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_ll(&t_v, str, count);
	count[2]++;
}

void	attrib_x_short(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_short(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		t_v.flag = t_v.l;
		t_v.nbr++;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_x1_short(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_short(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]],
					1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_x_maj_short(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_mshrt(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		t_v.flag = t_v.l;
		t_v.nbr++;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_x1_mshrt(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_mshrt(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]],
					1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_d_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_char(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->carac >= 0)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d3_char(&t_v, var, str, count);
	else if (t_v.flag == 2000 && var[count[2]]->carac >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d1_char(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d2_char(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000
			&& t_v.flag != 3000 && t_v.flag != 4000
			&& t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_char(&t_v, var, str, count);
	count[2]++;
}

void	attrib_u_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_u_char(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_u1_char(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_u2_char(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_u3_char(&t_v, str, count);
	count[2]++;
}
