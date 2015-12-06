/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 14:18:16 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 10:58:39 by hbeaujou         ###   ########.fr       */
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
int *affichageLettre;

//int i;
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

/*int flag[0];
int flag[1];
int flag[2];
int flag[3];
int flag[4];
int flagF6;
int flagF7;
int flagF8;
int flagF9;
int flag[0]0;
int flag[0]1;
int flag[0]2;
int flag[0]3;
int flag[0]4;
int flag[0]5;
int flag[0]6;
int flag[0]7;
int flag[0]8;
int flag[0]9;
int flag[1]0;
int flag[1]1;
int flag[1]2;
int flag[1]3;
int flag[1]4;
int flag[1]5;
int flag[1]6;
*/
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

void	ft_boucle_f1(int flag[26])
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
	hautMax1 = hautMax * 4;
	while (i < iterMax && testHaut < hautMax1 + 2  && absTmp != nbrTetri)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i);
		testLarg = calc_larg(tmpCalc, tailleMax);
		testHaut = calc_haut(tmpCalc, tailleMax);
//		if (i4 == 0 && i3 == 2 && i2 == 11 && (i == 24 || i == 25))
//		{
//			affiche(tmpCalc);
//			printf("larg :   %d\n", testLarg);
//			printf("haut :   %d\n", testHaut);
//			printf("-------------------\n");
//		}
		if ((testLarg < largMax && abs_minus(testLarg, testHaut) < absTmp) ||
				(testHaut < hautMax && abs_minus(testLarg, testHaut) < absTmp))
		{
			ft_strcpy_int(clean, tmpCalc, tailleMax * tailleMax);
			largMax = calc_larg(final, tailleMax);
			hautMax = calc_haut(final, tailleMax);
			absTmp = abs_minus(largMax, hautMax);
//			affiche(tmpCalc);
//			printf("larg :   %d\n", testLarg);
//			printf("haut :   %d\n", testHaut);
//			printf("-------------------\n");
		}
		else
		{
		}
		i++;
	}
}

void	ft_boucle_f2(int flag[26])
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
	while (i2 < iterMax && testHaut2 < hautMax + 2 && absTmp != nbrTetri)
	{
		tampon = resitue(clean2, (4 * nbrCourant2), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant2], tailleMax, var,
				nbrCourant2, (4 * nbrCourant2), i2);
		testLarg2 = calc_larg(tmpCalc, tailleMax);
		testHaut2 = calc_haut(tmpCalc, tailleMax);
		if (testLarg2 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant2), tailleMax);
			ft_boucle_f1(flag);
		}
		i2++;
	}
}

void	ft_boucle_f3(int flag[26])
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
	while (i3 < iterMax && testHaut3 < hautMax + 2 && absTmp != nbrTetri)
	{
		tampon = resitue(clean3, (4 * nbrCourant3), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant3], tailleMax, var,
				nbrCourant3, (4 * nbrCourant3), i3);
		testLarg3 = calc_larg(tmpCalc, tailleMax);
		testHaut3 = calc_haut(tmpCalc, tailleMax);
		if (testLarg3 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant3), tailleMax);
			ft_boucle_f2(flag);
		}
		i3++;
	}
}

void	ft_boucle_f4(int flag[26])
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
	while (i4 < iterMax && testHaut4 < hautMax + 2 && absTmp != nbrTetri)
	{
		tampon = resitue(clean4, (4 * nbrCourant4), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant4], tailleMax, var,
				nbrCourant4, (4 * nbrCourant4), i4);
		testLarg4 = calc_larg(tmpCalc, tailleMax);
		testHaut4 = calc_haut(tmpCalc, tailleMax);
		if (testLarg4 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant4), tailleMax);
			ft_boucle_f3(flag);
		}
		i4++;
	}
}

void	ft_boucle_f5(int flag[26])
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
	while (i5 < iterMax && testHaut5 < hautMax + 2 && absTmp != nbrTetri)
	{
		tampon = resitue(clean5, (4 * nbrCourant5), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant5], tailleMax, var,
				nbrCourant5, (4 * nbrCourant5), i5);
		testLarg5 = calc_larg(tmpCalc, tailleMax);
		testHaut5 = calc_haut(tmpCalc, tailleMax);
		if (testLarg5 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant5), tailleMax);
			ft_boucle_f4(flag);
		}
		i5++;
	}
}
