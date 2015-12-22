/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:49:34 by dbousque          #+#    #+#             */
/*   Updated: 2015/12/22 16:10:15 by hbeaujou         ###   ########.fr       */
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

int			ft_atoi_ultra(const char *str) //// A FAIRE
{
	int		res;
	int		i;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_is_valid(str[i]) || str[i] == ' ' || str[i] == '0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (signe == -1)
		res = -res;
	return (res);
}
