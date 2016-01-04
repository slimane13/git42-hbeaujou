/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 16:53:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstaddend_room(t_room **alst, t_room *new_r)
{
	t_room	*tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_r;
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
