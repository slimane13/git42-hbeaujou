/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:34:03 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/24 16:14:56 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (src[i] && i < (int)n)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
