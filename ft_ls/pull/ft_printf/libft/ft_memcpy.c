/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:15:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:15:42 by hbeaujou         ###   ########.fr       */
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
