/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 11:12:04 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	attrib_iter_first(void)
{
	if (g_nbr_tetri == 1)
	{
		g_iter_max = 6;
		g_test_max = 0;
	}
	else if (g_nbr_tetri == 2)
	{
		g_iter_max = 6;
		g_test_max = 1;
	}
	else if (g_nbr_tetri == 3)
	{
		g_iter_max = 24;
		g_test_max = 1;
	}
	else if (g_nbr_tetri == 4)
	{
		g_iter_max = 45;
		g_test_max = 3;
	}
	else if (g_nbr_tetri == 5)
	{
		g_iter_max = 55;
		g_test_max = 4;
	}
}

void	attrib_iter_second(void)
{
	if (g_nbr_tetri == 6)
	{
		g_iter_max = 60;
		g_test_max = 4;
	}
	else if (g_nbr_tetri == 7)
	{
		g_iter_max = 70;
		g_test_max = 4;
	}
	else if (g_nbr_tetri == 8)
	{
		g_iter_max = 70;
		g_test_max = 5;
	}
	else if (g_nbr_tetri == 9)
	{
		g_iter_max = 100;
		g_test_max = 7;
	}
	else if (g_nbr_tetri == 10)
	{
		g_iter_max = 120;
		g_test_max = 6;
	}
}

int		calc_larg(int *tab, int taille)
{
	int i;
	int g_larg_max_test;
	int largeur;
	int	larg_min;

	i = 0;
	largeur = 0;
	g_larg_max_test = -1;
	larg_min = 10;
	while (i < taille * taille)
	{
		largeur = i % taille;
		if (tab[i] != 0 && largeur > g_larg_max_test)
			g_larg_max_test = largeur;
		else if (tab[i] != 0 && largeur < larg_min)
			larg_min = largeur;
		i++;
	}
	g_larg_max_test++;
	return (g_larg_max_test);
}

int		calc_haut(int *tab_tetri, int taille)
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

int		absc(int a, int b)
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
