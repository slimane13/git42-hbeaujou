/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 19:03:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_display(int c)
{
	if (c == 0)
		printf(".");
	else
		printf("%c", 'Z' - 'A' - c + 40 + nbrTetri);
}

void		affiche(int *final)
{
	int i;
	int j;
	int taille;

	i = 0;
	j = 0;
	taille = tailleMax;
	while (i/taille < absTmp)
	{
		if (i % taille < absTmp - 1)
			ft_display(final[i]);
		else if (i % taille == absTmp - 1)
		{
			ft_display(final[i]);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}

void		affiche_special(int *final)
{
	int i;
	int j;
	int taille;

	i = 0;
	j = 0;
	taille = tailleMax;
	while (i/taille < 8)
	{
		if (i % taille < 7)
			ft_display(final[i]);
		else if (i % taille == 7)
		{
			ft_display(final[i]);
			printf("\n");
		}
		i++;
	}
	printf("\n");
}
