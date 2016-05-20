/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 23:15:14 by sksourou          #+#    #+#             */
/*   Updated: 2015/01/26 23:15:15 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				i;
	int				len;
	unsigned int	index;

	if (s != NULL && f != NULL)
	{
		i = 0;
		index = 0;
		len = ft_strlen(s);
		while (i < len)
		{
			(*f)(index, s);
			s++;
			i++;
			index++;
		}
	}
}
