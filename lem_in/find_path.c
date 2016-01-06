/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 18:52:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

t_reseau	*build_reseau(t_reseau **reseau)
{
	t_reseau	*res;
	t_path		*path;
///////////// REMPLIR PATH //////////////
	res = new_reseau(i, path);
	ft_lstaddend_reseau(reseau, res);
	return (res);
}
