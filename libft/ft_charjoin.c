/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 20:38:20 by dbousque          #+#    #+#             */
/*   Updated: 2015/12/30 14:27:07 by hbeaujou         ###   ########.fr       */
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
