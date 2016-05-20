/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:21:35 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:21:36 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	counter;

	if (s == NULL)
		return (NULL);
	dest = ft_strnew(len + 1);
	counter = 0;
	if (dest == NULL)
		return (NULL);
	while (counter < len + start)
	{
		if (counter >= start)
			dest[counter - start] = s[counter];
		counter++;
	}
	return (dest);
}
