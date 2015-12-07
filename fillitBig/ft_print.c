/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 11:05:47 by hbeaujou         ###   ########.fr       */
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
	while (i < taille * taille)
	{
		if (i % taille < taille - 1)
			ft_display(final[i]);
		else if (i % taille == taille - 1)
		{
			ft_display(final[i]);
			printf("\n");
		}
		i++;
	}
	ft_putchar('\n');
}