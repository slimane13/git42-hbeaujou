/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 10:58:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	calc_larg(int *tab, int taille)
{
	int i;
	int largMaxTest;
	int largeur;
	int	largMin;

	i = 0;
	largeur = 0;
	largMaxTest = -1;
	largMin = 10;
	while (i < taille*taille)
	{
		largeur = i%taille;
		if (tab[i] != 0 && largeur > largMaxTest)
			largMaxTest = largeur;
		else if (tab[i] != 0 && largeur < largMin)
			largMin = largeur;
		else
		{
		}
		i++;
	}
	largMaxTest++;
/*	if (i4 == 0 && i3 == 2 && i2 == 11)
	{
		printf("%d", largMaxTest);
		printf("   ");
		printf("%d\n", largMin);
	}*/
//	return(largMaxTest - largMin);
	return (largMaxTest);
}

int	calc_haut(int *tab, int taille)
{
	int i;
	int hautMaxTest;
	int hauteur;
	int hautMin;
	int flagM;

	i = 0;
	flagM = 0;
	hautMaxTest = -1;
	hautMin = 0;
	hauteur = 0;
	while (i < taille*taille)
	{
		hauteur = i/taille + 1;
		if (tab[i] != 0 && hauteur > hautMaxTest)
		{
			if (flagM == 0)
			{
				hautMin = hauteur;
				flagM = 1;
			}
			hautMaxTest = hauteur;
		}
		else
		{
		}
		i++;
	}
	hautMaxTest++;
	return(hautMaxTest - hautMin);
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
