/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_spec_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:13:00 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:13:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_valid(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int			ft_atoi_spec_o(const char *str)
{
	int		res;
	int		i;
	int		signe;

	i = 0;
	res = 0;
	signe = 1;
	while (ft_is_valid(str[i]) || str[i] == ' ')
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
