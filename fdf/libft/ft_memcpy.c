/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:08:56 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:08:57 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	char		*cast_dst;
	char const	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (char const *)src;
	while (n > 0)
	{
		cast_dst[n - 1] = cast_src[n - 1];
		n--;
	}
	return (dst);
}
