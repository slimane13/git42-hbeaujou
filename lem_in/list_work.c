/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 09:41:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstaddend_room(t_map **alst, t_map *new_r)
{
	t_map	*tmp;

	tmp = *alst;
	ft_putchar('\n');
	if (!tmp)
		*alst = new_r;
	else
	{
		ft_putchar('\n');
		while (tmp->next)
			tmp = tmp->next;
		ft_putchar('\n');
		tmp->next = new_r;
		ft_putchar('\n');
	}
	ft_putchar('\n');
}

t_room	*new_room(char *str, int cx, int cy)
{
	t_room *res;

	if (!(res = malloc(sizeof(t_room))))
		return (NULL);
	res->name = ft_strdup(str);
	res->x = cx;
	res->y = cy;
	res->next = NULL;
	return (res);
}

t_map	*new_map(char *str, int cx, int cy)
{
	t_map *res;

	if (!(res = malloc(sizeof(t_map))))
		return (NULL);
	res->room = new_room(str, cx, cy);
	res->next = NULL;
	return (res);
}
