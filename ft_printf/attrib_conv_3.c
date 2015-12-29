/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:46:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 15:28:06 by hbeaujou         ###   ########.fr       */
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
	int nbr;
	int flag;
	char c;
	int k;
	int check;
	int check_double;
	int neg;

	k = 0;
	c = 't';
	neg = 0;
	nbr = ft_nbrlen(var[count[2]]->v_long);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (flag == 3500)
		check_double = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.' && var[count[2]]->v_long < 0)
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_ntoa_base(var[count[2]]->v_long, "0123456789");
	if (var[count[2]]->v_long < 0 && str[count[0]][0] != '0')
		neg = 1;
	if (flag == 1000 && var[count[2]]->v_long >= 0)
	{
		neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (flag == 3500)
	{
		if (var[count[2]]->v_long < 0)
		{
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->v_long) + 1);
			while (k < check_double - nbr - 1)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
			k = 0;
			str[count[0]] = ft_strjoin("-", str[count[0]]);
			while (k < check - check_double)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
		else
		{
			while (k < check_double - nbr)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
			k = 0;
			while (k < check - check_double)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag == 2000 && var[count[2]]->v_long >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->v_long >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 4000)
	{
		if (var[count[2]]->v_long >= 0)
			str[count[0]] = ft_strjoin("+", str[count[0]]);
		while (k < check - nbr)
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
			flag != 3000 && flag != 4000 && flag != 3500 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + nbr + neg)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && (c == '0' || c == '.'))
		{
			if (var[count[2]]->v_long < 0)
				str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->v_long) + 1);
			while (k < flag - nbr - neg)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
			if (var[count[2]]->v_long < 0)
				str[count[0]] = ft_strjoin("-", str[count[0]]);
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
			while (k < flag - nbr - neg)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}
