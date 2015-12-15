/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:32:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/15 18:30:39 by hbeaujou         ###   ########.fr       */
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
	int nbr;
	int flag;
	int k;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	nbr = nbr + 2;
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa_base(var[count[2]]->entier, 16);
	nbr = ft_strlen(str[count[0]]);
	str[count[0]] = ft_strsub(str[count[0]], 2, nbr - 2);
	str[count[0]] = ft_strjoin("0x7fff", str[count[0]]);
	nbr = ft_strlen(str[count[0]]) + 2;
	count[2]++;
}

void	attrib_x(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	l = ft_atoi_spec_o(str[count[0]]);
	if (var[count[2]]->entier < 0)
		nbr++;
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa_base(var[count[2]]->entier, 16);
	if (flag == 1000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000 && var[count[2]]->entier >= 0)
	{
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
		flag = l;
		nbr++;
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
	if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 5000)
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

void	attrib_x_maj(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	if (var[count[2]]->entier < 0)
		nbr++;
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa_base_maj(var[count[2]]->entier, 16);
	if (flag == 1000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
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
	else if (flag != -1 && flag != 1000 &&
			flag != 2000 && flag != 5000)
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

void	attrib_o(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	int k;
	int l;
	char c;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	if (var[count[2]]->entier < 0)
		nbr++;
	flag = check_flag(str, count, &nbr, &c);
	l = ft_atoi_spec_o(str[count[0]]);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr * 2);
	str[count[0]] = ft_itoa_base(var[count[2]]->entier, 8);
	if (flag == 1000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (flag == 5000 && var[count[2]]->entier >= 0)
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
