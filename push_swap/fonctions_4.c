/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:08:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:29:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_ra(int *l_a, int *l_b)
{
	int ret;

	RA;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	RRA;
	return (ret);
}

int	test_rra(int *l_a, int *l_b)
{
	int ret;

	RRA;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	RA;
	return (ret);
}

int	test_sa(int *l_a, int *l_b)
{
	int ret;

	SA;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	SA;
	return (ret);
}

int	find_min_iter(int *tab)
{
	int i;
	int j;
	int min;

	min = 10000;
	i = 0;
	j = 0;
	while (i < 9)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			j = i;
		}
		i++;
	}
	return (j + 1);
}
