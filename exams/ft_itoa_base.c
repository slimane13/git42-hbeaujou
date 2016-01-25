/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:52:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/25 15:03:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>



char	*ft_itoa_base(int a, int base)
{
	char	basec[16] = "0123456789ABCDEF";
	char	*res;
	int		tmp;
	int		b;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char));
	b = a;
	while (a != 0)
	{
		a = a / base;
		i++;
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
	int	a = 15;

	printf("%s\n", ft_itoa_base(a, 16));
	return (0);
}
