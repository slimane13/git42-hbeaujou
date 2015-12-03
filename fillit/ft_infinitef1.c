/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:18:16 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 12:20:33 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*tampon;
int	*tmpCalc;
int	*final;
int	largMax;
int hautMax;
int	testLarg;
int	testHaut;
int iterMax;
int absTmp;
int tailleMax;
int	**points;
int **var;
int nbrCourant;
int flagTRY;
int nbrTetri;

int i;
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

int flagF1;
int flagF2;
int flagF3;
int flagF4;
int flagF5;
int flagF6;
int flagF7;
int flagF8;
int flagF9;
int flagF10;
int flagF11;
int flagF12;
int flagF13;
int flagF14;
int flagF15;
int flagF16;
int flagF17;
int flagF18;
int flagF19;
int flagF20;
int flagF21;
int flagF22;
int flagF23;
int flagF24;
int flagF25;
int flagF26;

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

void	ft_boucle_f1(void)
{
	i = 0;
	if (flagF1 == 0)
	{
		clean = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF1 = 1;
	}
	hautMax = 100;
	while (i < iterMax && testHaut < hautMax + 1 && absTmp != nbrTetri)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		testLarg = calc_larg(tmpCalc, tailleMax);
		testHaut = calc_haut(tmpCalc, tailleMax);
		if ((testLarg < largMax && abs_minus(testLarg, testHaut) < absTmp) ||
				(testHaut < hautMax && abs_minus(testLarg, testHaut) < absTmp))
		{
			ft_strcpy_int(clean, tmpCalc, tailleMax * tailleMax);
			largMax = calc_larg(final, tailleMax);
			hautMax = calc_haut(final, tailleMax);
			absTmp = abs_minus(largMax, hautMax);
			printf("tailleMax   :   %d\n", tailleMax);
			printf("larg  :   %d\n", largMax);
			printf("haut  :   %d\n", hautMax);
			affiche(clean);
			printf("---------\n");
		}
		else
		{
//			printf(" i  :    %d\n", i);
//			printf(" i2  :    %d\n", i2);
//			printf(" i3  :    %d\n", i3);
//			printf(" i4  :    %d\n", i4);
		}
		i++;
	}
}

void	ft_boucle_f2(void)
{
	int	testHaut2;
	int	testLarg2;

	i2 = 0;
	testHaut2 = 0;
	testLarg2 = 0;
	if (flagF2 == 0)
	{
		clean2 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF2 = 1;
	}
	ft_strcpy_int(clean2, tmpCalc, tailleMax * tailleMax);
	while (i2 < iterMax && testHaut2 < hautMax + 1 && absTmp != nbrTetri)
	{
		tampon = resitue(clean2, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i2);
		testLarg2 = calc_larg(tmpCalc, tailleMax);
		testHaut2 = calc_haut(tmpCalc, tailleMax);
		if (testLarg2 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f1();
		}
		i2++;
	}
}

void	ft_boucle_f3(void)
{
	int	testHaut3;
	int	testLarg3;
	
	i3 = 0;
	testHaut3 = 0;
	testLarg3 = 0;
	if (flagF3 == 0)
	{
		clean3 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF3 = 1;
	}
	ft_strcpy_int(clean3, tmpCalc, tailleMax * tailleMax);
	while (i3 < iterMax && testHaut3 < hautMax + 1 && absTmp != nbrTetri)
	{
		tampon = resitue(clean3, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i3);
		testLarg3 = calc_larg(tmpCalc, tailleMax);
		testHaut3 = calc_haut(tmpCalc, tailleMax);
		if (testLarg3 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f2();
		}
		i3++;
	}
}

void	ft_boucle_f4(void)
{
	int	testHaut4;
	int	testLarg4;

	i4 = 0;
	testHaut4 = 0;
	testLarg4 = 0;
	if (flagF4 == 0)
	{
		clean4 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF4 = 1;
	}
	ft_strcpy_int(clean4, tmpCalc, tailleMax * tailleMax);
	while (i4 < iterMax && testHaut4 < hautMax + 1 && absTmp != nbrTetri)
	{
		tampon = resitue(clean4, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i4);
		testLarg4 = calc_larg(tmpCalc, tailleMax);
		testHaut4 = calc_haut(tmpCalc, tailleMax);
		if (testLarg4 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f3();
		}
		i4++;
	}
}

void	ft_boucle_f5(void)
{
	int	testHaut5;
	int	testLarg5;

	i5 = 0;
	testLarg5 = 0;
	testHaut5 = 0;
	if (flagF5 == 0)
	{
		clean5 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF5 = 1;
	}
	ft_strcpy_int(clean5, tmpCalc, tailleMax * tailleMax + 1);
	while (i5 < iterMax && testHaut5 < hautMax + 1 && absTmp != nbrTetri)
	{
		tampon = resitue(clean5, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i5);
		testLarg5 = calc_larg(tmpCalc, tailleMax);
		testHaut5 = calc_haut(tmpCalc, tailleMax);
		if (testLarg5 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
			ft_boucle_f4();
		}
		i5++;
	}
}
