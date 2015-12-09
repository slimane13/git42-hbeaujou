/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:42:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 10:57:14 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	define(void)
{
}

void	instance(int ite, char **tetri_list, char *str)
{
}

void	calc(int *clean, int *nbr, int i, int *t1, int *t2, int indice)
{
	g_tampon = resitue(clean, (4 * nbr[indice - 1]), g_taille_max);
	g_tmpCalc = try_tetris_2(g_tampon, g_points[nbr[indice - 1]], g_taille_max, g_var,
			nbr[indice - 1], (4 * nbr[indice - 1]), i);
	*t1 = calc_larg(g_tmpCalc, g_taille_max);
	*t2 = calc_haut(g_tmpCalc, g_taille_max);
}

void	attrb_2(int *backtrack)
{
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	g_larg_max = calc_larg(g_final, g_taille_max);
	g_haut_max = calc_haut(g_final, g_taille_max);
	g_absTmp = absc(g_larg_max, g_haut_max);
}

void	remp_blank(int *tab)
{
	int i;

	i = 0;
	while (i < g_taille_max * g_taille_max)
	{
		tab[i] = 0;
		i++;
	}
}
