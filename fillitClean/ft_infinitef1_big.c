/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 17:38:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*g_backtrack_sp2;
int	*g_tampon;
int	*g_tmp_calc;
int	*g_final;
int	g_larg_max;
int g_haut_max;
int	g_t_l;
int	g_t_h;
int g_iter_max;
int g_abs_tmp;
int g_len_mx;
int	**g_points;
int **g_var;
int g_nbr_crt;
int g_flag_try;
int g_nbr_tetri;
int g_test_max;
int g_trouve;
int *g_show_l;

void	ft_boucle_f1_big(int flag[26], int g_nbr_crt[26])
{
	int			i;
	static int	*backtrack;

	i = 0;
	if (flag[0] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[0] = g_nbr_crt[1] + 1;
		flag[0] = 1;
	}
	while (i < g_iter_max && g_t_h < g_test_max + 4 && g_trouve == 0)
	{
		g_tmp_calc = try_tetris_2(g_tampon, g_points[g_nbr_crt[0]],
				(4 * g_nbr_crt[0]), i);
		g_t_l = calc_larg(g_tmp_calc, g_len_mx);
		g_t_h = calc_haut(g_tmp_calc, g_len_mx);
		g_abs_tmp = absc(g_t_h, g_t_l);
		if (g_abs_tmp <= g_test_max)
		{
			ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
			affiche(backtrack);
		}
		i++;
	}
}

void	ft_boucle_f2_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[1] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[1] = g_nbr_crt[2] + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 2);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[1]), g_len_mx);
			ft_boucle_f1_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f3_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[2] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[2] = g_nbr_crt[3] + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 3);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[2]), g_len_mx);
			ft_boucle_f2_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f4_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[3] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[3] = g_nbr_crt[4] + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 4);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[3]), g_len_mx);
			ft_boucle_f3_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}

void	ft_boucle_f5_big(int flag[26], int g_nbr_crt[26])
{
	int			bcl[3];
	static int	*backtrack;

	bcl[0] = 0;
	bcl[1] = 0;
	bcl[2] = 0;
	if (flag[4] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[4] = g_nbr_crt[5] + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx + 1);
	while (bcl[2] < g_iter_max && bcl[0] < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, bcl, 5);
		if (bcl[1] < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[4]), g_len_mx);
			ft_boucle_f4_big(flag, g_nbr_crt);
		}
		bcl[2]++;
	}
}
