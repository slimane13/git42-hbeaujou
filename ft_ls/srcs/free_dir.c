/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 07:43:56 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 07:44:17 by bsautron         ###   ########.fr       */
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
