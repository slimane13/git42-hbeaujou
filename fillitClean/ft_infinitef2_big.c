/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:58:12 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_haut6;
	int			g_test_larg6;
	int			i6;
	static int	*backtrack;

	i6 = 0;
	g_test_larg6 = 0;
	g_test_haut6 = 0;
	if (flag[5] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[5] = g_nbr_courant[6] + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i6 < g_iter_max && g_test_haut6 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i6, &g_test_larg6, &g_test_haut6, 6);
		if (g_test_larg6 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[5]), g_taille_max);
			ft_boucle_f5_big(flag, g_nbr_courant);
		}
		i6++;
	}
}

void	ft_boucle_f7_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_larg7;
	int			g_test_haut7;
	int			i7;
	static int	*backtrack;

	g_test_haut7 = 0;
	g_test_larg7 = 0;
	i7 = 0;
	if (flag[6] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[6] = g_nbr_courant[7] + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i7 < g_iter_max && g_test_haut7 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i7, &g_test_larg7, &g_test_haut7, 7);
		if (g_test_larg7 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[6]), g_taille_max);
			ft_boucle_f6_big(flag, g_nbr_courant);
		}
		i7++;
	}
}

void	ft_boucle_f8_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_larg8;
	int			g_test_haut8;
	int			i8;
	static int	*backtrack;

	g_test_haut8 = 0;
	g_test_larg8 = 0;
	i8 = 0;
	if (flag[7] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[7] = g_nbr_courant[8] + 1;
		flag[7] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i8 < g_iter_max && g_test_haut8 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i8, &g_test_larg8, &g_test_haut8, 8);
		if (g_test_larg8 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[7]), g_taille_max);
			ft_boucle_f7_big(flag, g_nbr_courant);
		}
		i8++;
	}
}

void	ft_boucle_f9_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_larg9;
	int			g_test_haut9;
	int			i9;
	static int	*backtrack;

	g_test_haut9 = 0;
	g_test_larg9 = 0;
	i9 = 0;
	if (flag[8] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[8] = g_nbr_courant[9] + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i9 < g_iter_max && g_test_haut9 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i9, &g_test_larg9, &g_test_haut9, 9);
		if (g_test_larg9 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[8]), g_taille_max);
			ft_boucle_f8_big(flag, g_nbr_courant);
		}
		i9++;
	}
}

void	ft_boucle_f10_big(int flag[26], int g_nbr_courant[26])
{
	int			g_test_larg10;
	int			g_test_haut10;
	int			i10;
	static int	*backtrack;

	g_test_haut10 = 0;
	g_test_larg10 = 0;
	i10 = 0;
	if (flag[9] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[9] = g_nbr_courant[10] + 1;
		flag[9] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i10 < g_iter_max && g_test_haut10 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_courant, i10, &g_test_larg10, &g_test_haut10, 10);
		if (g_test_larg10 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[9]), g_taille_max);
			ft_boucle_f9_big(flag, g_nbr_courant);
		}
		i10++;
	}
}
