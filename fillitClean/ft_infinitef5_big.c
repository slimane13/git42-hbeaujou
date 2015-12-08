/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef5_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2515/12/08 13:24:24 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:18:44 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f21_big(int flag[26], int nbrCourant[26])
{
	int test_haut21;
	int test_larg21;
	int i21;

	i21 = 0;
	test_larg21 = 0;
	test_haut21 = 0;
	if (flag[20] == 0)
	{
		clean21 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[20] = nbrCourant[21] + 1;
		flag[20] = 1;
	}
	ft_strcpy_int(clean21, tmpCalc, taille_max * taille_max);
	while (i21 < iter_max && test_haut21 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean21, (4 * nbrCourant[20]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[20]], taille_max, var,
				nbrCourant[20], (4 * nbrCourant[20]), i21);
		test_larg21 = calc_larg(tmpCalc, taille_max);
		test_haut21 = calc_haut(tmpCalc, taille_max);
		if (test_larg21 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[20]), taille_max);
			ft_boucle_f10_big(flag, nbrCourant);
		}
		i21++;
	}
}

void	ft_boucle_f22_big(int flag[26], int nbrCourant[26])
{
	int test_larg22;
	int test_haut22;
	int i22;

	test_haut22 = 0;
	test_larg22 = 0;
	i22 = 0;
	if (flag[21] == 0)
	{
		clean22 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[21] = nbrCourant[22] + 1;
		flag[21] = 1;
	}
	ft_strcpy_int(clean22, tmpCalc, taille_max * taille_max);
	while (i22 < iter_max && test_haut22 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean22, (4 * nbrCourant[21]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[21]], taille_max, var,
				nbrCourant[21], (4 * nbrCourant[21]), i22);
		test_haut22 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg22 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg22 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[21]), taille_max);
			ft_boucle_f21_big(flag, nbrCourant);
		}
		i22++;
	}
}

void	ft_boucle_f23_big(int flag[26], int nbrCourant[26])
{
	int test_larg23;
	int test_haut23;
	int i23;

	test_haut23 = 0;
	test_larg23 = 0;
	i23 = 0;
	if (flag[22] == 0)
	{
		clean23 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[22] = nbrCourant[23] + 1;
		flag[22] = 1;
	}
	ft_strcpy_int(clean23, tmpCalc, taille_max * taille_max);
	while (i23 < iter_max && test_haut23 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean23, (4 * nbrCourant[22]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[22]], taille_max, var,
				nbrCourant[22], (4 * nbrCourant[22]), i23);
		test_haut23 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg23 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg23 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[22]), taille_max);
			ft_boucle_f22_big(flag, nbrCourant);
		}
		i23++;
	}
}

void	ft_boucle_f24_big(int flag[26], int nbrCourant[26])
{
	int test_larg24;
	int test_haut24;
	int i24;

	test_haut24 = 0;
	test_larg24 = 0;
	i24 = 0;
	if (flag[23] == 0)
	{
		clean24 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[23] = nbrCourant[24] + 1;
		flag[23] = 1;
	}
	ft_strcpy_int(clean24, tmpCalc, taille_max * taille_max);
	while (i24 < iter_max && test_haut24 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean24, (4 * nbrCourant[23]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[23]], taille_max, var,
				nbrCourant[23], (4 * nbrCourant[23]), i24);
		test_haut24 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg24 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg24 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[23]), taille_max);
			ft_boucle_f23_big(flag, nbrCourant);
		}
		i24++;
	}
}

void	ft_boucle_f25_big(int flag[26], int nbrCourant[26])
{
	int test_larg25;
	int test_haut25;
	int i25;

	test_haut25 = 0;
	test_larg25 = 0;
	i25 = 0;
	if (flag[24] == 0)
	{
		clean25 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[24] = nbrCourant[25] + 1;
		flag[24] = 1;
	}
	ft_strcpy_int(clean25, tmpCalc, taille_max * taille_max);
	while (i25 < iter_max)
	{
		tampon = resitue(clean25, (4 * nbrCourant[24]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[24]], taille_max, var,
				nbrCourant[0], (4 * nbrCourant[24]), i25);
		test_haut25 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		test_larg25 = abs_minus(calc_larg(tmpCalc, taille_max), calc_haut(tmpCalc, taille_max));
		if (test_larg25 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant[24]), taille_max);
			ft_boucle_f24_big(flag, nbrCourant);
		}
		i25++;
	}
}
