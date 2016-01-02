/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 12:46:44 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 17:02:52 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_rr(int *l_a, int *l_b)
{
	int ret;

	RR;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
	RRR;
	return (ret);
}

int	test_rrr(int *l_a, int *l_b)
{
	int ret;

	RRR;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
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
	i = 0;
	while (tab[i + 1] != 0 && tab[i + 1] != '\0')
	{
		if (tab[i] > tab[i + 1])
			ret++;
		i++;
	}
	return (ret);
}

void	apply_test(int ret, int *l_a, int *l_b)
{
	if (ret == 1)
	{
		printf("RA ");
		RA;
	}
	else if (ret == 2)
	{
		printf("RRA ");
		RRA;
	}
	else if (ret == 3)
	{
		printf("RB ");
		RB;
	}
	else if (ret == 4)
	{
		printf("RRB ");
		RRB;
	}
	else if (ret == 5)
	{
		printf("SA ");
		SA;
	}
	else if (ret == 6)
	{
		printf("SB ");
		SB;
	}
	else if (ret == 7)
	{
		printf("SS ");
		SS;
	}
	else if (ret == 8)
	{
		printf("RR ");
		RR;
	}
	else if (ret == 9)
	{
		printf("RRR ");
		RRR;
	}
	else
		;
}
