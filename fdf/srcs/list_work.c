/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:31:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/02 09:39:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

t_point	*new_point(int x, int y, int z)
{
	t_point	*res;

	if (!(res = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	res->next = NULL;
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
