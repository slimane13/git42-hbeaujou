/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:16:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 21:16:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	val;
	int				i;

	val = (unsigned char)c;
	str = (unsigned char*)b;
	i = 0;
	while (i < (int)len)
	{
		str[i] = val;
		i++;
	}
	return (b);
}
