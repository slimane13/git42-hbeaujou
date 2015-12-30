/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:56:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 14:42:55 by hbeaujou         ###   ########.fr       */
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
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
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
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_strlen(str[count[0]]));
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
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 && t_v.flag != 3500 && t_v.flag != 5000)
		ft_cut_flag_d4_char(&t_v, var, str, count);
	count[2]++;
}

void	attrib_u_char(char **str, t_var **var, int count[3])
{
	int nbr;
	int s_nbr;
	int flag;
	char c;
	int k;
	int check;
	int neg;

	k = 0;
	c = 't';
	neg = 0;
	nbr = ft_nbrlen(var[count[2]]->u_carac);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * (nbr * 5));
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_carac, "0123456789");
	s_nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
	{
		neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 4000)
	{
		str[count[0]] = ft_strjoin("+", str[count[0]]);
		while (k < check - s_nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			k++;
		}
	}
	else if (flag == 3000)
	{
		if (var[count[2]]->stars < 0)
		{
			while (k > var[count[2]]->stars + nbr - 1)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < var[count[2]]->stars - nbr + 1)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag != 1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + s_nbr + neg)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && (c == '0' || c == '.'))
		{
			while (k < flag - s_nbr - neg)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
		else if (flag < -1 && c == '0')
		{
			while (k > flag)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k--;
			}
		}
		else
		{
			while (k < flag - s_nbr - neg)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}
