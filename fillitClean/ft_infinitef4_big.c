/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/17/08 18:21:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 13:26:07 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[0] = 0;
	boucle[1] = 0;
	boucle[2] = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[15] = g_nbr_crt[16] + 1;
		flag[15] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2] < g_iter_max && boucle[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, boucle, 16);
		if (boucle[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[15]), g_len_mx);
			ft_boucle_f10_big(flag, g_nbr_crt);
		}
		boucle[2]++;
	}
}

void	ft_boucle_f17_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[0] = 0;
	boucle[1] = 0;
	boucle[2] = 0;
	if (flag[16] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[16] = g_nbr_crt[17] + 1;
		flag[16] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2] < g_iter_max && boucle[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, boucle, 17);
		if (boucle[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[16]), g_len_mx);
			ft_boucle_f16_big(flag, g_nbr_crt);
		}
		boucle[2]++;
	}
}

void	ft_boucle_f18_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[0] = 0;
	boucle[1] = 0;
	boucle[2] = 0;
	if (flag[17] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[17] = g_nbr_crt[18] + 1;
		flag[17] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2] < g_iter_max && boucle[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, boucle, 18);
		if (boucle[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[17]), g_len_mx);
			ft_boucle_f17_big(flag, g_nbr_crt);
		}
		boucle[2]++;
	}
}

void	ft_boucle_f19_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[0] = 0;
	boucle[1] = 0;
	boucle[2] = 0;
	if (flag[18] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[18] = g_nbr_crt[19] + 1;
		flag[18] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2] < g_iter_max && boucle[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, boucle, 19);
		if (boucle[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[18]), g_len_mx);
			ft_boucle_f18_big(flag, g_nbr_crt);
		}
		boucle[2]++;
	}
}

void	ft_boucle_f20_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[0] = 0;
	boucle[1] = 0;
	boucle[2] = 0;
	if (flag[19] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[19] = g_nbr_crt[20] + 1;
		flag[19] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2] < g_iter_max)
	{
		calc(backtrack, g_nbr_crt, boucle, 20);
		if (boucle[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[19]), g_len_mx);
			ft_boucle_f19_big(flag, g_nbr_crt);
		}
		boucle[2]++;
	}
}
