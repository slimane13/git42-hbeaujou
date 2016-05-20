/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:08:01 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:08:02 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned int	i;
	void			*memory;
	char			*current;

	i = 0;
	memory = (void *)malloc(sizeof(char *) * size);
	current = (char *)memory;
	if (memory == NULL)
		return (NULL);
	else
	{
		while (i++ < size)
		{
			current[i] = 0;
		}
	}
	return (memory);
}
