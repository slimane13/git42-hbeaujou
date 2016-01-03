/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 20:35:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 19:13:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_o_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o_char(&t_v, var, str, count);
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
		ft_cut_flag_o1_char(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o2_char(&t_v, str, count);
	count[2]++;
}

void	attrib_x_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_char(&t_v, var, str, count);
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
		ft_cut_flag_x1_char(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_char(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]],
					1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_x_maj_char(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_mchr(&t_v, var, str, count);
	if (t_v.flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 5000)
	{
		str[count[0]] = ft_strjoin("0X", str[count[0]]);
		t_v.flag = t_v.l;
		t_v.nbr++;
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_x1_mchr(&t_v, var, str, count);
	if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_x2_mchr(&t_v, str, count);
	if (t_v.c != '.' && t_v.c != '0')
	{
		while (str[count[0]][0] == '0' && str[count[0]][1] != '\0')
			str[count[0]] = ft_strsub(str[count[0]],
					1, ft_strlen(str[count[0]]));
	}
	count[2]++;
}

void	attrib_d_j(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d_j(&t_v, var, str, count);
	if (t_v.flag == 1000)
	{
		t_v.neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_d1_j(&t_v, str, count);
	else if (t_v.flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d4_j(&t_v, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d2_j(&t_v, var, str, count);
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d3_j(&t_v, str, count);
	count[2]++;
}

void	attrib_s_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_s_maj(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->w_string != NULL)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 3000)
		ft_cut_flag_s1_maj(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_s2_maj(&t_v, str, count);
	else if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3500 && t_v.flag != 3000 &&
			t_v.flag != 4000 && t_v.flag != 5000 && t_v.c != '.')
		ft_cut_flag_s3_maj(&t_v, str, count);
	if (var[count[2]]->w_string == NULL && t_v.c == '.')
		str[count[0]][0] = '\0';
	else if (var[count[2]]->w_string == NULL && t_v.c != '.')
		str[count[0]] = ft_strdup("(null)");
	else if (t_v.flag > 0 && t_v.c == '.' && t_v.c_d != 0 && t_v.check == 0)
		ft_cut_flag_s4_maj(&t_v, str, count);
	else if (t_v.flag > 0 && t_v.c == '.' && t_v.c_d != 0 && t_v.check != 0)
		ft_cut_flag_s5_maj(&t_v, str, count);
	else if (t_v.flag > 0 && t_v.c == '.' && t_v.c_d == 0 && t_v.p == 1)
		ft_cut_flag_s6_maj(&t_v, str, count);
	g_s_maj = 1;
	count[2]++;
}
