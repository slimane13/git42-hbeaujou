/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 15:28:16 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6_big(int flag[26])
{
	int testHaut6;
	int testLarg6;

	i6 = 0;
	testLarg6 = 0;
	testHaut6 = 0;
	if (flag[5] == 0)
	{
		clean6 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant6 = nbrCourant7 + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(clean6, tmpCalc, tailleMax * tailleMax);
	while (i6 < iterMax && testHaut6 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean6, (4 * nbrCourant6), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant6], tailleMax, var,
				nbrCourant6, (4 * nbrCourant6), i6);
		testLarg6 = calc_larg(tmpCalc, tailleMax);
		testHaut6 = calc_haut(tmpCalc, tailleMax);
		if (testLarg6 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant6), tailleMax);
			ft_boucle_f5_big(flag);
		}
		i6++;
	}
}

void	ft_boucle_f7_big(int flag[26])
{
	int testLarg7;
	int testHaut7;

	testHaut7 = 0;
	testLarg7 = 0;
	i7 = 0;
	if (flag[6] == 0)
	{
		clean7 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant7 = nbrCourant8 + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(clean7, tmpCalc, tailleMax * tailleMax);
	while (i7 < iterMax && testHaut7 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean7, (4 * nbrCourant7), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant7], tailleMax, var,
				nbrCourant7, (4 * nbrCourant7), i7);
		testHaut7 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg7 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg7 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant7), tailleMax);
			ft_boucle_f6_big(flag);
		}
		i7++;
	}
}

void	ft_boucle_f8_big(int flag[26])
{
	int testLarg8;
	int testHaut8;

	testHaut8 = 0;
	testLarg8 = 0;
	i8 = 0;
	if (flag[7] == 0)
	{
		clean8 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant8 = nbrCourant9 + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(clean8, tmpCalc, tailleMax * tailleMax);
	while (i8 < iterMax && testHaut8 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean8, (4 * nbrCourant8), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant8], tailleMax, var,
				nbrCourant8, (4 * nbrCourant8), i8);
		testHaut8 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg8 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg8 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant8), tailleMax);
			ft_boucle_f7_big(flag);
		}
		i8++;
	}
}

void	ft_boucle_f9_big(int flag[26])
{
	i9 = 0;
	if (flag[8] == 0)
	{
		clean9 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant9 = nbrCourant10 + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(clean9, tmpCalc, tailleMax * tailleMax);
	while (i9 < iterMax)
	{
		tampon = resitue(clean9, (4 * nbrCourant9), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant9], tailleMax, var,
				nbrCourant9, (4 * nbrCourant9), i9);
		affiche(tmpCalc);
		tampon = resitue(tmpCalc, (4 * nbrCourant9), tailleMax);
		ft_boucle_f8(flag);
		i9++;
	}
}

void	ft_boucle_f10_big(int flag[26])
{
	i10 = 0;
	if (flag[9] == 0)
	{
		clean10 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[9] = 1;
	}
	ft_strcpy_int(clean10, tmpCalc, tailleMax * tailleMax);
	while (i10 < iterMax)
	{
		tampon = resitue(clean10, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i10);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f9_big(flag);
		i10++;
	}
}
