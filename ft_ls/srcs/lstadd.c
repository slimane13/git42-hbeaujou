/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 23:42:22 by bsautron          #+#    #+#             */
/*   Updated: 2014/11/28 22:21:29 by bsautron         ###   ########.fr       */
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
