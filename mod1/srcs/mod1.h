/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:22:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/04/09 21:19:29 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 30

typedef struct s_point	t_point;

struct	s_point
{
	int		x;
	int		y;
	float		z;
	t_point	*next;
};

void	map_to_list(float **map, t_point **points);
void	init_map(float **map);
void	put_in_map(float **map, char **argv);
void	apply_point_to_map(char *sub, float **map);
void	lst_addend_point(t_point **alst, t_point *new_r);

t_point	*new_point(int cx, int cy, float cz);

char    *ft_strsub_slim(char const *s, unsigned int start, size_t len);
