/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:13:30 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:13:31 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_dir(t_dir **begin_list)
{
	t_dir	*temp;

	temp = *begin_list;
	while (temp)
	{
		free(temp->dossier);
		free(temp->name);
		free(temp->absolute);
		free(temp->format->uid_name);
		free(temp->format->gid_name);
		free(temp->format->time);
		temp = temp->next;
	}
	*begin_list = NULL;
}
