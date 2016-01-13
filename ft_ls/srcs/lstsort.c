/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:14:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:31:27 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swap_name(t_dir *a, t_dir *b, t_option *op)
{
	int		res;

	res = ft_strcmp(a->name, b->name);
	if (res < 0 && op->rev == 1)
		ft_lstswap(&a, &b);
	else if (res > 0 && op->rev == 0)
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
			if ((res < 0 && op->rev == 0) || op->stop == 1)
				ft_lstswap(&temp_list, &rt_list);
			else if (res > 0 && op->rev == 1)
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
			if (op->date == 2)
				res = temp_list->buf.st_birthtime - rt_list->buf.st_birthtime;
			else if (op->date == 3)
				res = temp_list->buf.st_atime - rt_list->buf.st_atime;
			if (res > 0 && op->rev == 1)
				ft_lstswap(&temp_list, &rt_list);
			else if (res < 0 && op->rev == 0)
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
			if (res > 0 && op->rev == 1)
				ft_lstswap(&temp_list, &rt_list);
			else if (res < 0 && op->rev == 0)
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
	if (op->by == 1 || op->stop == 1)
		ft_lstsort_name(begin_list, op);
	if (op->by == 2)
		ft_lstsort_time(begin_list, op);
	if (op->prio_by == 3)
		ft_lstsort_size(begin_list, op);
}
