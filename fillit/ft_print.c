/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 12:59:31 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 11:45:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		if (i%taille < taille - 1)
			printf("%d", final[i]);
		else if (i%taille == taille - 1)
		{
			printf("%d", final[i]);
			printf("\n");
		}
		else
		{
		}
		i++;
	}
	printf("\n");
}
