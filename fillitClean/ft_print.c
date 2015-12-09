/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 10:27:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_display(int c)
{
	if (c == 0)
		printf(".");
	else
		printf("%c", 'Z' - 'A' - c + 40 + g_nbrTetri);
}

void		affiche(int *g_final)
{
	int i;
	int j;
	int taille;

	i = 0;
	j = 0;
	taille = g_taille_max;
	while (i / taille < g_absTmp)
	{
		if (i % taille < g_absTmp - 1)
			ft_display(g_final[i]);
		else if (i % taille == g_absTmp - 1)
		{
			ft_display(g_final[i]);
			printf("\n");
		}
		i++;
	}
	g_trouve = 1;
}
