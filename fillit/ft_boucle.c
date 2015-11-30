/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boucle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:48:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/30 17:19:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*ft_intcpy(int *src, int *dst, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		*ft_intdup(int *src, int len)
{
	int *p = malloc(sizeof(int) * len);
	ft_memcpy(p, src, len * sizeof(int));
	return (p);
}

void	boucle_test(int nbrTetri, int iterMax, int nbrCourant, int *largMax,
		int *hautMax, int *absTmp, int *tampon, int tailleMax, int **var, int **final, int **points,
		int *clean)
{
	int iCourant;
	int testLarg;
	int testHaut;
	int *tmpCalc;

	iCourant = 0;
	*absTmp = 100;
	*largMax = 100;
	*hautMax = 100;
	if (nbrCourant < nbrTetri - 1)
	{
//		while (iCourant < iterMax)
//		{
			tampon = resitue(*final, (4 * nbrCourant), tailleMax);
			boucle_test(nbrTetri, iterMax, nbrCourant + 1, largMax, hautMax, absTmp, tampon, tailleMax,
					var, final, points, clean);
			iCourant++;
//		}
	}
//	else
//	{
		while (iCourant < iterMax)
		{
			tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var, nbrCourant,
					(4 * nbrCourant), iCourant);
			testLarg = calc_larg(tmpCalc, tailleMax);
			testHaut = calc_haut(tmpCalc, tailleMax);
			if ((testLarg < *largMax && abs_minus(testLarg, testHaut) < *absTmp) ||
					(testHaut < *hautMax && abs_minus(testLarg, testHaut) < *absTmp))
			{
				clean = ft_intcpy(tmpCalc, clean, 64);
				*largMax = calc_larg(clean, tailleMax);
				*hautMax = calc_haut(clean, tailleMax);
				*absTmp = abs_minus(*largMax, *hautMax);
			}
			else
			{
			}
			printf("%d\n", nbrCourant);
			printf("%d\n\n", iCourant);
			affiche(clean);
			iCourant++;
//		}
	}	
}
