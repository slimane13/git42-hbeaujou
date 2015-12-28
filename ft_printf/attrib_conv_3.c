/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:46:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/28 10:53:33 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_h_h(char **str, t_var **var, int count[3])
{
	int flag;
	int k;
	int nbr;
	char c;

	k = 0;
	nbr = 0;
	c = 'h';
	nbr = ft_nbrlen(var[count[2]]->entier);
	flag = check_flag(str, count, &nbr, &c);
	if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd')
	{
		str[count[0]] = (char *)malloc(sizeof(char) * nbr);
		str[count[0]] = ft_itoa(var[count[2]]->entier);
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o')
	{
		str[count[0]] = (char *)malloc(sizeof(char) * nbr);
		str[count[0]] = ft_itoa_base(var[count[2]]->entier, 8); /////    BROKEN
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x')
	{
		str[count[0]] = (char *)malloc(sizeof(char) * nbr);
		str[count[0]] = ft_itoa_base(var[count[2]]->entier, 16);
	}
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X')
	{
		str[count[0]] = (char *)malloc(sizeof(char) * nbr);
		str[count[0]] = ft_itoa_base_maj(var[count[2]]->entier, 16);
	}
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000 && var[count[2]]->entier > 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000)
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
				if (c == '.')
					str[count[0]] = ft_strjoin("0", str[count[0]]);
				else
					str[count[0]] = ft_strjoin(str[count[0]], "0");
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

void	attrib_c_maj(char **str, t_var **var, int count[3])
{
	int flag;
	int k;
	int nbr;
	char c;

	k = 0;
	nbr = 0;
	c = 't';
	flag = check_flag(str, count, &nbr, &c);
	if (var[count[2]]->w_entier == 0)
		rajout = 1;
	str[count[0]] = (char *)malloc(sizeof(char) * 10);
	utf8encode(str[count[0]], var[count[2]]->w_entier);
	if (var[count[2]]->w_entier == 0)
		char_nul = count[0];
	if (flag == 1000 && var[count[2]]->w_entier > 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->w_entier >= 0)
	{
	}
	else if (flag == 3000)
	{
		if (var[count[2]]->stars < 0)
		{
			while (k > var[count[2]]->stars + nbr)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < var[count[2]]->stars - nbr)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (c == '.')
	{
	}
	else if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000 && c != '.')
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + 1)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else
		{
			while (k < flag - 1)
			{
				if (c == '0')
					str[count[0]] = ft_strjoin("0", str[count[0]]);
				else
					str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	if (var[count[2]]->w_entier == 0 && c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_u(char **str, t_var **var, int count[3])
{
	int nbr;
	int s_nbr;
	int flag;
	int check_double;
	char c;
	int k;
	int diff;
	int p;
	int check;
	int neg;

	k = 0;
	c = 't';
	neg = 0;
	p = 1;
	diff = 0;
	nbr = ft_nbrlen(var[count[2]]->u_entier);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * (nbr * 5));
	ft_ulltstr_base((unsigned long long)var[count[2]]->u_entier, "0123456789", str[count[0]]);
	s_nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
	{
	}
	else if (flag == 2000)
	{
	}
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
	else if (flag == 3500)
	{
		if (check_double >= nbr)
			diff = check_double;
		else
			diff = nbr;
		if (var[count[2]]->entier < 0)
		{
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
			if (check < check_double)
				k = -1;
			while (k < check_double - nbr - 1)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
				p = 0;
			}
			str[count[0]] = ft_strjoin("-", str[count[0]]);
			while (p < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				p++;
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
			while (k < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag == 0 && c == '.')
		str[count[0]][0] = '\0';
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

void	attrib_o_maj(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int spec;
	int k;
	int l;
	int check;
	int check_double;
	int p;
	int diff;
	char c;

	k = 0;
	spec = 0;
	p = 1;
	diff = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->u_long);
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	check = ft_atoi(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_long, "01234567");
	nbr = ft_strlen(str[count[0]]);
	if (flag == 1000)
	{
	}
	else if (flag == 2000)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000)
	{
		if (c != '.')
			str[count[0]] = ft_strjoin("0", str[count[0]]);
		flag = l;
		spec = 1;
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
	else if (flag == 3500)
	{
		if (check_double >= nbr)
			diff = check_double;
		else
			diff = nbr;
		if (var[count[2]]->entier < 0)
		{
			str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
			if (check < check_double)
				k = -1;
			while (k < check_double - nbr - 1)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
				p = 0;
			}
			str[count[0]] = ft_strjoin("-", str[count[0]]);
			while (p < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				p++;
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
			while (k < check - diff)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	if (flag != 0 && flag != -1 && flag != 1000 && flag != 3500 &&
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
	else if (flag == 0 && c == '.' && spec == 0)
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
