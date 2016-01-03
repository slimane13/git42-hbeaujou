/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 12:03:27 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/03 12:03:28 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_is_error(char *str)
{
	int rt;

	rt = (str[0] == '\0' || (str[0] == '-' && str[1] == '\0')	\
		|| (str[0] == '-' && !ft_isdigit(str[1]))				\
		|| (str[0] != '-' && !ft_isdigit(str[0])));
	return (rt);
}

static	void	ft_is_negative(int *neg, char **str)
{
	if (**str == '-')
	{
		*neg = 1;
		(*str)++;
	}
	else
		*neg = 0;
}

int				ft_is_int(char *str)
{
	long	nb;
	int		neg;

	nb = 0;
	if (ft_is_error(str))
		return (0);
	ft_is_negative(&neg, &str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		nb = nb * 10 + *str - '0';
		if ((neg && -nb < INT_MIN) || (!neg && nb > INT_MAX))
			return (0);
		str++;
	}
	return (1);
}
