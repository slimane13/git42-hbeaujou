/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:12:30 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:12:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi_double(const char *str)
{
	int		res;
	int		i;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] != '.' && ft_isalpha(str[i]) == 0) &&
			((str[i] != '+' && ft_isalpha(str[i]) == 0) || i < 2))
		i++;
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
