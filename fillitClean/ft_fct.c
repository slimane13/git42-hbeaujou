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
	tampon = resitue(clean, (4 * nbr[indice - 1]), taille_max);
	tmpCalc = try_tetris_2(tampon, points[nbr[indice - 1]], taille_max, var,
			nbr[indice - 1], (4 * nbr[indice - 1]), i);
	*t1 = calc_larg(tmpCalc, taille_max);
	*t2 = calc_haut(tmpCalc, taille_max);
}

void	attrb_2(int *backtrack)
{
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	larg_max = calc_larg(final, taille_max);
	haut_max = calc_haut(final, taille_max);
	absTmp = absc(larg_max, haut_max);
}

void	remp_blank(int *tab)
{
	int i;

	i = 0;
	while (i < taille_max * taille_max)
	{
		tab[i] = 0;
		i++;
	}
}
