/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:26:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 11:55:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap_3(int *t1, int *t2, int taille)
{
	int i;

	i = 0;
	while (i < taille)
	{
		if (t1[i] == t2[0] || t1[i] == t2[1] || t1[i] == t2[2] ||
				t1[i] == t2[3])
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(int *t1, int taille, int *spc)
{
	if (keep_form(t1, spc, taille) == 0)
		return (0);
	return (1);
}

void	assign_spot(int *tab)
{
	tab[0] = tab[0] + 1;
	tab[1] = tab[1] + 1;
	tab[2] = tab[2] + 1;
	tab[3] = tab[3] + 1;
}

void	ft_boucle(int var[3], int *t1, int *t2, int passage)
{
	while (var[0] < passage && var[2] == 0)
	{
		if (var[1] == t1[var[0]] && g_flag_try == 1)
		{
			g_final[var[1]] = g_show_l[var[1]];
			var[2] = 1;
		}
		var[0] = var[0] + 1;
	}
	if (var[2] == 0)
	{
		if (var[1] == t2[0] || var[1] == t2[1] ||
				var[1] == t2[2] || var[1] == t2[3])
			g_final[var[1]] = g_show_l[var[1]] + 1;
		else
			g_final[var[1]] = 0;
	}
	var[1] = var[1] + 1;
	var[0] = 0;
	var[2] = 0;
}

int		*try_tetris_2(int *t1, int *t2, int taille, int **spc, int k,
		int passage, int target)
{
	int var[3];

	var[0] = 0;
	var[1] = 0;
	var[2] = 0;
	rewind_tetris(t2, target);
	while (overlap_3(t1, t2, passage))
		assign_spot(t2);
	while (var[1] < taille * taille)
		ft_boucle(var, t1, t2, passage);
	return (g_final);
}
