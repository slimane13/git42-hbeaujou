/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 17:58:43 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/23 18:04:42 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	car;
	int		i;

	car = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == car)
			return ((char*)s + i);
		i--;
	}
	return (NULL);
}
