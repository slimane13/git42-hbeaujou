/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 15:18:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f1_big(int flag[26])
{
	int i;
	int hautMax1;

	i = 0;
	if (flag[0] == 0)
	{
		clean = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant = nbrCourant2 + 1;
		flag[0] = 1;
	}
	while (i < iterMax && testHaut < testMax + 4 && trouve == 0)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		testLarg = calc_larg(tmpCalc, tailleMax);
		testHaut = calc_haut(tmpCalc, tailleMax);
		absTmp = abs_minus(testHaut, testLarg);
		if (absTmp <= testMax)
		{
			ft_strcpy_int(clean, tmpCalc, tailleMax * tailleMax);
			trouve = 1;
		}
		else
		{
		}
		i++;
	}
}

void	ft_boucle_f2_big(int flag[26])
{
	int	testHaut2;
	int	testLarg2;

	i2 = 0;
	testHaut2 = 0;
	testLarg2 = 0;
	if (flag[1] == 0)
	{
		clean2 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant2 = nbrCourant3 + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(clean2, tmpCalc, tailleMax * tailleMax);
	while (i2 < iterMax && testHaut2 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean2, (4 * nbrCourant2), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant2], tailleMax, var,
				nbrCourant2, (4 * nbrCourant2), i2);
		testLarg2 = calc_larg(tmpCalc, tailleMax);
		testHaut2 = calc_haut(tmpCalc, tailleMax);
		if (testLarg2 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant2), tailleMax);
			ft_boucle_f1_big(flag);
		}
		i2++;
	}
}

void	ft_boucle_f3_big(int flag[26])
{
	int	testHaut3;
	int	testLarg3;
	
	i3 = 0;
	testHaut3 = 0;
	testLarg3 = 0;
	if (flag[2] == 0)
	{
		clean3 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant3 = nbrCourant4 + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(clean3, tmpCalc, tailleMax * tailleMax);
	while (i3 < iterMax && testHaut3 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean3, (4 * nbrCourant3), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant3], tailleMax, var,
				nbrCourant3, (4 * nbrCourant3), i3);
		testLarg3 = calc_larg(tmpCalc, tailleMax);
		testHaut3 = calc_haut(tmpCalc, tailleMax);
		if (testLarg3 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant3), tailleMax);
			ft_boucle_f2_big(flag);
		}
		i3++;
	}
}

void	ft_boucle_f4_big(int flag[26])
{
	int	testHaut4;
	int	testLarg4;

	i4 = 0;
	testHaut4 = 0;
	testLarg4 = 0;
	if (flag[3] == 0)
	{
		clean4 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant4 = nbrCourant5 + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(clean4, tmpCalc, tailleMax * tailleMax);
	while (i4 < iterMax && testHaut4 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean4, (4 * nbrCourant4), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant4], tailleMax, var,
				nbrCourant4, (4 * nbrCourant4), i4);
		testLarg4 = calc_larg(tmpCalc, tailleMax);
		testHaut4 = calc_haut(tmpCalc, tailleMax);
		if (testLarg4 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant4), tailleMax);
			ft_boucle_f3_big(flag);
		}
		i4++;
	}
}

void	ft_boucle_f5_big(int flag[26])
{
	int	testHaut5;
	int	testLarg5;

	i5 = 0;
	testLarg5 = 0;
	testHaut5 = 0;
	if (flag[4] == 0)
	{
		clean5 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant5 = nbrCourant6 + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(clean5, tmpCalc, tailleMax * tailleMax + 1);
	while (i5 < iterMax && testHaut5 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean5, (4 * nbrCourant5), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant5], tailleMax, var,
				nbrCourant5, (4 * nbrCourant5), i5);
		testLarg5 = calc_larg(tmpCalc, tailleMax);
		testHaut5 = calc_haut(tmpCalc, tailleMax);
		if (testLarg5 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant5), tailleMax);
			ft_boucle_f4_big(flag);
		}
		i5++;
	}
}
