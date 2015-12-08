/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/17/08 18:21:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:18:40 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16_big(int flag[26], int nbrCourant[26])
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
		nbrCourant[15] = nbrCourant[16] + 1;
		flag[15] = 1;
	}
	ft_strcpy_int(clean16, tmpCalc, taille_max * taille_max);
	while (i16 < iter_max && test_haut16 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean16, (4 * nbrCourant[15]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[15]], taille_max, var,
				nbrCourant[15], (4 * nbrCourant[15]), i16);
		test_larg16 = calc_larg(tmpCalc, taille_max);
		test_haut16 = calc_haut(tmpCalc, taille_max);
		if (test_larg16 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[15]), taille_max);
			ft_boucle_f10_big(flag, nbrCourant);
		}
		i16++;
	}
}

void	ft_boucle_f17_big(int flag[26], int nbrCourant[26])
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
		nbrCourant[16] = nbrCourant[17] + 1;
		flag[16] = 1;
	}
	ft_strcpy_int(clean17, tmpCalc, taille_max * taille_max);
	while (i17 < iter_max && test_haut17 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean17, (4 * nbrCourant[16]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[16]], taille_max, var,
				nbrCourant[16], (4 * nbrCourant[16]), i17);
		test_haut17 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg17 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg17 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[16]), taille_max);
			ft_boucle_f16_big(flag, nbrCourant);
		}
		i17++;
	}
}

void	ft_boucle_f18_big(int flag[26], int nbrCourant[26])
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
		nbrCourant[17] = nbrCourant[18] + 1;
		flag[17] = 1;
	}
	ft_strcpy_int(clean18, tmpCalc, taille_max * taille_max);
	while (i18 < iter_max && test_haut18 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean18, (4 * nbrCourant[17]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[17]], taille_max, var,
				nbrCourant[17], (4 * nbrCourant[17]), i18);
		test_haut18 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg18 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg18 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[17]), taille_max);
			ft_boucle_f17_big(flag, nbrCourant);
		}
		i18++;
	}
}

void	ft_boucle_f19_big(int flag[26], int nbrCourant[26])
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
		nbrCourant[18] = nbrCourant[19] + 1;
		flag[18] = 1;
	}
	ft_strcpy_int(clean19, tmpCalc, taille_max * taille_max);
	while (i19 < iter_max && test_haut19 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean19, (4 * nbrCourant[18]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[18]], taille_max, var,
				nbrCourant[18], (4 * nbrCourant[18]), i19);
		test_haut19 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg19 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg19 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[18]), taille_max);
			ft_boucle_f18_big(flag, nbrCourant);
		}
		i19++;
	}
}

void	ft_boucle_f20_big(int flag[26], int nbrCourant[26])
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
		nbrCourant[19] = nbrCourant[20] + 1;
		flag[19] = 1;
	}
	ft_strcpy_int(clean20, tmpCalc, taille_max * taille_max);
	while (i20 < iter_max)
	{
		tampon = resitue(clean20, (4 * nbrCourant[19]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[19]], taille_max, var,
				nbrCourant[0], (4 * nbrCourant[19]), i20);
		test_haut20 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg20 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg20 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[19]), taille_max);
			ft_boucle_f19_big(flag, nbrCourant);
		}
		i20++;
	}
}
