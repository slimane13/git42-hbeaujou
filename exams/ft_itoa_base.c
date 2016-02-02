/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:52:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/26 09:38:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int a, int base)
{
	char	basec[16] = "0123456789ABCDEF";
	char	*res;
	int		b;
	int		i;

	i = 0;
	b = a;
	if (base == 0)
		return (NULL);
	while (a != 0)
	{
		a = a / base;
		i++;
	}
	res = (char *)malloc(sizeof(char) * i + 1);
	if (b == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res[i] = '\0';
	i--;
	while (b != 0)
	{
		res[i] = basec[b % base];
		b = b / base;
		i--;
	}
	return (res);
}

int	main(void)
{
	int	a = 1423;

	printf("%s\n", ft_itoa_base(a, 2));
	return (0);
}
