/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:15:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:15:29 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	car;
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char*)s;
	car = (unsigned char)c;
	while (i < (int)n)
	{
		if (str[i] == car)
			return (str + i);
		i++;
	}
	return (NULL);
}
