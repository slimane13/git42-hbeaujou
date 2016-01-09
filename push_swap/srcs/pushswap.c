/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 10:59:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 15:40:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

int		g_coups;
int		g_total;
int		g_res;

void	resolve(t_stack *l_a, t_stack *l_b)
{
	while (l_a->next != l_a)
	{
		if ((l_a->next->nb > l_a->next->next->nb) &&
				(l_a->next->nb < l_a->next->next->next->nb))
			ft_c_c(l_a);
		else if ((l_a->prev->nb < l_a->prev->prev->nb) &&
				(l_a->prev->nb > l_a->prev->prev->prev->nb) &&
				(ft_lstlen(l_a) > 3))
			ft_cut_1(l_a);
		if (l_b->nb_elem == 0 && ft_is_sort(l_a))
			return ;
		resolve_rotate(l_a);
		if ((l_b->nb_elem == 0 && ft_is_sort(l_a)) ||
				(l_b->nb_elem != 0 && ft_is_sort(l_a) &&
				l_a->next->nb > l_b->next->nb))
			return ;
		push_a(&l_a, &l_b);
		ft_printf("PB ");
		g_coups++;
		if (l_b->nb_elem == 0 && ft_is_sort(l_a))
			return ;
	}
}

void	resolve_rotate(t_stack *l_a)
{
	int i;

	i = find_min(l_a);
	if (i > (l_a->nb_elem / 2) && (l_a->nb_elem) != 1)
		while (i++ < l_a->nb_elem)
		{
			rev_rotate(&l_a);
			ft_printf("RRA ");
			g_coups++;
		}
	else
	{
		while (i-- > 0)
		{
			rotate(&l_a);
			ft_printf("RA ");
			g_coups++;
		}
	}
}

void	resolve_stack_b(t_stack *l_a, t_stack *l_b)
{
	while (l_b->next != l_b)
	{
		if (push_b(&l_a, &l_b) == -1)
			return ;
		ft_printf("PA ");
		g_coups++;
	}
	ft_printf("\n");
}

int		initialize(t_stack **l_a, t_stack **l_b)
{
	if ((*l_a = (t_stack*)malloc(sizeof(**l_a))) == NULL)
	{
		ft_printf("malloc");
		return (-1);
	}
	(*l_a)->nb_elem = 0;
	(*l_a)->next = (*l_a);
	(*l_a)->prev = (*l_a);
	if ((*l_b = (t_stack *)malloc(sizeof(**l_b))) == NULL)
	{
		ft_printf("malloc");
		return (-1);
	}
	(*l_b)->nb_elem = 0;
	(*l_b)->next = (*l_b);
	(*l_b)->prev = (*l_b);
	return (0);
}

int		main(int ac, char **av)
{
	t_stack	*l_a;
	t_stack *l_b;

	g_coups = 0;
	g_total = 0;
	g_res = 0;
	if (ac < 2)
		return (0);
	if (initialize(&l_a, &l_b) == -1)
		return (-1);
	ft_check_3(av, ac, &l_a);
	if (ft_is_sort(l_a) == 1)
		ft_printf("\n");
	else
	{
		ft_printf("\n");
		resolve(l_a, l_b);
		resolve_stack_b(l_a, l_b);
	}
	if (g_total == 1)
		ft_printf("\nNombre de coups : %d\n\n", g_coups);
	if (g_res == 1)
		affiche(l_a);
	ft_printf("\n\n");
	return (0);
}
