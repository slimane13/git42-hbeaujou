/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:09:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:18:33 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11_big(int flag[26], int nbrCourant[26])
{
	int test_haut11;
	int test_larg11;
	int i11;

	i11 = 0;
	test_larg11 = 0;
	test_haut11 = 0;
	if (flag[10] == 0)
	{
		clean11 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[10] = nbrCourant[11] + 1;
		flag[10] = 1;
	}
	ft_strcpy_int(clean11, tmpCalc, taille_max * taille_max);
	while (i11 < iter_max && test_haut11 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean11, (4 * nbrCourant[10]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[10]], taille_max, var,
				nbrCourant[10], (4 * nbrCourant[10]), i11);
		test_larg11 = calc_larg(tmpCalc, taille_max);
		test_haut11 = calc_haut(tmpCalc, taille_max);
		if (test_larg11 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[10]), taille_max);
			ft_boucle_f10_big(flag, nbrCourant);
		}
		i11++;
	}
}

void	ft_boucle_f12_big(int flag[26], int nbrCourant[26])
{
	int test_larg12;
	int test_haut12;
	int i12;

	test_haut12 = 0;
	test_larg12 = 0;
	i12 = 0;
	if (flag[11] == 0)
	{
		clean12 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[11] = nbrCourant[12] + 1;
		flag[11] = 1;
	}
	ft_strcpy_int(clean12, tmpCalc, taille_max * taille_max);
	while (i12 < iter_max && test_haut12 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean12, (4 * nbrCourant[11]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[11]], taille_max, var,
				nbrCourant[11], (4 * nbrCourant[11]), i12);
		test_haut12 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg12 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg12 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[11]), taille_max);
			ft_boucle_f11_big(flag, nbrCourant);
		}
		i12++;
	}
}

void	ft_boucle_f13_big(int flag[26], int nbrCourant[26])
{
	int test_larg13;
	int test_haut13;
	int i13;

	test_haut13 = 0;
	test_larg13 = 0;
	i13 = 0;
	if (flag[12] == 0)
	{
		clean13 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[12] = nbrCourant[13] + 1;
		flag[12] = 1;
	}
	ft_strcpy_int(clean13, tmpCalc, taille_max * taille_max);
	while (i13 < iter_max && test_haut13 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean13, (4 * nbrCourant[12]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[12]], taille_max, var,
				nbrCourant[12], (4 * nbrCourant[12]), i13);
		test_haut13 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg13 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg13 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[12]), taille_max);
			ft_boucle_f12_big(flag, nbrCourant);
		}
		i13++;
	}
}

void	ft_boucle_f14_big(int flag[26], int nbrCourant[26])
{
	int test_larg14;
	int test_haut14;
	int i14;

	test_haut14 = 0;
	test_larg14 = 0;
	i14 = 0;
	if (flag[13] == 0)
	{
		clean14 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[13] = nbrCourant[14] + 1;
		flag[13] = 1;
	}
	ft_strcpy_int(clean14, tmpCalc, taille_max * taille_max);
	while (i14 < iter_max && test_haut14 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean14, (4 * nbrCourant[13]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[13]], taille_max, var,
				nbrCourant[13], (4 * nbrCourant[13]), i14);
		test_haut14 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg14 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg14 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[13]), taille_max);
			ft_boucle_f13_big(flag, nbrCourant);
		}
		i14++;
	}
}

void	ft_boucle_f15_big(int flag[26], int nbrCourant[26])
{
	int test_larg15;
	int test_haut15;
	int i15;

	test_haut15 = 0;
	test_larg15 = 0;
	i15 = 0;
	if (flag[15] == 0)
	{
		clean15 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[14] = nbrCourant[15] + 1;
		flag[14] = 1;
	}
	ft_strcpy_int(clean15, tmpCalc, taille_max * taille_max);
	while (i15 < iter_max)
	{
		tampon = resitue(clean15, (4 * nbrCourant[14]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[14]], taille_max, var,
				nbrCourant[0], (4 * nbrCourant[14]), i15);
		test_haut15 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg15 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg15 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[14]), taille_max);
			ft_boucle_f14_big(flag, nbrCourant);
		}
		i15++;
	}
}
