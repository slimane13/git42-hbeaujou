/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 01:49:26 by sksourou          #+#    #+#             */
/*   Updated: 2015/10/20 16:56:18 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			get_hook(t_all *a)
{
	draw_y(a);
	draw_x(a);
	return (1);
}

int			key_hook(int keycode, t_all *all)
{
	if (keycode == 69)
		change_scale(all, 1);
	if (keycode == 78)
		change_scale(all, 2);
	if (keycode == 126)
		change_scale(all, 3);
	if (keycode == 125)
		change_scale(all, 4);
	if (keycode == 123)
		change_scale(all, 5);
	if (keycode == 124)
		change_scale(all, 6);
	if (keycode == 53)
		exit(1);
	return (0);
}

void		change_scale(t_all *all, int i)
{
	mlx_clear_window(all->mlx, all->win);
	if (i == 1 && (all->scalx > 8 || all->scaly > 9))
	{
		all->scalx -= 5;
		all->scaly -= 5;
	}
	if (i == 2)
	{
		all->scalx += 5;
		all->scaly += 5;
	}
	if (i == 3)
		all->starty += 15;
	if (i == 4)
		all->starty -= 15;
	if (i == 5)
		all->startx += 15;
	if (i == 6)
		all->startx -= 15;
	get_hook(all);
}
