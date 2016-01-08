/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:20:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:20:07 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	int		i;

	if (!(res = (char*)malloc(size + (sizeof(char) * 1))))
		return (NULL);
	i = 0;
	while (i <= (int)size)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
