/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:20:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:20:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = start;
	while (i < start + (int)len)
	{
		res[i - start] = s[i];
		i++;
	}
	res[i - start] = '\0';
	return (res);
}
