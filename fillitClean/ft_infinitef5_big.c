/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef5_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2515/12/08 13:24:24 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 13:27:54 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f21_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[20] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[20] = g_nbr_crt[21] + 1;
		flag[20] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 21);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[20]), g_len_mx);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f22_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[21] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[21] = g_nbr_crt[22] + 1;
		flag[21] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 22);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[21]), g_len_mx);
			ft_boucle_f21_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f23_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[22] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[22] = g_nbr_crt[23] + 1;
		flag[22] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 23);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[22]), g_len_mx);
			ft_boucle_f22_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f24_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[23] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[23] = g_nbr_crt[24] + 1;
		flag[23] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 24);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[23]), g_len_mx);
			ft_boucle_f23_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f25_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[24] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[24] = g_nbr_crt[25] + 1;
		flag[24] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, bcl, 25);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[24]), g_len_mx);
			ft_boucle_f24_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}
