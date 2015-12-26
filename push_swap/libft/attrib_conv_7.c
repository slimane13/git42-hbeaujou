/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 14:17:49 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/21 14:49:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_u_j(char **str, t_var **var, int count[3])
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
	nbr = ft_nbrlen(var[count[2]]->u_l_long);
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

void	attrib_o_j(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_l_long);
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long, "01234567");
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

void	attrib_d_z(char **str, t_var **var, int count[3])
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
	nbr = ft_nbrlen(var[count[2]]->v_l_long);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (flag == 3500)
		check_double = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = ft_ntoa_base(var[count[2]]->v_l_long, "0123456789");
	if (str[count[0]][0] != '0')
		neg = 1;
	if (flag == 1000)
	{
		neg = 1;
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	}
	else if (flag == 3500)
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
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 4000)
	{
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
			while (k < flag - nbr - neg)
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
			while (k < flag - nbr - neg)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}

void	attrib_u_z(char **str, t_var **var, int count[3])
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
	nbr = ft_nbrlen(var[count[2]]->u_l_long);
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

void	attrib_o_z(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_l_long);
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long, "01234567");
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
