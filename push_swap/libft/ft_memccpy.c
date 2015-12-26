/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:16:37 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 15:58:46 by dbousque         ###   ########.fr       */
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
