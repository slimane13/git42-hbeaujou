/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:44:36 by ebouther          #+#    #+#             */
/*   Updated: 2015/11/27 17:22:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int	ft_nb_occur(char *line, int c, int *first_pos)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	*first_pos = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] == c)
		{
			if (*first_pos == 0)
				*first_pos = i;
			len++;
		}
		i++;
	}
	return (len);
}

static int	ft_fill_struct(t_map **map, int fd)
{	
	char	*line;
	int		last_pos;
	int		pos;
	
	pos = 0;
	while (get_next_line(fd, &line))
	{
		last_pos = pos;
		if (ft_strlen(line) > 0)
		{
			if (ft_nb_occur(line, '#', &pos) > (*map)->x)
				(*map)->x = ft_nb_occur(line, '#', &pos);
			if (ft_nb_occur(line, '#', &pos) > 0)
				(*map)->y++;
			if ((*map)->x == 2 && pos != last_pos)
				(*map)->x++;


		}
		else
		{
			if (!((*map)->nxt_map = (t_map *)malloc(sizeof(**map))))
				return (-1);
			(*map) = (*map)->nxt_map;
			(*map)->nxt_map = NULL;
			(*map)->x = 0;
			(*map)->y = 0;
		}
	}
	return (0);
}

t_map	*ft_get_maps(int fd)
{
	t_map	*map;
	t_map	*beg;

	if (fd < 0 || !(map = (t_map *)malloc(sizeof(*map))))
		return (NULL);
	beg = map;
	map->nxt_map = NULL;
	map->x = 0;
	map->y = 0;
	if (ft_fill_struct(&map, fd) == -1)
		return (NULL);
	return (beg);
}
