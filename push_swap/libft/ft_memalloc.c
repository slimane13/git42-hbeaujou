/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 18:03:39 by dbousque          #+#    #+#             */
/*   Updated: 2015/11/25 16:45:24 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*res;
	unsigned char	*tmp;
	int				i;

	if (!(res = malloc(size)))
		return (NULL);
	i = 0;
	tmp = (unsigned char*)res;
	while (i < (int)size)
	{
		tmp[i] = 0;
		i++;
	}
	return (res);
}
