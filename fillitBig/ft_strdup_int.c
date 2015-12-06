/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:25:54 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 08:43:59 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*ft_strdup_int(int *s, int taille)
{
	int *d;

	d = ft_memalloc(taille);
	if (d != NULL)
		ft_strcpy_int(d, s, 4);
	return (d);
}
