/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:17:48 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:17:49 by hbeaujou         ###   ########.fr       */
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
