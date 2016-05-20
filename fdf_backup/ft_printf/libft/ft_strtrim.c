/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:20:49 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:20:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_first(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_find_last(char const *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i])
	{
		if (s[i] != '\t' && s[i] != '\n' && s[i] != ' ')
			return (i);
		i--;
	}
	return (-1);
}

char		*ft_strtrim(char const *s)
{
	int		first;
	int		last;
	char	*res;

	if (s == NULL)
		return (NULL);
	first = ft_find_first(s);
	if (first == -1)
	{
		if (!(res = (char*)malloc(sizeof(char) * 1)))
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	last = ft_find_last(s);
	return (ft_strsub(s, first, last - first + 1));
}
