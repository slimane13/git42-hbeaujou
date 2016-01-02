/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 18:15:56 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 18:15:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_ra_only(int *l_a)
{
	int ret;

	RA;
	ret = nb_classed(l_a);
	RRA;
	return (ret);
}

int	test_rra_only(int *l_a)
{
	int ret;

	RRA;
	ret = nb_classed(l_a);
	RA;
	return (ret);
}

int	test_sa_only(int *l_a)
{
	int ret;

	SA;
	ret = nb_classed(l_a);
	SA;
	return (ret);
}

int		attrib_tests_onlya(int *tab)
{
	if (find_max_iter(tab) == 0)
		return (1);
	else if (find_max_iter(tab) == 1)
		return (2);
	else if (find_max_iter(tab) == 4)
		return (5);
	else if (find_max_iter(tab) == 9)
		return (10);
	return (0);
}
