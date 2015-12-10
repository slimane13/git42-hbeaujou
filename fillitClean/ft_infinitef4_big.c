/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/17/08 18:21:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:55:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_haut16;
	int			g_test_larg16;
	int			i16;
	static int	*backtrack;

	i16 = 0;
	g_test_larg16 = 0;
	g_test_haut16 = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[15] = g_nbr_crt[16] + 1;
		flag[15] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i16 < g_iter_max && g_test_haut16 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i16, &g_test_larg16, &g_test_haut16, 16);
		if (g_test_larg16 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[15]), g_taille_max);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		i16++;
	}
}

void	ft_boucle_f17_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg17;
	int			g_test_haut17;
	int			i17;
	static int	*backtrack;

	g_test_haut17 = 0;
	g_test_larg17 = 0;
	i17 = 0;
	if (flag[16] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[16] = g_nbr_crt[17] + 1;
		flag[16] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i17 < g_iter_max && g_test_haut17 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i17, &g_test_larg17, &g_test_haut17, 17);
		if (g_test_larg17 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[16]), g_taille_max);
			ft_boucle_f16_big(flag, g_nbr_crt);
		}
		i17++;
	}
}

void	ft_boucle_f18_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg18;
	int			g_test_haut18;
	int			i18;
	static int	*backtrack;

	g_test_haut18 = 0;
	g_test_larg18 = 0;
	i18 = 0;
	if (flag[17] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[17] = g_nbr_crt[18] + 1;
		flag[17] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i18 < g_iter_max && g_test_haut18 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i18, &g_test_larg18, &g_test_haut18, 18);
		if (g_test_larg18 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[17]), g_taille_max);
			ft_boucle_f17_big(flag, g_nbr_crt);
		}
		i18++;
	}
}

void	ft_boucle_f19_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg19;
	int			g_test_haut19;
	int			i19;
	static int	*backtrack;

	g_test_haut19 = 0;
	g_test_larg19 = 0;
	i19 = 0;
	if (flag[18] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[18] = g_nbr_crt[19] + 1;
		flag[18] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i19 < g_iter_max && g_test_haut19 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i19, &g_test_larg19, &g_test_haut19, 19);
		if (g_test_larg19 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[18]), g_taille_max);
			ft_boucle_f18_big(flag, g_nbr_crt);
		}
		i19++;
	}
}

void	ft_boucle_f20_big(int flag[26], int g_nbr_crt[26])
{
	int			g_test_larg20;
	int			g_test_haut20;
	int			i20;
	static int	*backtrack;

	g_test_haut20 = 0;
	g_test_larg20 = 0;
	i20 = 0;
	if (flag[19] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_crt[19] = g_nbr_crt[20] + 1;
		flag[19] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_taille_max * g_taille_max);
	while (i20 < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, i20, &g_test_larg20, &g_test_haut20, 20);
		if (g_test_larg20 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[19]), g_taille_max);
			ft_boucle_f19_big(flag, g_nbr_crt);
		}
		i20++;
	}
}
