/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:42:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:23:38 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	calc_attrib(int *clean, int *nbr, int i, int *t1, int *t2, int indice)
{
	tampon = resitue(clean, (4 * nbr[indice - 1]), taille_max);
	tmpCalc = try_tetris_2(tampon, points[nbr[indice - 1]], taille_max, var,
			nbr[indice - 1], (4 * nbr[indice - 1]), i);
	*t1 = calc_larg(tmpCalc, taille_max);
	*t2 = calc_haut(tmpCalc, taille_max);
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
