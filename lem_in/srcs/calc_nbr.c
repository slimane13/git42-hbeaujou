/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 18:18:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 09:16:56 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		nbr_path_end(t_map **map)
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

int		nbr_path_start(t_map **map)
{
	int		count;
	t_map	*tmp;
	t_tun	*tmp_t;

	tmp = *map;
	count = 0;
	while (tmp && tmp->room->start != 1)
		tmp = tmp->next;
	if (tmp->room->start != 1)
		exit(0);
	tmp_t = tmp->room->next;
	while (tmp_t)
	{
		count++;
		tmp_t = tmp_t->next;
	}
	return (count);
}

int		nbr_path(t_map **map)
{
	int start;
	int end;
	int res;

	res = 0;
	start = nbr_path_start(map);
	end = nbr_path_end(map);
	if (start < end)
		res = start;
	else
		res = end;
	return (res);
}

int		calc_path_n(t_reseau **res)
{
	t_reseau	*tmp;
	int			count;

	count = 0;
	tmp = *res;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
