/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:15:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:15:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_b;
	unsigned char	*src_b;
	unsigned char	car;
	int				i;

	if (dst == NULL || src == NULL || n == 0)
		return (NULL);
	dst_b = (unsigned char*)dst;
	src_b = (unsigned char*)src;
	car = (unsigned char)c;
	i = 0;
	while (i < (int)n)
	{
		dst_b[i] = src_b[i];
		if (dst_b[i] == car)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
