/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef5_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2515/12/08 13:24:24 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:56:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f21_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_haut21;
	int			g_test_larg21;
	int			i21;
	static int	*backtrack;

	i21 = 0;
	g_test_larg21 = 0;
	g_test_haut21 = 0;
	if (flag[20] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[20] = g_nbr_crt[21] + 1;
		flag[20] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i21 < g_iter_max && g_test_haut21 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i21, &g_test_larg21, &g_test_haut21, 21);
		if (g_test_larg21 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[20]), g_taille_max);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		i21++;
	}
}

void	ft_boucle_f22_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg22;
	int			g_test_haut22;
	int			i22;
	static int	*backtrack;

	g_test_haut22 = 0;
	g_test_larg22 = 0;
	i22 = 0;
	if (flag[21] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[21] = g_nbr_crt[22] + 1;
		flag[21] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i22 < g_iter_max && g_test_haut22 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i22, &g_test_larg22, &g_test_haut22, 22);
		if (g_test_larg22 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[21]), g_taille_max);
			ft_boucle_f21_big(flag, g_nbr_crt);
		}
		i22++;
	}
}

void	ft_boucle_f23_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg23;
	int			g_test_haut23;
	int			i23;
	static int	*backtrack;

	g_test_haut23 = 0;
	g_test_larg23 = 0;
	i23 = 0;
	if (flag[22] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[22] = g_nbr_crt[23] + 1;
		flag[22] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i23 < g_iter_max && g_test_haut23 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i23, &g_test_larg23, &g_test_haut23, 23);
		if (g_test_larg23 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[22]), g_taille_max);
			ft_boucle_f22_big(flag, g_nbr_crt);
		}
		i23++;
	}
}

void	ft_boucle_f24_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg24;
	int			g_test_haut24;
	int			i24;
	static int	*backtrack;

	g_test_haut24 = 0;
	g_test_larg24 = 0;
	i24 = 0;
	if (flag[23] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[23] = g_nbr_crt[24] + 1;
		flag[23] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i24 < g_iter_max && g_test_haut24 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i24, &g_test_larg24, &g_test_haut24, 24);
		if (g_test_larg24 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[23]), g_taille_max);
			ft_boucle_f23_big(flag, g_nbr_crt);
		}
		i24++;
	}
}

void	ft_boucle_f25_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg25;
	int			g_test_haut25;
	int			i25;
	static int	*backtrack;

	g_test_haut25 = 0;
	g_test_larg25 = 0;
	i25 = 0;
	if (flag[24] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[24] = g_nbr_crt[25] + 1;
		flag[24] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i25 < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, i25, &g_test_larg25, &g_test_haut25, 25);
		if (g_test_larg25 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[24]), g_taille_max);
			ft_boucle_f24_big(flag, g_nbr_crt);
		}
		i25++;
	}
}
