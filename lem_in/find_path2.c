/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:54:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 17:33:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*find_shortest(t_map **tmp)
{
	t_map	*ret;
	t_tun	*tmp2;
	int		nb_fe;
	int		min;

	min = 1000000;
	nb_fe = 0;
	tmp2 = (*tmp)->room->next;
	while (tmp2)
	{
		if ((tmp2->p_map->room->from_end < min) &&
				(tmp2->p_map->room->start != 1) &&
				(tmp2->p_map->room->flag == 0))
		{
			ret = tmp2->p_map;
			min = tmp2->p_map->room->from_end;
		}
		else
			;
		tmp2 = tmp2->next;
	}
	return (ret);
}

void	clean_flag(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		tmp->room->flag = 0;
		tmp = tmp->next;
	}
}

void	path_to_flag(t_path **path, t_map **map, int choix)
{
	t_path	*tmp;
	t_map	*tmp2;

	tmp = *path;
	while (tmp)
	{
		tmp2 = *map;
		while (tmp2)
		{
			if (ft_strcmp(tmp2->room->name, tmp->name) == 0)
				tmp2->room->flag = choix;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
