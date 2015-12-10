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
	int			g_t_h21;
	int			g_t_l21;
	int			i21;
	static int	*backtrack;

	i21 = 0;
	g_t_l21 = 0;
	g_t_h21 = 0;
	if (flag[20] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[20] = g_nbr_crt[21] + 1;
		flag[20] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i21 < g_iter_max && g_t_h21 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i21, &g_t_l21, &g_t_h21, 21);
		if (g_t_l21 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[20]), g_len_mx);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		i21++;
	}
}

void	ft_boucle_f22_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l22;
	int			g_t_h22;
	int			i22;
	static int	*backtrack;

	g_t_h22 = 0;
	g_t_l22 = 0;
	i22 = 0;
	if (flag[21] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[21] = g_nbr_crt[22] + 1;
		flag[21] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i22 < g_iter_max && g_t_h22 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i22, &g_t_l22, &g_t_h22, 22);
		if (g_t_l22 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[21]), g_len_mx);
			ft_boucle_f21_big(flag, g_nbr_crt);
		}
		i22++;
	}
}

void	ft_boucle_f23_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l23;
	int			g_t_h23;
	int			i23;
	static int	*backtrack;

	g_t_h23 = 0;
	g_t_l23 = 0;
	i23 = 0;
	if (flag[22] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[22] = g_nbr_crt[23] + 1;
		flag[22] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i23 < g_iter_max && g_t_h23 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i23, &g_t_l23, &g_t_h23, 23);
		if (g_t_l23 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[22]), g_len_mx);
			ft_boucle_f22_big(flag, g_nbr_crt);
		}
		i23++;
	}
}

void	ft_boucle_f24_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l24;
	int			g_t_h24;
	int			i24;
	static int	*backtrack;

	g_t_h24 = 0;
	g_t_l24 = 0;
	i24 = 0;
	if (flag[23] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[23] = g_nbr_crt[24] + 1;
		flag[23] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i24 < g_iter_max && g_t_h24 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i24, &g_t_l24, &g_t_h24, 24);
		if (g_t_l24 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[23]), g_len_mx);
			ft_boucle_f23_big(flag, g_nbr_crt);
		}
		i24++;
	}
}

void	ft_boucle_f25_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_l25;
	int			g_t_h25;
	int			i25;
	static int	*backtrack;

	g_t_h25 = 0;
	g_t_l25 = 0;
	i25 = 0;
	if (flag[24] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[24] = g_nbr_crt[25] + 1;
		flag[24] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i25 < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, i25, &g_t_l25, &g_t_h25, 25);
		if (g_t_l25 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[24]), g_len_mx);
			ft_boucle_f24_big(flag, g_nbr_crt);
		}
		i25++;
	}
}
