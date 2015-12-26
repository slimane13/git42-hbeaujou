/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:13:30 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 16:43:43 by dbousque         ###   ########.fr       */
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
