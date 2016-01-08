/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:31:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 12:52:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_lstaddend_line(t_line **alst, t_line *new_r)
{
	t_line	*tmp;

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

void	ft_lstaddend_point(t_point **alst, t_point *new_r)
{
	t_point	*tmp;

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

t_point	*new_point(int x, int y, int h)
{
	t_point	*res;

	if (!(res = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	res->next = NULL;
	res->x = x;
	res->y = y;
	res->h = h;
	return (res);
}

t_line	*new_line(t_point *pt)
{
	t_line	*res;

	if (!(res = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	res->next = NULL;
	res->line = pt;
	return (res);
}
