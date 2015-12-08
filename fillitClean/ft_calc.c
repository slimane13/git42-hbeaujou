/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:07:10 by hbeaujou         ###   ########.fr       */
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

int	calc_haut(int *tab, int taille)
{
	int i;
	int haut_max_test;
	int hauteur;
	int haut_min;
	int flag_m;

	i = 0;
	flag_m = 0;
	haut_max_test = -1;
	haut_min = 0;
	hauteur = 0;
	while (i < taille * taille)
	{
		hauteur = i / taille + 1;
		if (tab[i] != 0 && hauteur > haut_max_test)
		{
			if (flag_m == 0)
			{
				haut_min = hauteur;
				flag_m = 1;
			}
			haut_max_test = hauteur;
		}
		i++;
	}
	haut_max_test++;
	return (haut_max_test - haut_min);
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
