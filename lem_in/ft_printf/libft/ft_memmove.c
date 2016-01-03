/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:15:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:15:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_b;
	unsigned char	*src_b;
	unsigned char	*src_b_cpy;
	int				i;

	dst_b = (unsigned char*)dst;
	src_b = (unsigned char*)src;
	if (!(src_b_cpy = (unsigned char*)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		src_b_cpy[i] = src_b[i];
		i++;
	}
	i = 0;
	while (i < (int)len)
	{
		dst_b[i] = src_b_cpy[i];
		i++;
	}
	free(src_b_cpy);
	return (dst);
}
