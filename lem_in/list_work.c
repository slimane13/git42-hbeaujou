/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 19:18:55 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstaddend_room(t_map **alst, t_map *new_r)
{
	t_map	*tmp;

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

t_room	*new_room(char *str, int cx, int cy)
{
	t_room *res;

	if (!(res = malloc(sizeof(t_room))))
		return (NULL);
	res->name = ft_strdup(str);
	res->x = cx;
	res->y = cy;
	return (res);
}

t_map	*new_map(char *str, int cx, int cy)
{
	t_map *res;

	if (!(res = malloc(sizeof(t_map))))
		return (NULL);
	res->room = new_room(str, cx, cy);
	return (res);
}
