/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 21:06:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/04/09 21:30:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mod1.h"

t_point	*new_point(int cx, int cy, float cz)
{
	t_point *res;

	res = (t_point *)malloc(sizeof(t_point));
	res->x = cx;
	res->y = cy;
	res->z = cz;
	res->next = NULL;
	return (res);
}

void	lst_addend_point(t_point **alst, t_point *new_r)
{
	t_point *tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}
