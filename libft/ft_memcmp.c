/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:34:44 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/24 17:42:06 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (i < (int)n && c1[i] == c2[i])
		i++;
	if (i == (int)n)
		return (0);
	return (c1[i] - c2[i]);
}
