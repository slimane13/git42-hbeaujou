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

int	*g_tampon;
int	*g_tmpCalc;
int	*g_final;
int	g_larg_max;
int g_haut_max;
int	g_test_larg;
int	g_test_haut;
int g_iter_max;
int g_absTmp;
int g_taille_max;
int	**g_points;
int **g_var;
int g_nbr_courant;
int g_flagTRY;
int g_nbrTetri;
int g_test_max;
int g_trouve;
int *g_affichageLettre;

void	ft_boucle_f1_big(int flag[26], int g_nbr_courant[26])
{
	int			i;
	int			g_haut_max1;
	static int	*backtrack;

	i = 0;
	if (flag[0] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[0] = g_nbr_courant[1] + 1;
		flag[0] = 1;
	}
	while (i < g_iter_max && g_test_haut < g_test_max + 4 && g_trouve == 0)
	{
		g_tmpCalc = try_tetris_2(g_tampon, g_points[g_nbr_courant[0]], g_taille_max, g_var,
				g_nbr_courant[0], (4 * g_nbr_courant[0]), i);
		g_test_larg = calc_larg(g_tmpCalc, g_taille_max);
		g_test_haut = calc_haut(g_tmpCalc, g_taille_max);
		g_absTmp = absc(g_test_haut, g_test_larg);
		if (g_absTmp <= g_test_max)
		{
			ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
			affiche(backtrack);
		}
		i++;
	}
}

void	ft_boucle_f2_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_haut2;
	int			g_test_larg2;
	int			i2;
	static int	*backtrack;

	i2 = 0;
	g_test_haut2 = 0;
	g_test_larg2 = 0;
	if (flag[1] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[1] = g_nbr_courant[2] + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i2 < g_iter_max && g_test_haut2 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i2, &g_test_larg2, &g_test_haut2, 2);
		if (g_test_larg2 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[1]), g_taille_max);
			ft_boucle_f1_big(flag, g_nbr_courant);
		}
		i2++;
	}
}

void	ft_boucle_f3_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_haut3;
	int			g_test_larg3;
	int			i3;
	static int	*backtrack;

	i3 = 0;
	g_test_haut3 = 0;
	g_test_larg3 = 0;
	if (flag[2] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[2] = g_nbr_courant[3] + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i3 < g_iter_max && g_test_haut3 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i3, &g_test_larg3, &g_test_haut3, 3);
		if (g_test_larg3 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[2]), g_taille_max);
			ft_boucle_f2_big(flag, g_nbr_courant);
		}
		i3++;
	}
}

void	ft_boucle_f4_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_haut4;
	int			g_test_larg4;
	int			i4;
	static int	*backtrack;

	i4 = 0;
	g_test_haut4 = 0;
	g_test_larg4 = 0;
	if (flag[3] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[3] = g_nbr_courant[4] + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i4 < g_iter_max && g_test_haut4 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i4, &g_test_larg4, &g_test_haut4, 4);
		if (g_test_larg4 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[3]), g_taille_max);
			ft_boucle_f3_big(flag, g_nbr_courant);
		}
		i4++;
	}
}

void	ft_boucle_f5_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_haut5;
	int			g_test_larg5;
	int			i5;
	static int	*backtrack;

	i5 = 0;
	g_test_larg5 = 0;
	g_test_haut5 = 0;
	if (flag[4] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[4] = g_nbr_courant[5] + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max + 1);
	while (i5 < g_iter_max && g_test_haut5 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i5, &g_test_larg5, &g_test_haut5, 5);
		if (g_test_larg5 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[4]), g_taille_max);
			ft_boucle_f4_big(flag, g_nbr_courant);
		}
		i5++;
	}
}
