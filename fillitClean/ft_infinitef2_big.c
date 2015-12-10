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

void	ft_boucle_f6_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_h6;
	int			g_t_l6;
	int			i6;
	static int	*backtrack;

	i6 = 0;
	g_t_l6 = 0;
	g_t_h6 = 0;
	if (flag[5] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[5] = g_nbr_crt[6] + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i6 < g_iter_max && g_t_h6 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i6, &g_t_l6, &g_t_h6, 6);
		if (g_t_l6 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[5]), g_len_mx);
			ft_boucle_f5_big(flag, g_nbr_crt);
		}
		i6++;
	}
}

void	ft_boucle_f7_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l7;
	int			g_t_h7;
	int			i7;
	static int	*backtrack;

	g_t_h7 = 0;
	g_t_l7 = 0;
	i7 = 0;
	if (flag[6] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[6] = g_nbr_crt[7] + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i7 < g_iter_max && g_t_h7 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i7, &g_t_l7, &g_t_h7, 7);
		if (g_t_l7 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[6]), g_len_mx);
			ft_boucle_f6_big(flag, g_nbr_crt);
		}
		i7++;
	}
}

void	ft_boucle_f8_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l8;
	int			g_t_h8;
	int			i8;
	static int	*backtrack;

	g_t_h8 = 0;
	g_t_l8 = 0;
	i8 = 0;
	if (flag[7] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[7] = g_nbr_crt[8] + 1;
		flag[7] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i8 < g_iter_max && g_t_h8 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i8, &g_t_l8, &g_t_h8, 8);
		if (g_t_l8 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[7]), g_len_mx);
			ft_boucle_f7_big(flag, g_nbr_crt);
		}
		i8++;
	}
}

void	ft_boucle_f9_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l9;
	int			g_t_h9;
	int			i9;
	static int	*backtrack;

	g_t_h9 = 0;
	g_t_l9 = 0;
	i9 = 0;
	if (flag[8] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[8] = g_nbr_crt[9] + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i9 < g_iter_max && g_t_h9 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i9, &g_t_l9, &g_t_h9, 9);
		if (g_t_l9 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[8]), g_len_mx);
			ft_boucle_f8_big(flag, g_nbr_crt);
		}
		i9++;
	}
}

void	ft_boucle_f10_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l10;
	int			g_t_h10;
	int			i10;
	static int	*backtrack;

	g_t_h10 = 0;
	g_t_l10 = 0;
	i10 = 0;
	if (flag[9] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[9] = g_nbr_crt[10] + 1;
		flag[9] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i10 < g_iter_max && g_t_h10 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i10, &g_t_l10, &g_t_h10, 10);
		if (g_t_l10 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[9]), g_len_mx);
			ft_boucle_f9_big(flag, g_nbr_crt);
		}
		i10++;
	}
}
