/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 18:12:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 16:02:15 by hbeaujou         ###   ########.fr       */
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
	nbr = ft_nbrlen(var[count[2]]->v_short);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (flag == 3500)
		check_double = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.' && var[count[2]]->v_short < 0)
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa(var[count[2]]->v_short);
	if (var[count[2]]->v_short < 0 && str[count[0]][0] != '0')
		neg = 1;
	if (flag == 1000 && var[count[2]]->v_short >= 0)
	{
		neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (flag == 3500)
	{
		if (var[count[2]]->v_short < 0)
		{
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
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
	else if (flag == 2000 && var[count[2]]->v_short >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->v_short >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 4000)
	{
		if (var[count[2]]->v_short >= 0)
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
			if (var[count[2]]->v_short < 0)
				str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
			while (k < flag - nbr - neg)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
			if (var[count[2]]->v_short < 0)
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

void	attrib_u_short(char **str, t_var **var, int count[3])
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
	nbr = ft_nbrlen(var[count[2]]->u_short);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * (nbr * 5));
	ft_ulltstr_base((unsigned long long)var[count[2]]->u_short, "0123456789", str[count[0]]);
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

void	attrib_o_short(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_short);
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_short, "01234567");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		flag = l;
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
	if (flag != -1 && flag != 1000 &&
			flag != 2000 && flag != 3000 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && (c == '0' || c == '.'))
		{
			while (k < flag - nbr)
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
			while (k < flag - nbr)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}

void	attrib_u_ll(char **str, t_var **var, int count[3])
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
	nbr = ft_nbrlen_ll(var[count[2]]->u_l_long);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long, "0123456789");
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
