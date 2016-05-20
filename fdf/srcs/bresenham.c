/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 19:01:34 by sksourou          #+#    #+#             */
/*   Updated: 2015/10/20 16:54:11 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	bh_dispatch(t_all *all, int color)
{
	all->dx = all->x2 - all->x1;
	all->dy = all->y2 - all->y1;
	all->dx = ABS(all->dx);
	all->dy = ABS(all->dy);
	all->incx = (all->x2 > all->x1) ? 1 : -1;
	all->incy = (all->y2 > all->y1) ? 1 : -1;
	if (all->dx > all->dy)
		m_neg(all, color);
	else
		m_pos(all, color);
}

void	m_neg(t_all *all, int color)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(all->mlx, all->win, all->x1, all->y1, color);
	e = (2 * all->dy) - all->dx;
	inc1 = 2 * (all->dy - all->dx);
	inc2 = 2 * all->dy;
	while (i < all->dx)
	{
		if (e >= 0)
		{
			all->y1 = all->y1 + all->incy;
			e = e + inc1;
		}
		else
			e = e + inc2;
		all->x1 = all->x1 + all->incx;
		mlx_pixel_put(all->mlx, all->win, all->x1, all->y1, color);
		i++;
	}
}

void	m_pos(t_all *all, int color)
{
	int	inc1;
	int	inc2;
	int	e;
	int	i;

	i = 0;
	mlx_pixel_put(all->mlx, all->win, all->x1, all->y1, color);
	e = (2 * all->dx) - all->dy;
	inc1 = 2 * (all->dx - all->dy);
	inc2 = 2 * all->dx;
	while (i < all->dy)
	{
		if (e >= 0)
		{
			all->x1 = all->x1 + all->incx;
			e = e + inc1;
		}
		else
			e = e + inc2;
		all->y1 = all->y1 + all->incy;
		mlx_pixel_put(all->mlx, all->win, all->x1, all->y1, color);
		i++;
	}
}
