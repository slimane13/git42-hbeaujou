/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 17:42:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 11:36:55 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	define(void)
{
}

void	ft_cut_f2_special(int i2, int g_nbr_crt[26], int gt[2], int flag[26])
{
	if (i2 == 0)
	{
		g_tampon[0] = -1;
		g_tampon[1] = -1;
		g_tampon[2] = -1;
		g_tampon[3] = -1;
	}
	g_tmp_calc = try_tetris_2_2(g_tampon, g_points[g_nbr_crt[1]],
			g_len_mx, g_var, g_nbr_crt[1], (4 * (g_nbr_crt[1] + 1)), i2);
	gt[1] = calc_larg(g_tmp_calc, g_len_mx);
	gt[0] = calc_haut(g_tmp_calc, g_len_mx);
	if (gt[1] < g_larg_max + 1)
	{
		g_tampon = resitue(g_tmp_calc, (4 * (g_nbr_crt[1] + 1)),
				g_len_mx);
		ft_boucle_f1_special_2(flag, g_nbr_crt);
	}
}

void	calc(int *clean, int *nbr, int i, int *t1, int *t2, int indice)
{
	g_tampon = resitue(clean, (4 * nbr[indice - 1]), g_len_mx);
	g_tmp_calc = try_tetris_2(g_tampon, g_points[nbr[indice - 1]],
			g_len_mx, g_var, nbr[indice - 1], (4 * nbr[indice - 1]), i);
	*t1 = calc_larg(g_tmp_calc, g_len_mx);
	*t2 = calc_haut(g_tmp_calc, g_len_mx);
}

void	attrb_2(int *backtrack)
{
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	g_larg_max = calc_larg(g_final, g_len_mx);
	g_haut_max = calc_haut(g_final, g_len_mx);
	g_abs_tmp = absc(g_larg_max, g_haut_max);
}

void	remp_blank(int *tab)
{
	int i;

	i = 0;
	while (i < g_len_mx * g_len_mx)
	{
		tab[i] = 0;
		i++;
	}
}
