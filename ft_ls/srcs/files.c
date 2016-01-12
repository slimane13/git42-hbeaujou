/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbfiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:44:12 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 14:51:07 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nbfiles(t_dir **begin, t_option *op)
{
	int		f;
	t_dir	*temp;

	temp = *begin;
	f = 0;
	while (temp)
	{
		if (op->hide == NO_HIDE)
		{
			if (temp->name[0] != '.')
				f++;
		}
		else
			f++;
		temp = temp->next;
	}
	return (f);
}
