/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:18:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/03 11:29:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void		swap(t_stack **stack)
{
	t_stack *tmp;

	tmp = (*stack)->next->next;
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->prev = (*stack);
	tmp->next = (*stack)->next;
	(*stack)->next->prev = tmp;
	(*stack)->next = tmp;
}

void		rotate(t_stack **stack)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->prev->next;
	(*stack)->prev->next = (*stack);
	(*stack)->next->prev = (*stack);
}

void		rev_rotate(t_stack **stack)
{
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = (*stack)->prev->prev;
	(*stack)->prev->next = (*stack);
	(*stack)->next->prev = (*stack);
}

int			push_b(t_stack **l_a, t_stack **l_b)
{
	t_stack *tmp;

	if ((ft_list_front(l_a, (*l_b)->next->nb)) == -1)
		return (-1);
	tmp = (*l_b)->next;
	(*l_b)->next = (*l_b)->next->next;
	(*l_b)->nb_elem = (*l_b)->nb_elem - 1;
	free(tmp);
	return (0);
}

int			push_a(t_stack **l_a, t_stack **l_b)
{
	t_stack *tmp;

	if ((ft_list_front(l_b, (*l_a)->next->nb)) == -1)
		return (-1);
	tmp = (*l_a)->next;
	(*l_a)->next = (*l_a)->next->next;
	(*l_a)->nb_elem = (*l_a)->nb_elem - 1;
	free(tmp);
	return (0);
}
