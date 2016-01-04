/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:29:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 16:21:00 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*new_room(char *str, int cx, int cy)
{
	t_room *res;

	if (!(res = malloc(sizeof(t_room))))
		return (NULL);
	res->name = ft_strdup(str);
	res->x = cx;
	res->y = cy;
	return (res);
}

int		apply_start(char *line, t_room **map)
{
	t_room	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_room(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->t_previous = NULL;
	room->t_nexts = NULL;
	*map = room;

	return (1);
}

int		apply_end(char *line, t_room **map)
{
	return (0);
}

int		apply_map(char *line, t_room **map)
{
	return (0);
}

int		apply_tunnel(char *line, t_room **map)
{
	return (0);
}
