/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:59:51 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 19:42:58 by hbeaujou         ###   ########.fr       */
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

void	tri_name(t_file **files)
{
}
