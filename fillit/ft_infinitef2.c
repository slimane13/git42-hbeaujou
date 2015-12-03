/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:39:39 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 12:19:22 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6(void)
{
	int testHaut6;
	int testLarg6;

	i6 = 0;
	testLarg6 = 0;
	testHaut6 = 0;
	if (flagF6 == 0)
	{
		clean6 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF6 = 1;
	}
	ft_strcpy_int(clean6, tmpCalc, tailleMax * tailleMax);
	while (i6 < iterMax && testHaut6 < hautMax + 1 && absTmp != nbrTetri)
	{
		tampon = resitue(clean6, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i6);
		testHaut6 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg6 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg6 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f5();
		}
		i6++;
	}
}

void	ft_boucle_f7(void)
{
	int testLarg7;
	int testHaut7;

	testHaut7 = 0;
	testLarg7 = 0;
	i7 = 0;
	if (flagF2 == 0)
	{
		clean7 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF7 = 1;
	}
	ft_strcpy_int(clean7, tmpCalc, tailleMax * tailleMax);
	while (i7 < iterMax && testHaut7 < hautMax + 1)
	{
		tampon = resitue(clean7, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i7);
		testHaut7 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg7 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
//		if (testLarg7 < largMax + 1)
//		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f6();
//		}
		i7++;
	}
}

void	ft_boucle_f8(void)
{
	int testHaut8;
	int testLarg8;

	testHaut8 = 0;
	testLarg8 = 0;
	i8 = 0;
	if (flagF8 == 0)
	{
		clean8 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF8 = 1;
	}
	ft_strcpy_int(clean8, tmpCalc, tailleMax * tailleMax);
	while (i8 < iterMax && testHaut8 < hautMax + 1)
	{
		tampon = resitue(clean8, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i8);
//		if (testLarg8 < largMax + 1)
//		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f7();
//		}
		i8++;
	}
}

void	ft_boucle_f9(void)
{
	i9 = 0;
	if (flagF9 == 0)
	{
		printf("LLLLLLLLLLLLLLD\n");
		clean9 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF9 = 1;
	}
	ft_strcpy_int(clean9, tmpCalc, tailleMax * tailleMax);
	while (i9 < iterMax)
	{
		tampon = resitue(clean9, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i9);
		affiche(tmpCalc);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f8();
		i9++;
	}
}

void	ft_boucle_f10(void)
{
	i10 = 0;
	if (flagF10 == 0)
	{
		clean10 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF10 = 1;
	}
	ft_strcpy_int(clean10, tmpCalc, tailleMax * tailleMax);
	while (i10 < iterMax)
	{
		tampon = resitue(clean10, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i10);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f9();
		i10++;
	}
}
