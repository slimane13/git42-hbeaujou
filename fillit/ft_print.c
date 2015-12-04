/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/04 17:06:40 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_display(int c)
{
	if (c == 0)
		ft_putchar('.');
	else
		ft_putchar('A' - 1 + c);
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
			ft_putchar('\n');
		}
		i++;
	}
	ft_putchar('\n');
}
