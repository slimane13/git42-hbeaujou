/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:34:33 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 10:51:39 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cut_try_special(int varx[3], int passage, int *t1, int *t2)
{
	if (!t1)
	{
	}
	while (varx[0] < passage && varx[2] == 0)
	{
		if (varx[1] == t2[0] || varx[1] == t2[1] ||
				varx[1] == t2[2] || varx[1] == t2[3])
			g_final[varx[1]] = g_show_l[varx[1]] + 1;
		else
			g_final[varx[1]] = 0;
		varx[0] = varx[0] + 1;
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

void	ft_cut_try_2_2(int vari[3], int passage, int *t1, int *t2)
{
	while (vari[0] < passage && vari[2] == 0)
	{
		if (vari[1] == t1[vari[0]] && g_flag_try == 1)
		{
			g_final[vari[1]] = g_show_l[vari[1]];
			vari[2] = 1;
		}
		vari[0] = vari[0] + 1;
	}
	if (vari[2] == 0)
	{
		if (vari[1] == t2[0] || vari[1] == t2[1] ||
				vari[1] == t2[2] || vari[1] == t2[3])
			g_final[vari[1]] = g_show_l[vari[1]] + 1;
		else
			g_final[vari[1]] = 0;
	}
}

void	resolve(void)
{
	g_flag_try = 1;
	remp_blank(g_tmp_calc);
	g_larg_max = 100;
	g_trouve = 0;
	g_haut_max = 100;
	g_abs_tmp = 100;
	attrib_iter();
	if (g_nbr_tetri > 2)
	{
		while (g_trouve == 0)
		{
			choix_boucle(g_nbr_tetri);
			g_test_max++;
		}
	}
	else
		choix_boucle(g_nbr_tetri);
}

void	cut_main(int *ite, char **tetri_list)
{
	if (g_nbr_tetri == 2)
		g_len_mx = 5;
	while (*ite > 0)
	{
		g_points[*ite - 1] = situe_point(tetri_list[*ite - 1]);
		*ite = *ite - 1;
	}
	rewind_tetris(g_points[0], 0);
	g_flag_try = 0;
}
