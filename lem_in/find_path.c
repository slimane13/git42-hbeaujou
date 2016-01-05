/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:46:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 15:36:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		nbr_path(t_map **map)
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
/*
t_map	*find_path(t_map **map)
{

}*/
