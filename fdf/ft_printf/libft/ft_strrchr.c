/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:20:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:20:19 by hbeaujou         ###   ########.fr       */
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
