/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:29:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 17:07:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		apply_start(char *line, t_room **map)
{
	t_room	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_room(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->start = 1;
	room->end = 0;
	room->t_previous = NULL;
	room->t_nexts = NULL;
	if (g_nb == 0)
	{
		g_nb = 1;
		*map = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_end(char *line, t_room **map)
{
	t_room	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_room(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->start = 0;
	room->end = 1;
	room->t_previous = NULL;
	room->t_nexts = NULL;
	if (g_nb == 0)
	{
		g_nb = 1;
		*map = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_map(char *line, t_room **map)
{
	t_room	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_room(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->start = 0;
	room->end = 0;
	room->t_previous = NULL;
	room->t_nexts = NULL;
	if (g_nb == 0)
	{
		g_nb = 1;
		*map = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_tunnel(char *line, t_room **map)
{
	char	**str;
	char	*name1;
	char	*name2;

	return (0);
}
