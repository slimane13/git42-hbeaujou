/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 16:57:04 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	calc_larg(int *tab, int taille)
{
	int i;
	int largMax;
	int largeur;
	int	largMin;

	i = 0;
	largMax = 0;
	largMin = 100;
	while (i < taille*taille)
	{
		largeur = i%taille;
		if (tab[i] != 0 && largeur > largMax)
			largMax = largeur;
		else if (tab[i] != 0 && largeur < largMin)
			largMin = largeur;
		else
		{
		}
		i++;
	}
	largMax++;
	return(largMax - largMin);
}

int	calc_haut(int *tab, int taille)
{
	int i;
	int hautMax;
	int hauteur;
	int hautMin;

	i = 0;
	hautMax = 0;
	hautMin = 100;
	while (i < taille*taille)
	{
		hauteur = i/taille + 1;
		if (tab[i] != 0 && hauteur > hautMax)
			hautMax = hauteur;
		else if (tab[i] != 0 && hauteur < hautMin)
			hautMin = hauteur;
		else
		{
		}
		i++;
	}
	hautMax++;
	return(hautMax - hautMin);
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
