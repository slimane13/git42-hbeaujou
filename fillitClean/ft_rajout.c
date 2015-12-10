/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:34:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 10:55:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cut_try_special(int *flag, int j, int *i,
		int passage, int *t1, int *t2)
{
	while (*i < passage && *flag == 0)
	{
		if (j == t1[*i] && g_flag_try == 1)
		{
			g_final[j] = g_show_l[j];
			*flag = 1;
		}
		*i = *i + 1;
	}
	if (*flag == 0)
	{
		if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
			g_final[j] = g_show_l[j] + 1;
		else
			g_final[j] = 0;
	}
}
