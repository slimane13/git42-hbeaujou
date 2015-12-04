/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/04 14:42:13 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_display(final[i])
{
	
}

void	affiche(int * final)
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
		{
			if (final[i] == 0)
				ft_puchar('.');
			else
				ft_puchar('A' - 1 + final[i]);
		}
		else if (i % taille == taille - 1)
		{
			if (final[i] == 0)
				ft_putchar('.');
			else
				ft_putchar('A' - 1 + final[i]);
			ft_putchar('\n');
		}
		i++;
	}
	ft_putchar('\n');
}
