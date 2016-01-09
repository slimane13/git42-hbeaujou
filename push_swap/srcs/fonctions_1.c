/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 11:18:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 14:59:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pushswap.h"

t_stack		*ft_creat_element(int nb)
{
	t_stack	*new;

	new = NULL;
	if ((new = (t_stack *)malloc(sizeof(*new))))
	{
		new->nb = nb;
		new->prev = NULL;
		new->next = NULL;
	}
	if (!(new))
		ft_printf("malloc fail");
	return (new);
}

int			ft_list_back(t_stack **stack, int nb)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *stack;
	new = ft_creat_element(nb);
	if (new)
	{
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev->next = new;
		tmp->prev = new;
		tmp->nb_elem = tmp->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int			ft_list_front(t_stack **stack, int nb)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *stack;
	new = ft_creat_element(nb);
	if (new)
	{
		new->prev = tmp;
		new->next = tmp->next;
		tmp->next->prev = new;
		tmp->next = new;
		tmp->nb_elem = tmp->nb_elem + 1;
		return (0);
	}
	return (-1);
}

int			ft_is_sort(t_stack *x)
{
	t_stack *tmp;

	tmp = x->next->next;
	while (tmp != x)
	{
		if ((tmp->prev->nb) > (tmp->nb))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			find_min(t_stack *a)
{
	t_stack	*tmp;
	int		min_max;
	int		i;
	int		pos;

	i = 0;
	tmp = a->next;
	min_max = tmp->nb;
	pos = 0;
	while (tmp != a)
	{
		if (tmp->nb < min_max)
		{
			min_max = tmp->nb;
			pos = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}
