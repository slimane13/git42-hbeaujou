/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 10:46:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/17 14:38:54 by hbeaujou         ###   ########.fr       */
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
	if (flag == 1000 && var[count[2]]->entier >= 0)
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
	str[count[0]] = (char *)malloc(sizeof(char) * 2);
	str[count[0]][0] = ft_atoi(var[count[2]]->string);
	str[count[0]][1] = '\0';
	if (flag == 1000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000)
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
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}

void	attrib_u(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	char c;
	int k;
	int check;
	int neg;

	k = 0;
	c = 't';
	neg = 0;
	nbr = ft_nbrlen(var[count[2]]->u_entier);
	flag = check_flag(str, count, &nbr, &c);
	check = ft_atoi_ultra(str[count[0]]);
	if (str[count[0]][0] == '.')
		nbr--;
	str[count[0]] = (char *)malloc(sizeof(char) * (nbr * 5));
	ft_ulltstr_base((unsigned long long)var[count[2]]->u_entier, "0123456789", str[count[0]]);
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
			flag != 3000 && flag != 5000)
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
