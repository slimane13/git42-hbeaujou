/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:20:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/12 17:24:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char **str, int count[3], int *nbr)
{
	if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (0);
	}
	else if (str[count[0]][0] == ' ')
	{
		*nbr = *nbr + 1;
		return (1);
	}
	else if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (2);
	}
	else if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (3);
	}
	else if (str[count[0]][0] == '+')
	{
		*nbr = *nbr + 1;
		return (4);
	}
	return (10);
}
void	attrib_alpha(char **str, t_var **var, int count[3])
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd')
		attrib_d(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c')
		attrib_c(str, var, count);
	else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 's')
		attrib_s(str, var, count);
}

void	attrib_d(char **str, t_var **var, int count[3])
{
	int nbr;
	int flag;

	nbr = ft_nbrlen(var[count[2]]->entier);
	flag = check_flag(str, count, &nbr);
	str[count[0]] = (char *)malloc(sizeof(char) * nbr);
	str[count[0]] = ft_itoa(var[count[2]]->entier);
	if (flag == 0 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin("+", str[count[0]]);
	else if (flag == 1 && var[count[2]]->entier >= 0)
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
	count[2]++;
}

void	attrib_c(char **str, t_var **var, int count[3])
{
	str[count[0]] = (char *)malloc(sizeof(char) * 2);
	str[count[0]][0] = ft_atoi(var[count[2]]->string);
	str[count[0]][1] = '\0';
	count[2]++;
}

void	attrib_s(char **str, t_var **var, int count[3])
{
	int str_len;

	str_len = ft_strlen(var[count[2]]->string);
	str[count[0]] = (char *)malloc(sizeof(char) * str_len);
	str[count[0]] = ft_strcpy(str[count[0]], var[count[2]]->string);
	count[2]++;
}
