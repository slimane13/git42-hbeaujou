/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:36:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/07 17:43:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f1_special(int flag[26])
{
	int i;

	i = 0;
	clean = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	nbrCourant = nbrCourant2 + 1;
	if (nbrCourant == 0)
	{
		tampon[0] = -1;
		tampon[1] = -1;
		tampon[2] = -1;
		tampon[3] = -1;
	}
	tmpCalc = try_tetris_2_special(tampon, points[nbrCourant], tailleMax, var,
			nbrCourant, 4, i);
	testLarg = calc_larg(tmpCalc, tailleMax);
	testHaut = calc_haut(tmpCalc, tailleMax);
	absTmp = abs_minus(testLarg, testHaut);
	ft_strcpy_int(clean, tmpCalc, tailleMax * tailleMax);
}

void	ft_boucle_f1_special_2(int flag[26])
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
	while (i < iterMax && testHaut < hautMax1 + 4)
	{
		tmpCalc = try_tetris_2_2(tampon, points[nbrCourant], tailleMax, var,
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
		}
		i++;
	}
}

void	ft_boucle_f2_special(int flag[26])
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
	while (i2 < iterMax && testHaut2 < hautMax + 4)
	{
		tampon = resitue(clean2, (4 * (nbrCourant2 + 1)), tailleMax);
		if (i2 == 0)
		{
			tampon[0] = -1;
			tampon[1] = -1;
			tampon[2] = -1;
			tampon[3] = -1;
		}
		tmpCalc = try_tetris_2_2(tampon, points[nbrCourant2], tailleMax, var,
				nbrCourant2, (4 * (nbrCourant2 + 1)), i2);
		testLarg2 = calc_larg(tmpCalc, tailleMax);
		testHaut2 = calc_haut(tmpCalc, tailleMax);
		if (testLarg2 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * (nbrCourant2 + 1)), tailleMax);
			ft_boucle_f1_special_2(flag);
		}
		i2++;
	}
}

int		*try_tetris_2_special(int *t1, int *t2, int taille, int **spc, int k, int passage, int target)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	if (k != 0)
		rewind_tetris(t2, target);
	while (!isValid(t2, taille, spc[k]) || overlap_3(t1, t2, passage))
		assignSpot(t2);
	while (j < taille * taille)
	{
		while (i < passage && flag == 0)
		{
			if (j == t1[i] && flagTRY == 1)
			{
				final[j] = affichageLettre[j];
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
				final[j] = affichageLettre[j] + 1;
			else
				final[j] = 0;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (final);
}

int		*try_tetris_2_2(int *t1, int *t2, int taille, int **spc, int k, int passage, int target)
{
	int i;
	int j;
	int flag;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	flag = 0;
	if (k != 0)
		rewind_tetris(t2, 0);
	while ((!isValid(t2, taille, spc[k]) || overlap_3(t1, t2, passage)) && counter < 8)
	{
		assignSpot(t2);
		counter++;
	}
	while (j < taille * taille)
	{
		while (i < passage && flag == 0)
		{
			if (j == t1[i] && flagTRY == 1)
			{
				final[j] = affichageLettre[j];
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
				final[j] = affichageLettre[j] + 1;
			else
				final[j] = 0;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (final);
}
