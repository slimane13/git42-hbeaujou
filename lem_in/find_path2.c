/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 14:54:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 16:17:51 by hbeaujou         ###   ########.fr       */
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
				(tmp2->p_map->room->start != 1))
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
