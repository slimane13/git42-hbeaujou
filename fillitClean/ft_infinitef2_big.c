/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:37:26 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6_big(int flag[26])
{
	int test_haut6;
	int test_larg6;
	int i6;

	i6 = 0;
	test_larg6 = 0;
	test_haut6 = 0;
	if (flag[5] == 0)
	{
		clean6 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant6 = nbrCourant7 + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(clean6, tmpCalc, taille_max * taille_max);
	while (i6 < iter_max && test_haut6 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean6, (4 * nbrCourant6), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant6], taille_max, var,
				nbrCourant6, (4 * nbrCourant6), i6);
		test_larg6 = calc_larg(tmpCalc, taille_max);
		test_haut6 = calc_haut(tmpCalc, taille_max);
		if (test_larg6 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant6), taille_max);
			ft_boucle_f5_big(flag);
		}
		i6++;
	}
}

void	ft_boucle_f7_big(int flag[26])
{
	int test_larg7;
	int test_haut7;
	int i7;

	test_haut7 = 0;
	test_larg7 = 0;
	i7 = 0;
	if (flag[6] == 0)
	{
		clean7 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant7 = nbrCourant8 + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(clean7, tmpCalc, taille_max * taille_max);
	while (i7 < iter_max && test_haut7 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean7, (4 * nbrCourant7), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant7], taille_max, var,
				nbrCourant7, (4 * nbrCourant7), i7);
		test_haut7 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg7 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg7 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant7), taille_max);
			ft_boucle_f6_big(flag);
		}
		i7++;
	}
}

void	ft_boucle_f8_big(int flag[26])
{
	int test_larg8;
	int test_haut8;
	int i8;

	test_haut8 = 0;
	test_larg8 = 0;
	i8 = 0;
	if (flag[7] == 0)
	{
		clean8 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant8 = nbrCourant9 + 1;
		flag[7] = 1;
	}
	ft_strcpy_int(clean8, tmpCalc, taille_max * taille_max);
	while (i8 < iter_max && test_haut8 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean8, (4 * nbrCourant8), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant8], taille_max, var,
				nbrCourant8, (4 * nbrCourant8), i8);
		test_haut8 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg8 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg8 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant8), taille_max);
			ft_boucle_f7_big(flag);
		}
		i8++;
	}
}

void	ft_boucle_f9_big(int flag[26])
{
	int test_larg9;
	int test_haut9;
	int i9;

	test_haut9 = 0;
	test_larg9 = 0;
	i9 = 0;
	if (flag[8] == 0)
	{
		clean9 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant9 = nbrCourant10 + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(clean9, tmpCalc, taille_max * taille_max);
	while (i9 < iter_max && test_haut9 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean9, (4 * nbrCourant9), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant9], taille_max, var,
				nbrCourant9, (4 * nbrCourant9), i9);
		test_haut9 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg9 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg9 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant9), taille_max);
			ft_boucle_f8_big(flag);
		}
		i9++;
	}
}

void	ft_boucle_f10_big(int flag[26])
{
	int test_larg10;
	int test_haut10;
	int i10;

	test_haut10 = 0;
	test_larg10 = 0;
	i10 = 0;
	if (flag[9] == 0)
	{
		clean10 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant10 = nbrCourant11 + 1;
		flag[9] = 1;
	}
	ft_strcpy_int(clean10, tmpCalc, taille_max * taille_max);
	while (i10 < iter_max)
	{
		tampon = resitue(clean10, (4 * nbrCourant10), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant10], taille_max, var,
				nbrCourant10, (4 * nbrCourant10), i10);
		test_haut10 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg10 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg10 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant10), taille_max);
			ft_boucle_f9_big(flag);
		}
		i10++;
	}
}
