/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:34:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 11:12:21 by hbeaujou         ###   ########.fr       */
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

void	assign_spot_special(int *tab, int *counter)
{
	tab[0] = tab[0] + 1;
	tab[1] = tab[1] + 1;
	tab[2] = tab[2] + 1;
	tab[3] = tab[3] + 1;
	*counter = *counter + 1;
}

void	ft_cut_try_2_2(int *flag, int j, int *i,
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
