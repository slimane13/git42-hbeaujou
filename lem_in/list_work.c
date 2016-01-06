/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 16:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 17:09:18 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_lstaddend_tun(t_tun **alst, t_tun *new_r)
{
	t_tun	*tmp;

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

t_tun	*new_tun(char *str)
{
	t_tun *res;

	if (!(res = (t_tun *)malloc(sizeof(t_tun))))
		return (NULL);
	res->name = ft_strdup(str);
	res->next = NULL;
	res->p_map = NULL;
	return (res);
}

t_room	*new_room(char *str, int cx, int cy)
{
	t_room *res;

	if (!(res = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	res->name = ft_strdup(str);
	res->x = cx;
	res->y = cy;
	res->flag = 0;
	res->from_end = 0;
	res->next = NULL;
	return (res);
}

t_map	*new_map(char *str, int cx, int cy)
{
	t_map *res;

	if (!(res = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	res->room = new_room(str, cx, cy);
	res->next = NULL;
	return (res);
}
