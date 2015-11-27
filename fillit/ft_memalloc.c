/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:26:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/27 11:20:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_memalloc(size_t size)
{
	void	*memory;
	int		i;

	i = 0;
	if (!(memory = (int *)malloc(sizeof(int) * size)))
		return (NULL);
	return (memory);
}
