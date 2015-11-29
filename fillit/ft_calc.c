/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:53:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/29 17:22:48 by hbeaujou         ###   ########.fr       */
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
		if (tab[i]%taille > largMax)
			largMax = tab[i]%taille;
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
		if (tab[i]/taille > hautMax)
			hautMax = tab[i]%taille;
		i++;
	}
	return(hautMax);
}
