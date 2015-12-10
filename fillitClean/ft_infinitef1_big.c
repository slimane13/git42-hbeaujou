/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 09:07:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	int			g_haut_max1;
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
				g_len_mx, g_var, g_nbr_crt[0], (4 * g_nbr_crt[0]), i);
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
	int			g_t_h2;
	int			g_t_l2;
	int			i2;
	static int	*backtrack;

	i2 = 0;
	g_t_h2 = 0;
	g_t_l2 = 0;
	if (flag[1] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[1] = g_nbr_crt[2] + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i2 < g_iter_max && g_t_h2 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i2, &g_t_l2, &g_t_h2, 2);
		if (g_t_l2 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[1]), g_len_mx);
			ft_boucle_f1_big(flag, g_nbr_crt);
		}
		i2++;
	}
}

void	ft_boucle_f3_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_h3;
	int			g_t_l3;
	int			i3;
	static int	*backtrack;

	i3 = 0;
	g_t_h3 = 0;
	g_t_l3 = 0;
	if (flag[2] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[2] = g_nbr_crt[3] + 1;
		flag[2] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i3 < g_iter_max && g_t_h3 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i3, &g_t_l3, &g_t_h3, 3);
		if (g_t_l3 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[2]), g_len_mx);
			ft_boucle_f2_big(flag, g_nbr_crt);
		}
		i3++;
	}
}

void	ft_boucle_f4_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_h4;
	int			g_t_l4;
	int			i4;
	static int	*backtrack;

	i4 = 0;
	g_t_h4 = 0;
	g_t_l4 = 0;
	if (flag[3] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[3] = g_nbr_crt[4] + 1;
		flag[3] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (i4 < g_iter_max && g_t_h4 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i4, &g_t_l4, &g_t_h4, 4);
		if (g_t_l4 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[3]), g_len_mx);
			ft_boucle_f3_big(flag, g_nbr_crt);
		}
		i4++;
	}
}

void	ft_boucle_f5_big(int flag[26], int g_nbr_crt[26])
{
	int			g_t_h5;
	int			g_t_l5;
	int			i5;
	static int	*backtrack;

	i5 = 0;
	g_t_l5 = 0;
	g_t_h5 = 0;
	if (flag[4] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
		g_nbr_crt[4] = g_nbr_crt[5] + 1;
		flag[4] = 1;
	}
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx + 1);
	while (i5 < g_iter_max && g_t_h5 < g_test_max + 1 && g_trouve == 0)
	{
		calc(backtrack, g_nbr_crt, i5, &g_t_l5, &g_t_h5, 5);
		if (g_t_l5 < g_test_max + 1)
		{
			g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[4]), g_len_mx);
			ft_boucle_f4_big(flag, g_nbr_crt);
		}
		i5++;
	}
}
