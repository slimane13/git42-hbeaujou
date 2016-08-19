/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 13:07:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/08/19 13:07:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_malloc.h>

void				*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*p_dst;
	char			*p_src;
	size_t			k;

	if (!dst || !src || !len)
		return (dst);
	p_dst = (char*)dst;
	p_src = (char*)src;
	k = 0;
	while (k < len)
	{
		p_dst[k] = p_src[k];
		k++;
	}
	return (dst);
}
