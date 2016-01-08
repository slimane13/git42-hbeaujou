/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ultra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:13:13 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:13:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_valid(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f' ||
			c == '%' || c == '{' || c == '}' || c == '+')
		return (1);
	return (0);
}

void		cut_atoi(int *res, char c)
{
	if (c != '+')
		*res = *res * 10 + (c - '0');
	else
		;
}

int			ft_atoi_ultra(const char *str)
{
	int		res;
	int		i;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_is_valid(str[i]) || str[i] == ' ' || str[i] == '0' ||
			str[i] == '#')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '+')
	{
		cut_atoi(&res, str[i]);
		i++;
	}
	if (signe == -1)
		res = -res;
	return (res);
}
