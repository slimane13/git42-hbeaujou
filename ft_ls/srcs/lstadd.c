/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:14:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstadd_ls(t_dir **begin_list, struct stat buf)
{
	t_dir	*new;

	new = ft_lstnew_ls(buf);
	if (begin_list && *begin_list)
		new->next = *begin_list;
	*begin_list = new;
}
