/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:13:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:29:33 by hbeaujou         ###   ########.fr       */
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
		if (op->hide == 0)
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
