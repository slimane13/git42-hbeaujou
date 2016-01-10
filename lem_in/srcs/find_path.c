/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/10 18:33:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_fromend(t_map **map)
{
	t_map	*tmp;

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
}

t_path	*fromend_to_path(t_map **tmp)
{
	t_map		*tmp2;
	t_map		*tmp3;
	t_path		*path;
	t_path		*new;
	int			i;

	path = NULL;
	tmp3 = *tmp;
	tmp2 = NULL;
	i = 0;
	while (tmp3->room->end != 1 && i < g_nbr_rooms)
	{
		if (tmp3)
			cut_fromend_topath(&new, &tmp2, &tmp3, &path);
		tmp3 = tmp2;
		if (tmp3 == NULL)
			return (NULL);
		i++;
	}
	if (tmp3->room->end != 1)
		exit_prgm();
	new = new_path(tmp3->room->name);
	ft_lstaddend_path(&path, new);
	return (path);
}

void	build_first_reseau(t_reseau **reseau, t_map **map)
{
	t_reseau	*tmp4;
	t_map		*tmp;
	t_path		*path;

	put_fromend(map);
	clean_flag(map);
	tmp = *map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	path = fromend_to_path(&tmp);
	tmp4 = new_reseau(1, path);
	ft_lstaddend_reseau(reseau, tmp4);
	clean_flag(map);
	path_to_flag(&path, map, 1);
}

void	build_reseau(t_reseau **reseau, t_map **map, int count)
{
	t_reseau	*tmp4;
	t_map		*tmp;
	t_path		*path;

	tmp = *map;
	cut_build(reseau, map);
	tmp = *map;
	while (tmp->room->end != 1)
		tmp = tmp->next;
	tmp->room->flag = 0;
	tmp = *map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	path = fromend_to_path(&tmp);
	if (path)
	{
		tmp4 = new_reseau(count, path);
		ft_lstaddend_reseau(reseau, tmp4);
	}
	else
		g_end_affiche = 2;
}
