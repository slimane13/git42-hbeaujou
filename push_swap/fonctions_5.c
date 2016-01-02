/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:15:22 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 15:18:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	test_rb(int *l_a, int *l_b)
{
	int ret;

	RB;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
	RRB;
	return (ret);
}

int	test_rrb(int *l_a, int *l_b)
{
	int ret;

	RRB;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
	RB;
	return (ret);
}

int	test_sb(int *l_a, int *l_b)
{
	int ret;

	SB;
	ret = nb_classed(l_a);
	ret = ret + nb_classed_rev(l_b);
	SB;
	return (ret);
}
