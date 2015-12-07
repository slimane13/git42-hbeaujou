/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:09:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/07 18:16:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11_big(int flag[26])
{
	int testHaut11;
	int testLarg11;

	i11 = 0;
	testLarg11 = 0;
	testHaut11 = 0;
	if (flag[10] == 0)
	{
		clean11 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant11 = nbrCourant12 + 1;
		flag[10] = 1;
	}
	ft_strcpy_int(clean11, tmpCalc, tailleMax * tailleMax);
	while (i11 < iterMax && testHaut11 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean11, (4 * nbrCourant11), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant11], tailleMax, var,
				nbrCourant11, (4 * nbrCourant11), i11);
		testLarg11 = calc_larg(tmpCalc, tailleMax);
		testHaut11 = calc_haut(tmpCalc, tailleMax);
		if (testLarg11 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant11), tailleMax);
			ft_boucle_f10_big(flag);
		}
		i11++;
	}
}

void	ft_boucle_f12_big(int flag[26])
{
	int testLarg12;
	int testHaut12;

	testHaut12 = 0;
	testLarg12 = 0;
	i12 = 0;
	if (flag[11] == 0)
	{
		clean12 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant12 = nbrCourant13 + 1;
		flag[11] = 1;
	}
	ft_strcpy_int(clean12, tmpCalc, tailleMax * tailleMax);
	while (i12 < iterMax && testHaut12 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean12, (4 * nbrCourant12), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant12], tailleMax, var,
				nbrCourant12, (4 * nbrCourant12), i12);
		testHaut12 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg12 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg12 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant12), tailleMax);
			ft_boucle_f11_big(flag);
		}
		i12++;
	}
}

void	ft_boucle_f13_big(int flag[26])
{
	int testLarg13;
	int testHaut13;

	testHaut13 = 0;
	testLarg13 = 0;
	i13 = 0;
	if (flag[12] == 0)
	{
		clean13 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant13 = nbrCourant14 + 1;
		flag[12] = 1;
	}
	ft_strcpy_int(clean13, tmpCalc, tailleMax * tailleMax);
	while (i13 < iterMax && testHaut13 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean13, (4 * nbrCourant13), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant13], tailleMax, var,
				nbrCourant13, (4 * nbrCourant13), i13);
		testHaut13 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg13 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg13 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant13), tailleMax);
			ft_boucle_f12_big(flag);
		}
		i13++;
	}
}

void	ft_boucle_f14_big(int flag[26])
{
	int testLarg14;
	int testHaut14;

	testHaut14 = 0;
	testLarg14 = 0;
	i14 = 0;
	if (flag[13] == 0)
	{
		clean14 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant14 = nbrCourant15 + 1;
		flag[13] = 1;
	}
	ft_strcpy_int(clean14, tmpCalc, tailleMax * tailleMax);
	while (i14 < iterMax && testHaut14 < testMax + 1 && trouve == 0)
	{
		tampon = resitue(clean14, (4 * nbrCourant14), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant14], tailleMax, var,
				nbrCourant14, (4 * nbrCourant14), i14);
		testHaut14 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg14 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg14 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant14), tailleMax);
			ft_boucle_f13_big(flag);
		}
		i14++;
	}
}

void	ft_boucle_f15_big(int flag[26])
{
	int testLarg15;
	int testHaut15;

	testHaut15 = 0;
	testLarg15 = 0;
	i15 = 0;
	if (flag[15] == 0)
	{
		clean15 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant15 = nbrCourant16 + 1;
		flag[14] = 1;
	}
	ft_strcpy_int(clean15, tmpCalc, tailleMax * tailleMax);
	while (i15 < iterMax)
	{
		tampon = resitue(clean15, (4 * nbrCourant15), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant15], tailleMax, var,
				nbrCourant, (4 * nbrCourant15), i15);
		testHaut15 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		testLarg15 = abs_minus(calc_larg(tmpCalc, tailleMax), calc_haut(tmpCalc, tailleMax));
		if (testLarg15 < testMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant15), tailleMax);
			ft_boucle_f14_big(flag);
		}
		i15++;
	}
}
