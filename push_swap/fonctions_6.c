/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 10:23:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:35:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_ss(int *l_a, int *l_b)
{
	int ret;

	SS;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	SS;
	return (ret);
}

// A METTRE DANS LIBFTPRINTF
int	tab_len(int *tab)
{
	return (0);
}

int	find_min_2(int *tab, int min)
{
	int i;
	int min2;

	min2 = 0;
	i = 0;
	while (tab[i] != 0 && tab[i] != '\0')
	{
		if (tab[i] < min2 && tab[i] != min)
			min2 = tab[i];
		i++;
	}
	return (min2);
}

void	do_tests(int *tab, int *l_a, int *l_b)
{
	tab[0] = test_ra(l_a, l_b);
	tab[1] = test_rra(l_a, l_b);
	tab[4] = test_sa(l_a, l_b);
	if (count > 1)
	{
		tab[2] = test_rb(l_a, l_b);
		tab[3] = test_rrb(l_a, l_b);
		tab[5] = test_sb(l_a, l_b);
		tab[6] = test_ss(l_a, l_b);
		tab[7] = test_rr(l_a, l_b);
		tab[8] = test_rrr(l_a, l_b);
	}
/*	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);
	printf("%d\n", tab[5]);
	printf("%d\n", tab[6]);
	printf("%d\n", tab[7]);
	printf("%d\n", tab[8]);
	printf("\n\n");
	printf("%d\n", find_min_iter(tab));
	printf("\n\n");*/
}

int		attrib_tests(int *tab)
{
	if (find_min_iter(tab) == 0)
		return (1);
	else if (find_min_iter(tab) == 1)
		return (2);
	else if (find_min_iter(tab) == 2)
		return (3);
	else if (find_min_iter(tab) == 3)
		return (4);
	else if (find_min_iter(tab) == 4)
		return (5);
	else if (find_min_iter(tab) == 5)
		return (6);
	else if (find_min_iter(tab) == 6)
		return (7);
	else if (find_min_iter(tab) == 7)
		return (8);
	else if (find_min_iter(tab) == 8)
		return (9);
	return (0);
}
