/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:18:11 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:18:12 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(sizeof(char *) * size + 1);
	i = 0;
	if (str == NULL)
		return ((char *)NULL);
	else
	{
		while (i++ < size)
		{
			str[i] = 0;
		}
	}
	return ((char *)str);
}
