/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 00:30:16 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/04 16:07:13 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swap_name(t_dir *a, t_dir *b, t_option *op)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	if (res < 0 && op->rev == REVERSE)
		ft_lstswap(&a, &b);
	else if (res > 0 && op->rev == NO_REVERSE)
		ft_lstswap(&a, &b);
}

static void	ft_lstsort_name(t_dir **begin_list, t_option *op)
{
	t_dir	*temp_list;
	t_dir	*rt_list;
	int		res;

	temp_list = *begin_list;
	while (temp_list)
	{
		rt_list = temp_list->next;
		while (rt_list != NULL)
		{
			res = ft_strcmp(rt_list->name, temp_list->name);
			if ((res < 0 && op->rev == NO_REVERSE) || op->stop == STOP)
				ft_lstswap(&temp_list, &rt_list);
			else if (res > 0 && op->rev == REVERSE)
				ft_lstswap(&temp_list, &rt_list);
			rt_list = rt_list->next;
		}
		temp_list = temp_list->next;
	}
}

static void	ft_lstsort_time(t_dir **begin_list, t_option *op)
{
	t_dir	*temp_list;
	t_dir	*rt_list;
	time_t	res;

	temp_list = *begin_list;
	while (temp_list)
	{
		rt_list = temp_list->next;
		while (rt_list != NULL)
		{
			res = temp_list->buf.st_mtime - rt_list->buf.st_mtime;
			if (op->date == DATE_CREATE)
				res = temp_list->buf.st_birthtime - rt_list->buf.st_birthtime;
			else if (op->date == DATE_ACCES)
				res = temp_list->buf.st_atime - rt_list->buf.st_atime;
			if (res > 0 && op->rev == REVERSE)
				ft_lstswap(&temp_list, &rt_list);
			else if (res < 0 && op->rev == NO_REVERSE)
				ft_lstswap(&temp_list, &rt_list);
			else if (res == 0)
				ft_swap_name(temp_list, rt_list, op);
			rt_list = rt_list->next;
		}
		temp_list = temp_list->next;
	}
}

static void	ft_lstsort_size(t_dir **begin_list, t_option *op)
{
	t_dir	*temp_list;
	t_dir	*rt_list;
	time_t	res;

	temp_list = *begin_list;
	while (temp_list)
	{
		rt_list = temp_list->next;
		while (rt_list != NULL)
		{
			res = temp_list->buf.st_size - rt_list->buf.st_size;
			if (res > 0 && op->rev == REVERSE)
				ft_lstswap(&temp_list, &rt_list);
			else if (res < 0 && op->rev == NO_REVERSE)
				ft_lstswap(&temp_list, &rt_list);
			else if (res == 0)
				ft_swap_name(temp_list, rt_list, op);
			rt_list = rt_list->next;
		}
		temp_list = temp_list->next;
	}
}

void		ft_lstsort(t_dir **begin_list, t_option *op)
{
	if (op->by == BY_NAME || op->stop == STOP)
		ft_lstsort_name(begin_list, op);
	if (op->by == BY_TIME)
		ft_lstsort_time(begin_list, op);
	if (op->prio_by == BY_SIZE)
		ft_lstsort_size(begin_list, op);
}
