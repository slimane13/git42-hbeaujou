/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:08:15 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:08:16 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	size_t		i;
	char		*cast_dst;
	char const	*cast_src;

	cast_dst = (char *)dst;
	cast_src = (char const *)src;
	i = 0;
	while (i < n && (i == 0 || cast_src[i - 1] != c))
	{
		cast_dst[i] = cast_src[i];
		i++;
	}
	if (i > 0 && cast_src[i - 1] == c)
		return (cast_dst + i);
	else
		return (NULL);
}
