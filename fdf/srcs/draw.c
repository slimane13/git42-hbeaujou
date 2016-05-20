/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:50:16 by sksourou          #+#    #+#             */
/*   Updated: 2015/10/20 16:54:33 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		coord_x(t_all *all, int x, int y)
{
	return (all->startx - (all->scalx * y) + (all->scalx * x));
}

int		coord_y(t_all *all, int x, int y, int z)
{
	if (z > 30000)
		z = 30000;
	if (z < -30000)
		z = -30000;
	return (all->starty + ((all->scaly) * x) + ((all->scaly) * y) - (z * 2));
}

int		get_color(int z1, int z2)
{
	int	color;

	if (z1 >= 0 && z2 >= 0 && z2 != z1)
		color = 0xFF69B4;
	else if (z1 == z2 && z1 > 0)
		color = 0xFBF2B7;
	else if (z1 <= 0 && z2 <= 0 && z2 != z1)
		color = 0xDF6D14;
	else if (z1 == z2 && z1 < 0)
		color = 0x00FF7F;
	else
		color = 0xFFFFFF;
	return (color);
}

void	draw_y(t_all *all)
{
	int			i;
	int			j;

	i = 0;
	while (i < all->nbr_line)
	{
		j = 0;
		while (j < (all->nbr_split[i] - 1))
		{
			all->x1 = coord_x(all, j, i);
			all->y1 = coord_y(all, j, i, all->nbr[i][j]);
			j++;
			all->x2 = coord_x(all, j, i);
			all->y2 = coord_y(all, j, i, all->nbr[i][j]);
			bh_dispatch(all, get_color(all->nbr[i][j - 1], all->nbr[i][j]));
		}
		i++;
	}
}

void	draw_x(t_all *all)
{
	int			i;
	int			j;

	i = 0;
	while (i < (all->nbr_line - 1))
	{
		j = 0;
		while (j < all->nbr_split[i] && (all->nbr_split[i + 1] - j) > 0)
		{
			all->x1 = coord_x(all, j, i);
			all->y1 = coord_y(all, j, i, all->nbr[i][j]);
			all->x2 = coord_x(all, j, i + 1);
			all->y2 = coord_y(all, j, i + 1, all->nbr[i + 1][j]);
			bh_dispatch(all, get_color(all->nbr[i][j], all->nbr[i + 1][j]));
			j++;
		}
		i++;
	}
}
