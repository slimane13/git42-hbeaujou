/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:20:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 11:00:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char **str, int count[3], int *nbr, char *c)
{
	if ((str[count[0]][0] == '-' && str[count[0]][1] == '+') ||
			(str[count[0]][0] == '+' && str[count[0]][1] == '-'))
	{
		*nbr = *nbr + 1;
		return (4000);
	}
	else if (str[count[0]][0] == '0' && str[count[0]][1] == '-')
	{
		*nbr = *nbr + 1;
		return (4500);
	}
	else if ((ft_isdigit(str[count[0]][0]) && str[count[0]][1] == '.') ||
			(ft_isdigit(str[count[0]][0]) && ft_isdigit(str[count[0]][1]) &&
			 str[count[0]][2] == '.'))
		return (3500);
	else if ((str[count[0]][0] == '+' && str[count[0]][1] != '0') ||
			(str[count[0]][0] == ' ' && str[count[0]][1] == '+'))
	{
		*nbr = *nbr + 1;
		return (1000);
	}
	else if (str[count[0]][0] == '+' && str[count[0]][1] == '0')
	{
		*nbr = *nbr + 1;
		return (1500);
	}
	else if (str[count[0]][0] == ' ' && str[count[0]][1] == '0')
	{
		*nbr = *nbr + 1;
		return (2500);
	}
	else if (str[count[0]][0] == ' ' && str[count[0]][1] != '+')
	{
		*nbr = *nbr + 1;
		return (2000);
	}
	else if (str[count[0]][0] == '*')
	{
		*nbr = *nbr + 1;
		return (3000);
	}
	else if (str[count[0]][0] == '#')
	{
		if (str[count[0]][1] == '.')
			*c = '.';
		*nbr = *nbr + 1;
		return (5000);
	}
	else
		return (check_flag_number(str, count, nbr, c));
	return (-1);
}

void	attrib_d(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init(&t_v, var, str, count);
	if (t_v.flag == 1000 || t_v.flag == 4500 || t_v.flag == 2500)
		ft_cut_flag_d1(&t_v, var, str, count);
	else if (t_v.flag == 1500)
		ft_cut_flag_d2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_d3(&t_v, var, str, count);
	else if (t_v.flag == 2000 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	else if (t_v.flag == 4000)
	{
		if (var[count[2]]->entier >= 0)
			str[count[0]] = ft_strjoin("+", str[count[0]]);
		while (t_v.k < t_v.check - t_v.nbr)
		{
			str[count[0]] = ft_strjoin(str[count[0]], " ");
			t_v.k++;
		}
	}
	else if (t_v.flag == 3000)
	{
		if (var[count[2]]->stars < 0)
		{
			while (t_v.k > var[count[2]]->stars + t_v.nbr - 1)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				t_v.k--;
			}
		}
		else
		{
			while (t_v.k < var[count[2]]->stars - t_v.nbr + 1)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				t_v.k++;
			}
		}
	}
	else if (t_v.flag == 0 && t_v.c == '.')
		str[count[0]][0] = '\0';
	else if (t_v.flag != 1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3000 && t_v.flag != 4000 && t_v.flag != 3500 && t_v.flag != 5000)
	{
		if (t_v.flag < -1 && t_v.c != '0')
		{
			while (t_v.k > t_v.flag + t_v.nbr + t_v.neg)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				t_v.k--;
			}
		}
		else if (t_v.flag > 0 && (t_v.c == '0' || t_v.c == '.'))
		{
			if (var[count[2]]->entier < 0)
				str[count[0]] = ft_strsub(str[count[0]], 1, ft_nbrlen(var[count[2]]->entier) + 1);
			while (t_v.k < t_v.flag - t_v.nbr - t_v.neg)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				t_v.k++;
			}
			if (var[count[2]]->entier < 0)
				str[count[0]] = ft_strjoin("-", str[count[0]]);
		}
		else if (t_v.flag < -1 && t_v.c == '0')
		{
			while (t_v.k > t_v.flag)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				t_v.k--;
			}
		}
		else
		{
			while (t_v.k < t_v.flag - t_v.nbr - t_v.neg)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				t_v.k++;
			}
		}
	}
	count[2]++;
}

void	attrib_c(char **str, t_var **var, int count[3])
{
	int flag;
	int k;
	int nbr;
	int check;
	int check_double;
	int p;
	int diff;
	char c;

	k = 0;
	nbr = 0;
	c = 't';
	diff = 0;
	p = 1;
	check = ft_atoi(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	flag = check_flag(str, count, &nbr, &c);
	if (ft_atoi(var[count[2]]->string) == 0)
		rajout = 1;
	str[count[0]] = (char *)malloc(sizeof(char) * 2);
	str[count[0]][0] = ft_atoi(var[count[2]]->string);
	str[count[0]][1] = '\0';
	if (ft_atoi(var[count[2]]->string) == 0)
		char_nul = count[0];
	if (flag == 1000 && ft_atoi(var[count[2]]->string) > 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 2000 && var[count[2]]->entier >= 0)
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
			k = 0;
			while (k < check - diff - 1)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
	}
	else if (flag != -1 && flag != 1000 && flag != 2000 && flag != 3500 &&
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
	if (ft_atoi(var[count[2]]->string) == 0 && c == '.')
		str[count[0]][0] = '\0';
	count[2]++;
}

void	attrib_s(char **str, t_var **var, int count[3])
{
	int str_len;
	int flag;
	int k;
	int diff;
	int check;
	int check_double;
	char c;
	char z;

	k = 0;
	diff = 0;
	c = 't';
	z = 'o';
	str_len = 7;
	check = ft_atoi_ultra(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	flag = check_flag(str, count, &str_len, &c);
	if (str[count[0]][0] == '.' || str[count[0]][1] == '.' ||
			str[count[0]][2] == '.')
		c = '.';
	if (str[count[0]][0] == '0')
		z = '0';
	if (var[count[2]]->string == NULL && c != '.')
		flag = -1;
	if (var[count[2]]->string != NULL)
		str_len = ft_strlen(var[count[2]]->string);
	str[count[0]] = (char *)malloc(sizeof(char) * str_len);
	if (var[count[2]]->string != NULL)
		str[count[0]] = ft_strcpy(str[count[0]], var[count[2]]->string);
	if (flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (flag == 3500)
	{
		if (check_double < str_len)
			str[count[0]] = ft_strsub(str[count[0]], 0, check_double);
		str_len = ft_strlen(str[count[0]]);
		if (check_double >= str_len)
			diff = check_double;
		else
			diff = str_len;
		if (check < check_double)
			check_double = check;
		while (k < check_double - str_len)
		{
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
		k = 0;
		while (k < check - diff)
		{
			if (z == '0')
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			else
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
	}
	else if (flag != 0 && flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000 && flag != 3500)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + str_len)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag == 0 && c == '.')
			str[count[0]][0] = '\0';
		else if (flag > 0 && c == '.')
		{
			if (flag < 0)
				flag = -flag;
			str[count[0]] = ft_strsub(str[count[0]], 0, flag);
		}
		else if (c == '0')
		{
			while (k < flag - str_len)
			{
				str[count[0]] = ft_strjoin("0", str[count[0]]);
				k++;
			}
		}
		else
		{
			while (k < flag - str_len)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}
