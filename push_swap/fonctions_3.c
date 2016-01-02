/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:43:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 18:12:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	find_min(int *tab)
{
	int i;
	int min;

	min = 100000;
	i = 0;
	while (tab[i] != 0 && tab[i] != '\0')
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	find_max(int *tab)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (tab[i] != 0 && tab[i] != '\0')
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	nb_classed(int *tab)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = 0;
	j = 0;
	while (tab[i + 1] != 0 && tab[i + 1] != '\0')
	{
		j = i + 1;
		while (tab[j + 1] != 0 && tab[j + 1] != '\0')
		{
			if (tab[i] < tab[j])
				ret = ret + j - i;
			else
				;
			j++;
		}
		i++;
	}
	i = 0;
	while (tab[i + 1] != 0 && tab[i + 1] != '\0')
	{
		if (tab[i] < tab[i + 1])
			ret++;
		i++;
	}
	return (ret);
}
