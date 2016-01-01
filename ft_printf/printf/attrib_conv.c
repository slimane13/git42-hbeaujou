/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:20:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 16:34:46 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char **str, int count[3], int *nbr, char *c)
{
	if ((str[count[0]][0] == '-' && str[count[0]][1] == '+') ||
			(str[count[0]][0] == '+' && str[count[0]][1] == '-'))
		return (cut_flag_check2(nbr));
	else if (str[count[0]][0] == '0' && str[count[0]][1] == '-')
		return (cut_flag_check3(nbr));
	else if ((ft_isdigit(str[count[0]][0]) && str[count[0]][1] == '.') ||
			(ft_isdigit(str[count[0]][0]) && ft_isdigit(str[count[0]][1]) &&
			str[count[0]][2] == '.') || (str[count[0]][0] == ' ' &&
				str[count[0]][3] == '.') || (str[count[0]][0] == '+' &&
					str[count[0]][3] == '.'))
		return (3500);
	else if ((str[count[0]][0] == '+' && str[count[0]][1] != '0') ||
			(str[count[0]][0] == ' ' && str[count[0]][1] == '+') ||
			(str[count[0]][0] == ' ' && str[count[0]][1] == ' ' &&
			str[count[0]][2] == '+'))
		return (cut_flag_check4(nbr));
	else if (str[count[0]][0] == '+' && str[count[0]][1] == '0')
		return (cut_flag_check5(nbr));
	else if (str[count[0]][0] == ' ')
		return (cut_flag_check(str, count, nbr));
	else if (str[count[0]][0] == '*')
		return (cut_flag_check6(nbr));
	else if (str[count[0]][0] == '#' || str[count[0]][1] == '#')
		return (cut_flag_check7(nbr, c, str, count));
	else
		return (check_flag_number(str, count, nbr, c));
	return (-1);
}

void	attrib_d(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_d(&t_v, var, str, count);
	if (t_v.flag == 1000 || t_v.flag == 4500 || t_v.flag == 2500)
		ft_cut_flag_d1(&t_v, var, str, count);
	else if (t_v.flag == 1500)
		ft_cut_flag_d2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_d3(&t_v, var, str, count);
	else if (t_v.flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
		ft_cut_flag_d4(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_d5(&t_v, var, str, count);
	else if (t_v.flag == 0 && t_v.c == '.' && var[count[2]]->entier == 0)
		str[count[0]][0] = '\0';
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 &&
			t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d6(&t_v, var, str, count);
	count[2]++;
}

void	attrib_c(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_c(&t_v, var, str, count);
	if (t_v.flag == 1000 && ft_atoi(var[count[2]]->string) > 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (t_v.flag == 2000 && var[count[2]]->entier >= 0)
	{
	}
	else if (t_v.flag == 3000)
		ft_cut_flag_c1(&t_v, var, str, count);
	else if (t_v.c == '.')
	{
	}
	else if (t_v.flag == 3500)
		ft_cut_flag_c2(&t_v, var, str, count);
	else if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3500 && t_v.flag != 3000 &&
			t_v.flag != 4000 && t_v.flag != 5000 && t_v.c != '.')
		ft_cut_flag_c3(&t_v, str, count);
	if (ft_atoi(var[count[2]]->string) == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_s(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_s(&t_v, var, str, count);
	if (t_v.flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (t_v.flag == 3500)
		ft_cut_flag_s1(&t_v, str, count);
	else if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3000 &&
			t_v.flag != 4000 && t_v.flag != 5000 && t_v.flag != 3500)
		ft_cut_flag_s2(&t_v, str, count);
	else if (t_v.check == 0 && t_v.c_d != 0 && t_v.flag == 0)
		str[count[0]] = ft_strsub(str[count[0]], 0, t_v.c_d);
	count[2]++;
}
