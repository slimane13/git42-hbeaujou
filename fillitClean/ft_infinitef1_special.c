/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:36:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 19:14:53 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f1_special(int flag[26], int nbr_courant[26])
{
	int i;
	static int	*backtrack;

	i = 0;
	backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
	nbr_courant[0] = nbr_courant[1] + 1;
	if (nbr_courant == 0)
	{
		tampon[0] = -1;
		tampon[1] = -1;
		tampon[2] = -1;
		tampon[3] = -1;
	}
	tmpCalc = try_tetris_2_special(tampon, points[nbr_courant[0]],
			taille_max, var, nbr_courant[0], 4, i);
	test_larg = calc_larg(tmpCalc, taille_max);
	test_haut = calc_haut(tmpCalc, taille_max);
	absTmp = abs_minus(test_larg, test_haut);
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
}

void	ft_boucle_f1_special_2(int flag[26], int nbr_courant[26])
{
	int i;
	int haut_max1;
	static int	*backtrack;

	i = 0;
	if (flag[0] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[0] = nbr_courant[1] + 1;
		flag[0] = 1;
	}
	haut_max1 = haut_max * 4;
	while (i < iter_max && test_haut < haut_max1 + 4)
	{
		tmpCalc = try_tetris_2_2(tampon, points[nbr_courant[0]],
				taille_max, var, nbr_courant[0], (4 * nbr_courant[0]), i);
		test_larg = calc_larg(tmpCalc, taille_max);
		test_haut = calc_haut(tmpCalc, taille_max);
		if ((test_larg < larg_max && abs_minus(test_larg, test_haut) < absTmp) ||
				(test_haut < haut_max && abs_minus(test_larg, test_haut) < absTmp))
		{
			ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
			larg_max = calc_larg(final, taille_max);
			haut_max = calc_haut(final, taille_max);
			absTmp = abs_minus(larg_max, haut_max);
		}
		i++;
	}
}

void	ft_boucle_f2_special(int flag[26], int nbr_courant[26])
{
	int i2;
	int	test_haut2;
	int	test_larg2;
	static int	*backtrack;

	i2 = 0;
	test_haut2 = 0;
	test_larg2 = 0;
	if (flag[1] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[1] = nbr_courant[2] + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i2 < iter_max && test_haut2 < haut_max + 4)
	{
		tampon = resitue(backtrack, (4 * (nbr_courant[1] + 1)), taille_max);
		if (i2 == 0)
		{
			tampon[0] = -1;
			tampon[1] = -1;
			tampon[2] = -1;
			tampon[3] = -1;
		}
		tmpCalc = try_tetris_2_2(tampon, points[nbr_courant[1]],
				taille_max, var, nbr_courant[1], (4 * (nbr_courant[1] + 1)), i2);
		test_larg2 = calc_larg(tmpCalc, taille_max);
		test_haut2 = calc_haut(tmpCalc, taille_max);
		if (test_larg2 < larg_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * (nbr_courant[1] + 1)), taille_max);
			ft_boucle_f1_special_2(flag, nbr_courant);
		}
		i2++;
	}
}

int		*try_tetris_2_special(int *t1, int *t2, int taille, int **spc,
		int k, int passage, int target)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	if (k != 0)
		rewind_tetris(t2, target);
	while (!is_valid(t2, taille, spc[k]) || overlap_3(t1, t2, passage))
		assign_spot(t2);
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

int		*try_tetris_2_2(int *t1, int *t2, int taille, int **spc,
		int k, int passage, int target)
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
	while ((!is_valid(t2, taille, spc[k]) ||
				overlap_3(t1, t2, passage)) && counter < 8)
	{
		assign_spot(t2);
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
