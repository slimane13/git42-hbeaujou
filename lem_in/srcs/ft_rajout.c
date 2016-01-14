/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:19:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/14 19:21:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		cut_rajout(char *line)
{
	if (line[0] == 'L')
		return (0);
	else
		return (cut_read_3());
}

void	cut_fromend_topath(t_path **new, t_map **tmp2,
		t_map **tmp3, t_path **path)
{
	*new = new_path((*tmp3)->room->name);
	ft_lstaddend_path(path, *new);
	*tmp2 = find_shortest(tmp3);
}

int		is_valid_coord(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return (0);
		if (ft_isdigit(line[i]) == 1 &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

int		cut_apply_line(char **line2, int *t_3, t_map **map)
{
	get_next_line(0, line2);
	*t_3 = read_line(*line2);
	if (*t_3 != 5)
		return (0);
	else
		return (apply_start(*line2, map));
}

void	cut_build(t_reseau **reseau, t_map **map)
{
	clean_from_end(map);
	clean_flag(map);
	reseau_to_flag(reseau, map);
	put_fromend(map);
	clean_flag(map);
	reseau_to_flag(reseau, map);
}
