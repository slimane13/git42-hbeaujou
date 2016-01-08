/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:15:15 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:15:16 by hbeaujou         ###   ########.fr       */
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
