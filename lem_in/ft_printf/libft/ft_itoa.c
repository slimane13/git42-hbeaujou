/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:14:15 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:14:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_array(int n, int *length)
{
	int		signe;
	char	*res;

	*length = 0;
	signe = 1;
	if (n == 0)
		*length = 1;
	if (n < 0)
	{
		*length = 1;
		signe = -1;
	}
	while (n != 0)
	{
		n /= 10;
		(*length)++;
	}
	if (!(res = (char*)malloc(sizeof(char) * (*length + 1))))
		return (NULL);
	if (signe == -1)
		res[0] = '-';
	else
		res[0] = '0';
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		length;

	res = ft_get_array(n, &length);
	if (res == NULL)
		return (NULL);
	res[length] = '\0';
	length--;
	while (length >= 0)
	{
		if (length != 0 || res[length] != '-')
		{
			if (n < 0)
				res[length] = -(n % 10) + '0';
			else
				res[length] = n % 10 + '0';
		}
		n /= 10;
		length--;
	}
	return (res);
}
