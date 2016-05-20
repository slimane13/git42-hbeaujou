/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:19:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:19:53 by hbeaujou         ###   ########.fr       */
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
