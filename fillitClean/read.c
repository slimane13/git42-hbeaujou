/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouther <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:44:36 by ebouther          #+#    #+#             */
/*   Updated: 2015/12/09 14:24:02 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int	ft_new_struct(t_map **map, t_env *env, int tetriminos)
{
	ft_check_tetriminos(*map, tetriminos);
	(*map)->content = ft_strjoin((*map)->content, ft_add_to_map(tetriminos));
	env->nb_of_line = 0;
	env->last_pos = 0;
	if (!((*map)->nxt_map = (t_map *)malloc(sizeof(**map))))
		return (-1);
	(*map) = (*map)->nxt_map;
	(*map)->nxt_map = NULL;
	(*map)->x = 0;
	(*map)->y = 0;
	(*map)->content = ft_strnew(0);
	return (0);
}

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

static void	ft_getxy(t_map **map, t_env *env, char *line, int c)
{
	int			pos;
	int			nb;

	pos = 0;
	nb = ft_nb_occur(line, c, &pos);
	env->nb_of_line++;
	if (nb > (*map)->x)
		(*map)->x = nb;
	if (nb > 0)
		(*map)->y++;
	if (nb == 2 && env->last_x == 2 && env->last_pos != 0
			&& (pos != env->last_pos))
		(*map)->x++;
	env->last_x = (*map)->x;
	env->last_pos = pos;
}

static void	ft_fill_struct(t_map **map, int fd, int tetriminos)
{
	char	*line;
	t_env	env;
	int		i;
	int		j;

	j = 0;
	env.nb_of_line = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		if ((ft_strlen(line) != 4 && ft_strlen(line) != 0))
			ft_error_exit();
		if (ft_strlen(line) > 0)
		{
			(*map)->content = ft_strjoin(ft_strjoin((ft_strjoin((*map)->content, line)),
						(const char *)ft_add_to_line(tetriminos)), "\n");
			ft_getxy(map, &env, line, '#');
		}
		else if (env.nb_of_line != 4 || ft_new_struct(map, &env, tetriminos) == -1)
			ft_error_exit();
	}
	if (env.nb_of_line != 4)
		ft_error_exit();
	ft_check_tetriminos(*map, tetriminos);
	(*map)->content = ft_strjoin((*map)->content, ft_add_to_map(tetriminos));
}

t_map		*ft_get_maps(int fd, int tetriminos)
{
	t_map	*map;
	t_map	*beg;

	if (tetriminos > 2)
		tetriminos = (tetriminos * 2);
	if (fd < 0 || !(map = (t_map *)malloc(sizeof(*map))))
		ft_error_exit();
	beg = map;
	map->nxt_map = NULL;
	map->x = 0;
	map->y = 0;
	map->content = ft_strnew(0);
	ft_fill_struct(&map, fd, tetriminos);
	return (beg);
}
