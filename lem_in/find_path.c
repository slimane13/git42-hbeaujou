/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 17:05:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			nbr_path(t_map **map)
{
	int		count;
	t_map	*tmp;
	t_tun	*tmp_t;

	tmp = *map;
	count = 0;
	while (tmp && tmp->room->end != 1)
		tmp = tmp->next;
	if (tmp->room->end != 1)
		exit(0);
	tmp_t = tmp->room->next;
	while (tmp_t)
	{
		count++;
		tmp_t = tmp_t->next;
	}
	return (count);
}


void	put_fromend(t_map **map)
{
	t_map	*tmp;
	int		coups;

	tmp = *map;
	while (tmp && tmp->room->end != 1)
		tmp = tmp->next;
	while (tmp && tmp->room->start != 1)
	{
		tmp->room->from_end = coups;
		coups++;
		tmp = tmp->room->next->p_map;
	}
	tmp->room->from_end = coups;
}
/*
t_reseau	*build_reseau(t_map **map, t_reseau **reseau)
{
	t_map		*tmp;
	t_path		*res;
	t_reseau	*fin;
	int			choix;

	choix = 1;
	fin = new_reseau(choix, NULL);
	res = new_path(tmp->room->name);
	tmp = *map;
	put_fromend(&tmp, &res);
	ft_lstaddend_reseau(&fin, new_reseau(choix, res));
	return (fin);
}*/
