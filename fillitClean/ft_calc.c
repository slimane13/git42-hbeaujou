/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:50:48 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	calc_larg(int *tab, int taille)
{
	int i;
	int larg_max_test;
	int largeur;
	int	larg_min;

	i = 0;
	largeur = 0;
	larg_max_test = -1;
	larg_min = 10;
	while (i < taille * taille)
	{
		largeur = i % taille;
		if (tab[i] != 0 && largeur > larg_max_test)
			larg_max_test = largeur;
		else if (tab[i] != 0 && largeur < larg_min)
			larg_min = largeur;
		i++;
	}
	larg_max_test++;
	return (larg_max_test);
}

int	calc_haut(int *tab_tetri, int taille)
{
	int tab[4];
	int i;

	i = 0;
	tab[0] = 0;
	tab[1] = -1;
	tab[3] = 0;
	tab[2] = 0;
	while (i < taille * taille)
	{
		tab[2] = i / taille + 1;
		if (tab_tetri[i] != 0 && tab[2] > tab[1])
		{
			if (tab[0] == 0)
			{
				tab[3] = tab[2];
				tab[0] = 1;
			}
			tab[1] = tab[2];
		}
		i++;
	}
	tab[1]++;
	return (tab[1] - tab[3]);
}

int	abs_minus(int a, int b)
{
	int n;

	n = 0;
	if (a > b)
		n = a;
	else if (a < b)
		n = b;
	else
		n = a;
	return (n);
}
