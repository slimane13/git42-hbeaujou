/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:48:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 13:12:17 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_line(char *line)
{
	int i;

	i = 0;
}

int		apply_line(char *line, t_room *map)
{
}

void	read_map(void)
{
	int		t_1;
	int		t_2;
	char	*line;
	t_room	*map;

	while (read_line != 0 && apply_map != 0)
	{
		get_next_line(0, &line);
		t_1 = read_line(line);
		if (t_1 != 0)
			t_2 = apply_line(line, map, t_1);
	}
}
