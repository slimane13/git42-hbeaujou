/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:14:38 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:39 by hbeaujou         ###   ########.fr       */
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
