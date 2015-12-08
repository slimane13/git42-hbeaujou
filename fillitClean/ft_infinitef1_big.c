/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:29:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*tampon;
int	*tmpCalc;
int	*final;
int	larg_max;
int haut_max;
int	test_larg;
int	test_haut;
int iter_max;
int absTmp;
int taille_max;
int	**points;
int **var;
int nbrCourant;
int flagTRY;
int nbrTetri;
int test_max;
int trouve;
int *affichageLettre;

int i2;
int i3;
int i4;
int i5;
int i6;
int i7;
int i8;
int i9;
int i10;
int i11;
int i12;
int i13;
int i14;
int i15;
int i16;
int i17;
int i18;
int i19;
int i20;
int i21;
int i22;
int i23;
int i24;
int i25;
int i26;

int	nbrCourant1;
int	nbrCourant2;
int	nbrCourant3;
int	nbrCourant4;
int	nbrCourant5;
int	nbrCourant6;
int	nbrCourant7;
int	nbrCourant8;
int	nbrCourant9;
int	nbrCourant10;
int	nbrCourant11;
int	nbrCourant12;
int	nbrCourant13;
int	nbrCourant14;
int	nbrCourant15;
int	nbrCourant16;
int	nbrCourant17;
int	nbrCourant18;
int	nbrCourant19;
int	nbrCourant20;
int	nbrCourant21;
int	nbrCourant22;
int	nbrCourant23;
int	nbrCourant24;
int	nbrCourant25;
int	nbrCourant26;
int	nbrCourant27;

int *clean;
int *clean2;
int *clean3;
int *clean4;
int *clean5;
int *clean6;
int *clean7;
int *clean8;
int *clean9;
int *clean10;
int *clean11;
int *clean12;
int *clean13;
int *clean14;
int *clean15;
int *clean16;
int *clean17;
int *clean18;
int *clean19;
int *clean20;
int *clean21;
int *clean22;
int *clean23;
int *clean24;
int *clean25;
int *clean26;

void	ft_boucle_f1_big(int flag[26])
{
	int i;
	int haut_max1;

	i = 0;
	if (flag[0] == 0)
	{
		clean = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant = nbrCourant2 + 1;
		flag[0] = 1;
	}
	while (i < iter_max && test_haut < test_max + 4 && trouve == 0)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], taille_max, var,
				nbrCourant, (4 * nbrCourant), i);
		test_larg = calc_larg(tmpCalc, taille_max);
		test_haut = calc_haut(tmpCalc, taille_max);
		absTmp = abs_minus(test_haut, test_larg);
		if (absTmp <= test_max)
		{
			ft_strcpy_int(clean, tmpCalc, taille_max * taille_max);
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
	int	test_haut2;
	int	test_larg2;

	i2 = 0;
	test_haut2 = 0;
	test_larg2 = 0;
	if (flag[1] == 0)
	{
		clean2 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant2 = nbrCourant3 + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(clean2, tmpCalc, taille_max * taille_max);
	while (i2 < iter_max && test_haut2 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean2, (4 * nbrCourant2), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant2], taille_max, var,
				nbrCourant2, (4 * nbrCourant2), i2);
		test_larg2 = calc_larg(tmpCalc, taille_max);
		test_haut2 = calc_haut(tmpCalc, taille_max);
		if (test_larg2 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant2), taille_max);
			ft_boucle_f1_big(flag);
		}
		i2++;
	}
}

void	ft_boucle_f3_big(int flag[26])
{
	int	test_haut3;
	int	test_larg3;
	
	i3 = 0;
	test_haut3 = 0;
	test_larg3 = 0;
	if (flag[2] == 0)
	{
		clean3 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant3 = nbrCourant4 + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(clean3, tmpCalc, taille_max * taille_max);
	while (i3 < iter_max && test_haut3 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean3, (4 * nbrCourant3), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant3], taille_max, var,
				nbrCourant3, (4 * nbrCourant3), i3);
		test_larg3 = calc_larg(tmpCalc, taille_max);
		test_haut3 = calc_haut(tmpCalc, taille_max);
		if (test_larg3 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant3), taille_max);
			ft_boucle_f2_big(flag);
		}
		i3++;
	}
}

void	ft_boucle_f4_big(int flag[26])
{
	int	test_haut4;
	int	test_larg4;

	i4 = 0;
	test_haut4 = 0;
	test_larg4 = 0;
	if (flag[3] == 0)
	{
		clean4 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant4 = nbrCourant5 + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(clean4, tmpCalc, taille_max * taille_max);
	while (i4 < iter_max && test_haut4 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean4, (4 * nbrCourant4), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant4], taille_max, var,
				nbrCourant4, (4 * nbrCourant4), i4);
		test_larg4 = calc_larg(tmpCalc, taille_max);
		test_haut4 = calc_haut(tmpCalc, taille_max);
		if (test_larg4 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant4), taille_max);
			ft_boucle_f3_big(flag);
		}
		i4++;
	}
}

void	ft_boucle_f5_big(int flag[26])
{
	int	test_haut5;
	int	test_larg5;

	i5 = 0;
	test_larg5 = 0;
	test_haut5 = 0;
	if (flag[4] == 0)
	{
		clean5 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant5 = nbrCourant6 + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(clean5, tmpCalc, taille_max * taille_max + 1);
	while (i5 < iter_max && test_haut5 < test_max + 1 && trouve == 0)
	{
		tampon = resitue(clean5, (4 * nbrCourant5), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant5], taille_max, var,
				nbrCourant5, (4 * nbrCourant5), i5);
		test_larg5 = calc_larg(tmpCalc, taille_max);
		test_haut5 = calc_haut(tmpCalc, taille_max);
		if (test_larg5 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant5), taille_max);
			ft_boucle_f4_big(flag);
		}
		i5++;
	}
}
