/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:18:16 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/01 18:06:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int *clean; yes ??
int	*tampon;
int	*tmpCalc;
int	*final;
int	largMax;
int hautMax;
int	testLarg;
int	testHaut;
int iterMax;
int absTmp;
int tailleMax;
int	**points;
int **var;
int nbrCourant;
int	i;
int flagF1;
int flagF2;
int *clean;

void	ft_boucle_f1(void)
{
	i = 0;
	if (flagF1 == 0)
	{
		nbrCourant++;
		flagF1 = 1;
	}
	while (i < iterMax && testHaut < hautMax)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		testLarg = calc_larg(tmpCalc, tailleMax);
		testHaut = calc_haut(tmpCalc, tailleMax);
//		printf("testHaut : %d\n", testHaut);
//		printf("hautMax : %d\n\n", hautMax);
		if ((testLarg < largMax && abs_minus(testLarg, testHaut) < absTmp) ||
				(testHaut < hautMax && abs_minus(testLarg, testHaut) < absTmp))
		{
//			printf("%d\n",hautMax);
//			printf("%d\n\n",testHaut);

//			printf("%d\n",largMax);
//			printf("%d\n\n",testLarg);
			final = tmpCalc;
			largMax = calc_larg(final, tailleMax);
			hautMax = calc_haut(final, tailleMax);
			absTmp = abs_minus(largMax, hautMax);
		}
		else
		{
		}
		affiche(final);
//		printf("%d\n",absTmp);
//		printf("%d\n",largMax);
//		printf("%d\n\n",hautMax);
		i++;
	}
}

void	ft_boucle_f2(void)
{
	int i2;

	i2 = 0;
	if (flagF2 == 0)
	{
		nbrCourant++;
		flagF2 = 1;
	}
	affiche(final);
	clean = final;
	while (i2 < iterMax)
	{
		tampon = resitue(clean, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f1();
//		printf("AAAAAA\n");
//		printf("%d\n", iterMax);
		i2++;
	}
}

void	ft_boucle_f3(void)
{
	i = 0;
	nbrCourant++;
	while (i < iterMax)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		tampon = resitue(final, (4 * nbrCourant), tailleMax);
		ft_boucle_f2();
		i++;
	}
}

void	ft_boucle_f4(void)
{
	i = 0;
	nbrCourant++;
	while (i < iterMax)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		tampon = resitue(final, (4 * nbrCourant), tailleMax);
		ft_boucle_f3();
		i++;
	}
}

void	ft_boucle_f5(void)
{
	i = 0;
	nbrCourant++;
	while (i < iterMax)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		tampon = resitue(final, (4 * nbrCourant), tailleMax);
		ft_boucle_f4();
		i++;
	}
}
