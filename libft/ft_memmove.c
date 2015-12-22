/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:20:21 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 16:45:43 by dbousque         ###   ########.fr       */
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
