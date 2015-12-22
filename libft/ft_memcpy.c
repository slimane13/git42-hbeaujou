/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:12:16 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 12:40:18 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_b;
	unsigned char	*src_b;
	int				i;

	dst_b = (unsigned char*)dst;
	src_b = (unsigned char*)src;
	i = 0;
	while (i < (int)n)
	{
		dst_b[i] = src_b[i];
		i++;
	}
	return (dst);
}
