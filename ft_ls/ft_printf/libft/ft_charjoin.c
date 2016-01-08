/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:13:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:13:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_charjoin(char const *s1, char s2)
{
	int		length;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	length = ft_strlen(s1) + 1;
	if (!(res = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	length = 0;
	while (s1[length])
	{
		res[length] = s1[length];
		length++;
	}
	res[length] = s2;
	res[length + 1] = '\0';
	return (res);
}
