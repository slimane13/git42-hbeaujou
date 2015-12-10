/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 13:19:28 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[5] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[5] = g_nbr_crt[6] + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 6);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[5]), g_len_mx);
			ft_boucle_f5_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f7_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[6] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[6] = g_nbr_crt[7] + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 7);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[6]), g_len_mx);
			ft_boucle_f6_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f8_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[7] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[7] = g_nbr_crt[8] + 1;
		flag[7] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 8);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[7]), g_len_mx);
			ft_boucle_f7_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f9_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[8] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[8] = g_nbr_crt[9] + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 9);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[8]), g_len_mx);
			ft_boucle_f8_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f10_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[9] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[9] = g_nbr_crt[10] + 1;
		flag[9] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 10);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[9]), g_len_mx);
			ft_boucle_f9_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}
