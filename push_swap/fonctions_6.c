/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 10:23:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 18:16:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_ss(int *l_a, int *l_b)
{
	int ret;

	SS;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
	SS;
	return (ret);
}

// A METTRE DANS LIBFTPRINTF
int	tab_len(int *tab)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i++);
}

int	find_max_2(int *tab, int min)
{
	int i;
	int min2;

	min2 = 1000000;
	i = 0;
	while (tab[i] != 0 && tab[i] != '\0')
	{
		if (tab[i] < min2 && tab[i] != min)
			min2 = tab[i];
		i++;
	}
	return (min2);
}

void	do_tests_onlya(int *tab, int *l_a)
{
	tab[0] = test_ra_only(l_a);
	tab[1] = test_rra_only(l_a);
	tab[4] = test_sa_only(l_a);
	tab[2] = 0;
	tab[3] = 0;
	tab[5] = 0;
	tab[6] = 0;
	tab[7] = 0;
	tab[8] = 0;
	tab[9] = nb_classed(l_a);
}

void	do_tests(int *tab, int *l_a, int *l_b)//, int count)
{
	tab[0] = test_ra(l_a, l_b);
	tab[1] = test_rra(l_a, l_b);
	tab[4] = test_sa(l_a, l_b);
	tab[2] = test_rb(l_a, l_b);
	tab[3] = test_rrb(l_a, l_b);
	tab[5] = test_sb(l_a, l_b);
	tab[6] = test_ss(l_a, l_b);
	tab[7] = test_rr(l_a, l_b);
	tab[8] = test_rrr(l_a, l_b);
	tab[9] = nb_classed(l_a) + nb_classed_rev(l_b);
}

int		attrib_tests(int *tab)
{
	printf("\n%d\n", find_max_iter(tab));
	if (find_max_iter(tab) == 0)
		return (1);
	else if (find_max_iter(tab) == 1)
		return (2);
	else if (find_max_iter(tab) == 2)
		return (3);
	else if (find_max_iter(tab) == 3)
		return (4);
	else if (find_max_iter(tab) == 4)
		return (5);
	else if (find_max_iter(tab) == 5)
		return (6);
	else if (find_max_iter(tab) == 6)
		return (7);
	else if (find_max_iter(tab) == 7)
		return (8);
	else if (find_max_iter(tab) == 8)
		return (9);
	else if (find_max_iter(tab) == 9)
		return (10);
	return (0);
}
