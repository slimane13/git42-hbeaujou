/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 12:46:44 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 13:32:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_rr(int *l_a, int *l_b)
{
	int ret;

	RR;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	RRR;
	return (ret);
}

int	test_rrr(int *l_a, int *l_b)
{
	int ret;

	RRR;
	ret = nb_classed(l_a);
	ret = ret + nb_classed(l_b);
	RR;
	return (ret);
}

int		nb_classed_rev(int *tab)
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
			if (tab[i] > tab[j])
				ret = ret + j - i;
			else
				;
			j++;
		}
		i++;
	}
	return (ret);
}

void	apply_test(int ret, int *l_a, int *l_b)
{
	if (ret == 1)
		RA;
	else if (ret == 2)
		RRA;
	else if (ret == 3)
		RB;
	else if (ret == 4)
		RRB;
	else if (ret == 5)
		SA;
	else if (ret == 6)
		SB;
	else if (ret == 7)
		SS;
	else if (ret == 8)
		RR;
	else if (ret == 9)
		RRR;
	else
		;
}
