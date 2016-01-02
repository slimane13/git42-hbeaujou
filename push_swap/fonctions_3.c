/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:43:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:33:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	find_min(int *tab)
{
	int i;
	int min;

	min = 0;
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
	return (ret);
}

void resolve_test(int *l_a, int *l_b, int max)
{
	int tab[9]; // 0 = ra - 1 = rra - 2 = rb - 3 = rrb - 4 = sa - 5 = sb 6 = ss 7 = rr - 8 = rrr
	int ret;
	int min;
	int count;

	ret = 0;
	min = 0;
	count = 0;
	while (!ft_is_valid(l_a) && tab_len(l_a) >= tab_len (l_b))
	{
		min = find_min(l_a);
//		min2 = find_min2(l_a, min); A VOIR PAR LA SUITE
		if (l_a[0] == min)// || l_a[0] == min2) // CHECK TOUS LES MINS ?
		{
			PB;
			count++;
		}
		do_tests(tab, l_a, l_b);
		ret = attrib_tests(tab);
		apply_test(ret, l_a, l_b);
//		affiche(l_a, 8);
	}
	while (l_b[0] != 0)
		PA;
}
