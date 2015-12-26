/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:27:48 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 12:41:18 by dbousque         ###   ########.fr       */
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
