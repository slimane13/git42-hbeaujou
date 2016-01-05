/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 15:29:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 12:36:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		apply_start(char *line, t_map **map)
{
	t_map	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_map(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->room->start = 1;
	room->room->end = 0;
	if (g_nb == 0)
	{
		g_nb = 1;
		(*map) = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_end(char *line, t_map **map)
{
	t_map	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_map(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->room->start = 0;
	room->room->end = 1;
	if (g_nb == 0)
	{
		g_nb = 1;
		(*map) = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_map(char *line, t_map **map)
{
	t_map	*room;
	char	**str;

	str = ft_strsplit(line, ' ');
	if (!(room = new_map(str[0], ft_atoi(str[1]), ft_atoi(str[2]))))
		return (0);
	room->room->start = 0;
	room->room->end = 0;
	if (g_nb == 0)
	{
		g_nb = 1;
		(*map) = room;
	}
	else
		ft_lstaddend_room(map, room);
	return (1);
}

int		apply_name(t_map *tmp, char *str, char *str2)
{
	t_tun	*tun;
	
	if (!(tun = new_tun(str2)))
		return (0);
	while (ft_strcmp(tmp->room->name, str) != 0)
		tmp=tmp->next;
	if (tmp->room->next == NULL)
		tmp->room->next = tun;
	else
		ft_lstaddend_tun(&(tmp->room->next), tun);
	return (1);
}

int		apply_tunnel(char *line, t_map **map)
{
	char	**str;
	t_map	*tmp;
	
	str = ft_strsplit(line, '-');
	tmp = *map;
	if (apply_name(tmp, str[0], str[1]) == 0)
		return (0);
	tmp = *map;
	if (apply_name(tmp, str[1], str[0]) == 0)
		return (0);
	return (1);
}
