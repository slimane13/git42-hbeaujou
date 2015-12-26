/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:34:40 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/23 17:59:13 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	car;
	int		i;

	car = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == car)
			return ((char*)s + i);
		i++;
	}
	if (car == '\0')
		return ((char*)s + i);
	return (NULL);
}
