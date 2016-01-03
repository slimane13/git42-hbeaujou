/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 16:13:36 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/03 16:16:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_cut_1(t_stack *l_a)
{
	rev_rotate(&l_a);
	ft_printf("RRA ");
	g_coups++;
	rev_rotate(&l_a);
	ft_printf("RRA ");
	g_coups++;
	swap(&l_a);
	ft_printf("SA ");
	g_coups++;
	rotate(&l_a);
	ft_printf("RA ");
	g_coups++;
	rotate(&l_a);
	ft_printf("RA ");
	g_coups++;
}
