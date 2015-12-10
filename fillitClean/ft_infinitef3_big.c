/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:09:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:53:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_h11;
	int			g_t_l11;
	int			i11;
	static int	*backtrack;

	i11 = 0;
	g_t_l11 = 0;
	g_t_h11 = 0;
	if (flag[10] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[10] = g_nbr_crt[11] + 1;
		flag[10] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i11 < g_iter_max && g_t_h11 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i11, &g_t_l11, &g_t_h11, 11);
		if (g_t_l11 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[10]), g_len_mx);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		i11++;
	}
}

void	ft_boucle_f12_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l12;
	int			g_t_h12;
	int			i12;
	static int	*backtrack;

	g_t_h12 = 0;
	g_t_l12 = 0;
	i12 = 0;
	if (flag[11] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[11] = g_nbr_crt[12] + 1;
		flag[11] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i12 < g_iter_max && g_t_h12 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i12, &g_t_l12, &g_t_h12, 12);
		if (g_t_l12 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[11]), g_len_mx);
			ft_boucle_f11_big(flag, g_nbr_crt);
		}
		i12++;
	}
}

void	ft_boucle_f13_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l13;
	int			g_t_h13;
	int			i13;
	static int	*backtrack;

	g_t_h13 = 0;
	g_t_l13 = 0;
	i13 = 0;
	if (flag[12] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[12] = g_nbr_crt[13] + 1;
		flag[12] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i13 < g_iter_max && g_t_h13 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i13, &g_t_l13, &g_t_h13, 13);
		if (g_t_l13 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[12]), g_len_mx);
			ft_boucle_f12_big(flag, g_nbr_crt);
		}
		i13++;
	}
}

void	ft_boucle_f14_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l14;
	int			g_t_h14;
	int			i14;
	static int	*backtrack;

	g_t_h14 = 0;
	g_t_l14 = 0;
	i14 = 0;
	if (flag[13] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[13] = g_nbr_crt[14] + 1;
		flag[13] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i14 < g_iter_max && g_t_h14 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i14, &g_t_l14, &g_t_h14, 14);
		if (g_t_l14 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[13]), g_len_mx);
			ft_boucle_f13_big(flag, g_nbr_crt);
		}
		i14++;
	}
}

void	ft_boucle_f15_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l15;
	int			g_t_h15;
	int			i15;
	static int	*backtrack;

	g_t_h15 = 0;
	g_t_l15 = 0;
	i15 = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[14] = g_nbr_crt[15] + 1;
		flag[14] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i15 < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, i15, &g_t_l15, &g_t_h15, 15);
		if (g_t_l15 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[14]), g_len_mx);
			ft_boucle_f14_big(flag, g_nbr_crt);
		}
		i15++;
	}
}
