/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_map_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 14:46:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_map	*return_map_adr(t_map **map, char *str)
{
	t_map	*tmp;

	tmp = *map;
	while (tmp)
	{
		if (ft_strcmp(tmp->room->name, str) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	apply_map_to_tun(t_map **map)
{
	t_map	*tmp_m;
	t_tun	*tmp_t;
	tmp_m = *map;
	while (tmp_m)
	{
		tmp_t = tmp_m->room->next;
		if (tmp_t)
		{
			while (tmp_t)
			{
				if(!(tmp_t->p_map = return_map_adr(map, tmp_t->name)))
					exit(0);
				tmp_t = tmp_t->next;
			}
		}
		tmp_m = tmp_m->next;
	}
}
