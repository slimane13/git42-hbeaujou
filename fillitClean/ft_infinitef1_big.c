/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 10:30:53 by hbeaujou         ###   ########.fr       */
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
int nbr_courant;
int flagTRY;
int nbrTetri;
int test_max;
int trouve;
int *affichageLettre;

void	ft_boucle_f1_big(int flag[26], int nbr_courant[26])
{
	int			i;
	int			haut_max1;
	static int	*backtrack;

	i = 0;
	if (flag[0] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[0] = nbr_courant[1] + 1;
		flag[0] = 1;
	}
	while (i < iter_max && test_haut < test_max + 4 && trouve == 0)
	{
		tmpCalc = try_tetris_2(tampon, points[nbr_courant[0]], taille_max, var,
				nbr_courant[0], (4 * nbr_courant[0]), i);
		test_larg = calc_larg(tmpCalc, taille_max);
		test_haut = calc_haut(tmpCalc, taille_max);
		absTmp = absc(test_haut, test_larg);
		if (absTmp <= test_max)
		{
			ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
			affiche(backtrack);
		}
		i++;
	}
}

void	ft_boucle_f2_big(int flag[26], int nbr_courant[26])
{
	int			test_haut2;
	int			test_larg2;
	int			i2;
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
	while (i2 < iter_max && test_haut2 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i2, &test_larg2, &test_haut2, 2);
		if (test_larg2 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[1]), taille_max);
			ft_boucle_f1_big(flag, nbr_courant);
		}
		i2++;
	}
}

void	ft_boucle_f3_big(int flag[26], int nbr_courant[26])
{
	int			test_haut3;
	int			test_larg3;
	int			i3;
	static int	*backtrack;

	i3 = 0;
	test_haut3 = 0;
	test_larg3 = 0;
	if (flag[2] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[2] = nbr_courant[3] + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i3 < iter_max && test_haut3 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i3, &test_larg3, &test_haut3, 3);
		if (test_larg3 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[2]), taille_max);
			ft_boucle_f2_big(flag, nbr_courant);
		}
		i3++;
	}
}

void	ft_boucle_f4_big(int flag[26], int nbr_courant[26])
{
	int			test_haut4;
	int			test_larg4;
	int			i4;
	static int	*backtrack;

	i4 = 0;
	test_haut4 = 0;
	test_larg4 = 0;
	if (flag[3] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[3] = nbr_courant[4] + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i4 < iter_max && test_haut4 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i4, &test_larg4, &test_haut4, 4);
		if (test_larg4 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[3]), taille_max);
			ft_boucle_f3_big(flag, nbr_courant);
		}
		i4++;
	}
}

void	ft_boucle_f5_big(int flag[26], int nbr_courant[26])
{
	int			test_haut5;
	int			test_larg5;
	int			i5;
	static int	*backtrack;

	i5 = 0;
	test_larg5 = 0;
	test_haut5 = 0;
	if (flag[4] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[4] = nbr_courant[5] + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max + 1);
	while (i5 < iter_max && test_haut5 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i5, &test_larg5, &test_haut5, 5);
		if (test_larg5 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[4]), taille_max);
			ft_boucle_f4_big(flag, nbr_courant);
		}
		i5++;
	}
}
