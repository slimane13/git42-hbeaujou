/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:32:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 17:32:38 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag_number(char **str, int count[3], int *nbr, char *c)
{
	int flag;

	*nbr = *nbr;
	if (str[count[0]][0] == '.' || (str[count[0]][0] == '0' &&
				str[count[0]][1] == '.'))
	{
		*c = '.';
		if (ft_isalpha(str[count[0]][1]) != 0)
			return (0);
		flag = ft_atoi_spec(str[count[0]]);
	}
	else if (str[count[0]][0] == '-' && str[count[0]][1] == '.')
	{
		str[count[0]][0] = '0';
		if (*c == 'h')
			flag = ft_atoi_length(str[count[0]]);
		else
			flag = ft_atoi_spec(str[count[0]]);
		*c = '.';
	}
	else if (str[count[0]][0] == '-' && str[count[0]][1] == '0')
	{
		*c = '0';
		flag = ft_atoi(str[count[0]]);
	}
	else if (str[count[0]][0] == '0')
	{
		*c = '0';
		flag = ft_atoi(str[count[0]]);
	}
	else
		flag = ft_atoi(str[count[0]]);
	return (flag);
}

void	attrib_p(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_p(&t_v, str, count);
	if (var[count[2]]->u_long != 0 && t_v.flag != 3500)
	{
		str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long,
				"0123456789abcdef");
		t_v.nbr = ft_strlen(str[count[0]]);
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		t_v.nbr = ft_strlen(str[count[0]]) + 2;
	}
	if (t_v.flag == 3500)
		ft_cut_flag_p1(&t_v, var, str, count);
	else if (var[count[2]]->u_long == 0 && t_v.c != '.')
		str[count[0]] = ft_strdup("0x0");
	else if (t_v.flag != 3500 && var[count[2]]->u_long == 0)
		str[count[0]] = ft_strdup("0x");
	if (t_v.flag != 0 && t_v.flag < 1000)
		ft_cut_flag_p2(&t_v, var, str, count);
	count[2]++;
}

void	attrib_x(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1(&t_v, var, str, count);
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

void	attrib_x_maj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_maj(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1_maj(var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_x2_maj(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_x3_maj(&t_v, var, str, count);
	else if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 3500 && t_v.flag != 2000 && t_v.flag != 5000)
		ft_cut_flag_x4_maj(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_o(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_o(&t_v, var, str, count);
	if (t_v.flag == 1000 && var[count[2]]->entier > 0)
		;
	else if (t_v.flag == 5000 && var[count[2]]->entier >= 0)
		ft_cut_flag_o1(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_o2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_o3(&t_v, var, str, count);
	if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 3500 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 5000)
		ft_cut_flag_o4(&t_v, str, count);
	else if (t_v.flag_save == 0 && t_v.c == '.' && t_v.spec == 1)
		str[count[0]][0] = '\0';
	else if (var[count[2]]->entier == 0 && t_v.c == '.' && t_v.spec == 1)
		str[count[0]][0] = '\0';
	count[2]++;
}
