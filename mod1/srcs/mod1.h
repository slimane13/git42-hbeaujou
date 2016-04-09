/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:22:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/04/09 18:58:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 30
#define WINDOW_HEIGHT 30

void	init_map(float **map);
void	put_in_map(float **map, char **argv);
void	apply_point_to_map(char *sub, float **map);
void	check_around_point(float **map);

char    *ft_strsub_slim(char const *s, unsigned int start, size_t len);
