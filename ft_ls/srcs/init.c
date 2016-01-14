/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initoption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:14:16 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:02:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initoption(t_option **t_op)
{
	(*t_op)->rec = 0;
	(*t_op)->rev = 0;
	(*t_op)->hide = 0;
	(*t_op)->sup_hide = 0;
	(*t_op)->by = 1;
	(*t_op)->prio_by = 1;
	(*t_op)->format = 0;
	(*t_op)->colors = 0;
	(*t_op)->listed = 0;
	(*t_op)->date = 1;
	(*t_op)->pipe = 0;
	(*t_op)->stop = 0;
	(*t_op)->uid = 1;
	(*t_op)->long_date = 0;
}

t_len	ft_initlen(void)
{
	t_len	len;

	len.links = 0;
	len.uid = 0;
	len.gid = 0;
	len.size = 0;
	len.major = 0;
	len.minor = 0;
	len.maj_min = 0;
	len.dev = 0;
	len.total_blocks = 0;
	len.nb_files = 0;
	return (len);
}
