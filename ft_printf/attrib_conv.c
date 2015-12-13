/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:20:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/13 16:10:56 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char **str, int count[3], int *nbr, char *c)
{
	if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (1000);
	}
	else if (str[count[0]][0] == ' ')
	{
		*nbr = *nbr + 1;
		return (2000);
	}
	else if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (3000);
	}
	else if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (4000);
	}
	else if (str[count[0]][0] == '#')
	{
		*nbr = *nbr + 1;
		*c = str[count[0]][1];  //////////////  EN COURS
		return (5000);
	}
	else
		return (check_flag_number(str, count, nbr, c));
	return (-1);
}
void	attrib_alpha(char **str, t_var **var, int count[3])
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd')
		attrib_d(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c')
		attrib_c(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 's')
		attrib_s(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'p')
		attrib_p(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x')
		attrib_x(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X')
		attrib_x_maj(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o')
		attrib_o(str, var, count);
}

void	attrib_d(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;
	char c;
	int k;

	k = 0;
	c = 't';
	nbr = ft_nbrlen(var[count[2]]->entier);
	flag = check_flag(str, count, &nbr, &c);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa(var[count[2]]->entier);
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

void	attrib_c(char **str, t_var **var, int count[3])
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

void	attrib_s(char **str, t_var **var, int count[3])
{
	int str_len;
	int flag;
	int k;
	char c;

	k = 0;
	c = 't';
	str_len = ft_strlen(var[count[2]]->string);
	flag = check_flag(str, count, &str_len, &c);
	str[count[0]] = (char *)malloc(sizeof(char) * str_len);
	str[count[0]] = ft_strcpy(str[count[0]], var[count[2]]->string);
	if (flag != -1 && flag != 1000 && flag != 2000 &&
			flag != 3000 && flag != 4000 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + str_len)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag > 0 && c == '.')
		{
			if (flag < 0)
				flag = -flag;
			str[count[0]] = ft_strsub(str[count[0]], 0, flag);
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
