/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:18:48 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:18:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	int		length;

	i = 0;
	j = 0;
	while (dst[i] && i < (int)size)
		i++;
	length = i;
	if (length == (int)size)
		return (length + ft_strlen(src));
	while (src[j] && j + i + 1 < (int)size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (length + ft_strlen(src));
}
