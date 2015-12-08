/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/17/08 18:21:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:38:56 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16_big(int flag[26])
{
	int test_haut16;
	int test_larg16;
	int i16;

	i16 = 0;
	test_larg16 = 0;
	test_haut16 = 0;
	if (flag[15] == 0)
	{
		clean16 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant16 = nbrCourant17 + 1;
		flag[15] = 1;
	}
	ft_strcpy_int(clean16, tmpCalc, taille_max * taille_max);
	while (i16 < iter_max && test_haut16 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean16, (4 * nbrCourant16), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant16], taille_max, var,
				nbrCourant16, (4 * nbrCourant16), i16);
		test_larg16 = calc_larg(tmpCalc, taille_max);
		test_haut16 = calc_haut(tmpCalc, taille_max);
		if (test_larg16 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant16), taille_max);
			ft_boucle_f10_big(flag);
		}
		i16++;
	}
}

void	ft_boucle_f17_big(int flag[26])
{
	int test_larg17;
	int test_haut17;
	int i17;

	test_haut17 = 0;
	test_larg17 = 0;
	i17 = 0;
	if (flag[16] == 0)
	{
		clean17 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant17 = nbrCourant18 + 1;
		flag[16] = 1;
	}
	ft_strcpy_int(clean17, tmpCalc, taille_max * taille_max);
	while (i17 < iter_max && test_haut17 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean17, (4 * nbrCourant17), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant17], taille_max, var,
				nbrCourant17, (4 * nbrCourant17), i17);
		test_haut17 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg17 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg17 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant17), taille_max);
			ft_boucle_f16_big(flag);
		}
		i17++;
	}
}

void	ft_boucle_f18_big(int flag[26])
{
	int test_larg18;
	int test_haut18;
	int i18;

	test_haut18 = 0;
	test_larg18 = 0;
	i18 = 0;
	if (flag[17] == 0)
	{
		clean18 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant18 = nbrCourant19 + 1;
		flag[17] = 1;
	}
	ft_strcpy_int(clean18, tmpCalc, taille_max * taille_max);
	while (i18 < iter_max && test_haut18 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean18, (4 * nbrCourant18), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant18], taille_max, var,
				nbrCourant18, (4 * nbrCourant18), i18);
		test_haut18 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg18 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg18 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant18), taille_max);
			ft_boucle_f17_big(flag);
		}
		i18++;
	}
}

void	ft_boucle_f19_big(int flag[26])
{
	int test_larg19;
	int test_haut19;
	int i19;

	test_haut19 = 0;
	test_larg19 = 0;
	i19 = 0;
	if (flag[18] == 0)
	{
		clean19 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant19 = nbrCourant20 + 1;
		flag[18] = 1;
	}
	ft_strcpy_int(clean19, tmpCalc, taille_max * taille_max);
	while (i19 < iter_max && test_haut19 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean19, (4 * nbrCourant19), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant19], taille_max, var,
				nbrCourant19, (4 * nbrCourant19), i19);
		test_haut19 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg19 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg19 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant19), taille_max);
			ft_boucle_f18_big(flag);
		}
		i19++;
	}
}

void	ft_boucle_f20_big(int flag[26])
{
	int test_larg20;
	int test_haut20;
	int i20;

	test_haut20 = 0;
	test_larg20 = 0;
	i20 = 0;
	if (flag[19] == 0)
	{
		clean20 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant20 = nbrCourant21 + 1;
		flag[19] = 1;
	}
	ft_strcpy_int(clean20, tmpCalc, taille_max * taille_max);
	while (i20 < iter_max)
	{
		tampon = resitue(clean20, (4 * nbrCourant20), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant20], taille_max, var,
				nbrCourant, (4 * nbrCourant20), i20);
		test_haut20 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg20 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg20 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant20), taille_max);
			ft_boucle_f19_big(flag);
		}
		i20++;
	}
}
