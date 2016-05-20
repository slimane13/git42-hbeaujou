/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:17:41 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:17:42 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	unsigned int i;

	i = ft_strlen(src);
	if (i < n)
	{
		dest = ft_memcpy(dest, src, n);
		while (i < n)
		{
			dest[i] = 0;
			i++;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
