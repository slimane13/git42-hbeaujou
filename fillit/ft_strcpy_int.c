/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:25:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 08:36:13 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strcpy_int(int *dest, int *src, int taille)
{
	int i;

	i = 0;
	while (i < taille)
	{
		dest[i] = src[i];
		i++;
	}
}
