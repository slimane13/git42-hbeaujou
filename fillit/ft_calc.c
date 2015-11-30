/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/30 11:49:36 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	calc_larg(int *tab, int taille)
{
	int i;
	int largMax;

	i = 0;
	largMax = 0;
	while (i < taille*taille)
	{
		if (tab[i] != 0 && i%taille > largMax)
			largMax = i%taille;
		i++;
	}
	largMax++;
	return(largMax);
}

int	calc_haut(int *tab, int taille)
{
	int i;
	int hautMax;

	i = 0;
	hautMax = 0;
	while (i < taille*taille)
	{
		if (tab[i] != 0 && i/taille > hautMax)
			hautMax = i/taille + 2;
		i++;
	}
	return(hautMax);
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
