/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rajouts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:07:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:36:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	info_cut3(int count[9], t_dir **f)
{
	if (count[4] > 2)
	{
		(*f)->format->linkname = ft_strdup("ldapmodify");
		count[4] = 0;
	}
	if (count[3] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT10);
		count[3] = 0;
	}
	if (count[2] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT11);
		count[2] = 0;
	}
	if (count[1] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT12);
		count[1] = 0;
	}
	if (count[0] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT13);
		count[0] = 0;
	}
}
