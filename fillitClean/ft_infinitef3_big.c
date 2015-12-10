/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:09:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 14:47:24 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[10] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[10] = g_nbr_crt[11] + 1;
		flag[10] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 11);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[10]), g_len_mx);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f12_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[11] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[11] = g_nbr_crt[12] + 1;
		flag[11] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 12);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[11]), g_len_mx);
			ft_boucle_f11_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f13_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[12] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[12] = g_nbr_crt[13] + 1;
		flag[12] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 13);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[12]), g_len_mx);
			ft_boucle_f12_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f14_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[13] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[13] = g_nbr_crt[14] + 1;
		flag[13] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 14);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[13]), g_len_mx);
			ft_boucle_f13_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f15_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[14] = g_nbr_crt[15] + 1;
		flag[14] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, bcl, 15);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[14]), g_len_mx);
			ft_boucle_f14_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}
