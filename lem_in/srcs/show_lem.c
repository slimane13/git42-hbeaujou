/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:58:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 18:27:19 by hbeaujou         ###   ########.fr       */
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
	int			i;

	tmp = *res;
	i = 1;
	while (tmp && i < nb)
	{
		tmp = tmp->next;
		i++;
	}
	tmp2 = tmp->path;
	tmp2 = tmp2->next;
	while (tmp2)
	{
		if (tmp2->ant != 0)
			ft_printf("L%d-%s ", tmp2->ant, tmp2->name);
		tmp2 = tmp2->next;
	}
}

void	avance_lem(t_reseau **res, int *i, int nb_path)
{
	t_reseau	*tmp;
	t_path		*tmp2;
	int			save;

	save = 0;
	tmp = *res;
	while (tmp)
	{
		tmp2 = tmp->path;
		while (tmp2->next)
			tmp2 = tmp2->next;
		save = tmp2->ant;
		////////////////// ESSAI DE FIN D AFFICHAGE /////////////////////////
		if (save == g_lem)
		{
			g_end_affiche = 1;
		}
		///////////////////////////////////////////////////////////////////
		while (tmp2->previous)
		{
			tmp2->ant = tmp2->previous->ant;
			tmp2 = tmp2->previous;
			if (tmp2->ant >= g_lem - nb_path)
				tmp2->ant = 0;
		}
		if (tmp2->ant == 0 || tmp2->ant == tmp2->next->ant)
		{
			if (*i <= g_lem)
				tmp2->ant = *i;
			*i = *i + 1;
		}
		tmp = tmp->next;
	}
}
