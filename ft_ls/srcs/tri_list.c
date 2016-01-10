/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:59:51 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/10 12:27:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	next_to_previous(t_file **files)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *files;
	tmp2 = NULL;
	while (tmp)
	{
		tmp->previous = tmp2;
		tmp2 = tmp;
		tmp = tmp->next;
	}
}

void	tri_rev(t_file **files)
{
	t_file *temp;
	t_file *current;

	next_to_previous(files);
	temp = NULL;
	current = *files;
	while (current !=  NULL)
	{
		temp = current->previous;
		current->previous = current->next;
		current->next = temp;
		current = current->previous;
	}
	if (temp != NULL)
		*files = temp->previous;
}

void 	tri_time(t_file **head)
{
	int done;
	t_file **pv;
	t_file *nd;
	t_file *nx;

	done = 0;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (!done)
	{
		pv = head;
		nd = *head;
		nx = (*head)->next;
		done = 1;
		while (nx)
		{
			if (nd->stats.st_mtime < nx->stats.st_mtime)
			{
				nd->next = nx->next;
				nx->next = nd;
				*pv = nx;

				done = 0;
			}
			else if (nd->stats.st_mtime == nx->stats.st_mtime &&
					ft_strcmp(nd->name, nx->name) > 0)
			{
				nd->next = nx->next;
				nx->next = nd;
				*pv = nx;

				done = 0;
			}
			pv = &nd->next;
			nd = nx;
			nx = nx->next;
		}
	}
}

void 	tri_char(t_file **head)
{
	int done;
	t_file **pv;
	t_file *nd;
	t_file *nx;

	done = 0;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (!done)
	{
		pv = head;
		nd = *head;
		nx = (*head)->next;
		done = 1;
		while (nx)
		{
			if (ft_strcmp(nd->name, nx->name) > 0)
			{
				nd->next = nx->next;
				nx->next = nd;
				*pv = nx;

				done = 0;
			}
			pv = &nd->next;
			nd = nx;
			nx = nx->next;
		}
	}
}
