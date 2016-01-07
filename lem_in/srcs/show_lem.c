/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:58:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 16:40:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	next_to_previous(t_reseau **res)
{
	t_reseau *tmp;
	t_path	 *tmp2;
	t_path	 *tmp3;

	tmp = *res;
	while (tmp)
	{
		tmp2 = tmp->path;
		tmp3 = NULL;
		while (tmp2)
		{
			tmp2->previous = tmp3;
			tmp3= tmp2;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	affiche_path(int nb, t_reseau **res)
{
	t_reseau	*tmp;
	t_path		*tmp2;

	tmp = *res;
	while (tmp && tmp->choix != nb)
		tmp = tmp->next;
	tmp2 = tmp->path;
	while (tmp2->next->next)
	{
		if (tmp2->ant != 0)
			ft_printf("L%d-%s", tmp2->ant, tmp2->name);
		tmp2 = tmp2->next;
	}
}

void	avance_lem(t_reseau **res, int i)
{
	t_reseau	*tmp;
	t_path		*tmp2;
	int			save;

	save = 0;
	tmp = *res;
	while (tmp)
	{
		tmp2 = tmp->path;
		tmp2->ant = i;
		while (tmp2->next)
			tmp2 = tmp2->next;
		save = tmp2->ant;
		while (tmp2->previous->previous)
		{
			tmp2->ant = tmp2->previous->ant;
			tmp2 = tmp2->previous;
		}
		tmp = tmp->next;
	}
}
