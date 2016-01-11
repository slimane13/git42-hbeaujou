/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 21:50:21 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/01 00:37:11 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir	*ft_lstnew_ls(struct stat buf)
{
	t_dir	*new_files;

	new_files = (t_dir *)malloc(sizeof(t_dir));
	if (new_files == NULL)
		return (NULL);
	new_files->buf = buf;
	new_files->next = NULL;
	return (new_files);
}
