/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:43:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/02 11:11:22 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	key_hook(int keycode, t_point **begin, void *window, void *init)
{
	t_point	*tmp;

	ft_printf("Key : %d\n", keycode);
	tmp = *begin;
	if (keycode == RIGHT)
	{
		while (tmp)
		{
			tmp->x = tmp->x + 10;
			tmp = tmp->next;
		}
	}
	else if (keycode == DOWN)
	{
		while (tmp)
		{
			tmp->y = tmp->y + 10;
			tmp = tmp->next;
		}
	}
	else if (keycode == LEFT)
	{
		while (tmp)
		{
			tmp->x = tmp->x - 10;
			tmp = tmp->next;
		}
	}
	else if (keycode == UP)
	{
		while (tmp)
		{
			tmp->y = tmp->y - 10;
			tmp = tmp->next;
		}
	}
	else if (keycode == P)
	{
		while (tmp)
		{
			tmp->x = tmp->x * 1.2;
			tmp->y = tmp->y * 1.2;
			tmp = tmp->next;
		}
	}
	else
		;
	tmp = *begin;
	return (0);
}
