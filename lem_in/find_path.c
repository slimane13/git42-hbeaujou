/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 16:23:14 by hbeaujou         ###   ########.fr       */
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
	put_fromend_recur(&tmp, 0);
}

void	put_fromend_recur(t_map **tmp, int coups)
{
	t_tun	*tmp2;

	tmp2 = (*tmp)->room->next;
	(*tmp)->room->flag = 1;
	(*tmp)->room->from_end = coups;
	ft_printf("salle : %s\n", (*tmp)->room->name);
	ft_printf("coups : %d\n", (*tmp)->room->from_end);
	ft_printf("tunnel : %s\n", tmp2->p_map->room->name);
	ft_printf("\n");
	while (tmp2 && tmp2->p_map->room->start != 1)
	{
		if (tmp2->p_map->room->flag == 0)
		{
			(*tmp) = tmp2->p_map;
			put_fromend_recur(tmp, coups + 1);
		}
		else
			tmp2 = tmp2->next;
	}
	if ((*tmp)->room->start == 1)
		(*tmp)->room->from_end = coups;
}

t_path	*fromend_to_path(t_map **tmp)
{
	t_map 	*tmp2;
	t_map 	*tmp3;
	t_path	*path;
	t_path	*new;

	path = NULL;
	tmp3 = *tmp;
	while (tmp3->room->end != 1)
	{
		new = new_path(tmp3->room->name);
		ft_lstaddend_path(&path, new);
		tmp2 = find_shortest(&tmp3);
		tmp3 = tmp2;
	}
	new = new_path(tmp3->room->name);
	ft_lstaddend_path(&path, new);
	return (path);
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
