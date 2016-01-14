/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:48:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/14 19:21:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		g_coups;
int		g_after_start;
int		g_begin_attrib_map;
int		g_begin_tunnel;
int		g_after_end;
int		g_nb;
int		g_lem;
int		g_end_affiche;
int		g_total;
int		g_catch_lem;
int		g_nbr_rooms;

void	nbr_rooms(t_map **map)
{
	t_map	*tmp;
	int		i;

	tmp = *map;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	g_nbr_rooms = i;
}

int		read_line(char *line)
{
	int test2;
	int test3;

	test2 = 0;
	test3 = 0;
	test2 = is_valid_coord(line);
	test3 = is_valid_tunnel(line);
	if (line[0] == ' ')
		return (0);
	else if (line[0] == '#' && line[1] != '#')
		return (2);
	else if (ft_strcmp(line, "##start") == 0 && g_after_start == 0)
		return (cut_read_1());
	else if (ft_strcmp(line, "##end") == 0 && g_after_end == 0)
		return (cut_read_2());
	else if (line[0] == '#' && line[1] == '#')
		return (2);
	else if (test2 == 1)
		return (cut_rajout(line));
	else if (test3 == 1)
		return (cut_read_4());
	else if (ft_isalldigit(line) == 1 && line[0] != '\n' && line[0] != '\0')
		return (cut_read_5());
	else
		return (0);
}

int		apply_line(char *line, t_map **map, int t_1)
{
	int		t_3;
	char	*line2;

	t_3 = 0;
	if (t_1 == 1)
		g_lem = ft_atoi(line);
	else if (t_1 == 2)
		;
	else if (t_1 == 3)
		return (cut_apply_line(&line2, &t_3, map));
	else if (t_1 == 4)
	{
		get_next_line(0, &line2);
		t_3 = read_line(line2);
		if (t_3 != 5)
			return (0);
		else
			return (apply_end(line2, map));
	}
	else if (t_1 == 5)
		return (apply_map(line, map));
	else if (t_1 == 6)
		return (apply_tunnel(line, map));
	return (1);
}

void	attrib_glob(void)
{
	g_coups = 0;
	g_nb = 0;
	g_lem = 0;
	g_total = 0;
	g_after_start = 0;
	g_after_end = 0;
	g_begin_attrib_map = 0;
	g_begin_tunnel = 0;
	g_end_affiche = 0;
	g_catch_lem = 0;
	g_nbr_rooms = 0;
}

void	read_map(t_map **map)
{
	int		t_1;
	int		t_2;
	char	*line;

	attrib_glob();
	while (1)
	{
		get_next_line(0, &line);
		t_1 = read_line(line);
		if (t_1 == 0)
			return ;
		else
			t_2 = apply_line(line, map, t_1);
		if (t_2 == 0)
			return ;
	}
}
