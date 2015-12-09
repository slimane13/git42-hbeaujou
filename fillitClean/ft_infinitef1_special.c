/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef1_special.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 10:36:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 10:17:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f1_special(int flag[26], int g_nbr_courant[26])
{
	int			i;
	static int	*backtrack;

	i = 0;
	backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
	g_nbr_courant[0] = g_nbr_courant[1] + 1;
	if (g_nbr_courant == 0)
	{
		g_tampon[0] = -1;
		g_tampon[1] = -1;
		g_tampon[2] = -1;
		g_tampon[3] = -1;
	}
	g_tmpCalc = try_tetris_2_special(g_tampon, g_points[g_nbr_courant[0]],
			g_taille_max, g_var, g_nbr_courant[0], 4, i);
	g_test_larg = calc_larg(g_tmpCalc, g_taille_max);
	g_test_haut = calc_haut(g_tmpCalc, g_taille_max);
	g_absTmp = absc(g_test_larg, g_test_haut);
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
}

void	ft_boucle_f1_special_2(int flag[26], int g_nbr_courant[26])
{
	int			i;
	int			g_haut_max1;
	static int	*backtrack;

	i = 0;
	if (flag[0] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[0] = g_nbr_courant[1] + 1;
		flag[0] = 1;
	}
	g_haut_max1 = g_haut_max * 4;
	while (i < g_iter_max && g_test_haut < g_haut_max1 + 4)
	{
		g_tmpCalc = try_tetris_2_2(g_tampon, g_points[g_nbr_courant[0]],
				g_taille_max, g_var, g_nbr_courant[0], (4 * g_nbr_courant[0]), i);
		g_test_larg = calc_larg(g_tmpCalc, g_taille_max);
		g_test_haut = calc_haut(g_tmpCalc, g_taille_max);
		if ((g_test_larg < g_larg_max && absc(g_test_larg, g_test_haut) < g_absTmp) ||
				(g_test_haut < g_haut_max && absc(g_test_larg, g_test_haut) < g_absTmp))
			attrb_2(backtrack);
		i++;
	}
}

void	ft_boucle_f2_special(int flag[26], int g_nbr_courant[26])
{
	int			i2;
	int			g_test_haut2;
	int			g_test_larg2;
	static int	*backtrack;

	i2 = 0;
	g_test_haut2 = 0;
	g_test_larg2 = 0;
	if (flag[1] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
		g_nbr_courant[1] = g_nbr_courant[2] + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i2 < g_iter_max && g_test_haut2 < g_haut_max + 4)
	{
		g_tampon = resitue(backtrack, (4 * (g_nbr_courant[1] + 1)), g_taille_max);
		if (i2 == 0)
		{
			g_tampon[0] = -1;
			g_tampon[1] = -1;
			g_tampon[2] = -1;
			g_tampon[3] = -1;
		}
		g_tmpCalc = try_tetris_2_2(g_tampon, g_points[g_nbr_courant[1]], g_taille_max,
				g_var, g_nbr_courant[1], (4 * (g_nbr_courant[1] + 1)), i2);
		g_test_larg2 = calc_larg(g_tmpCalc, g_taille_max);
		g_test_haut2 = calc_haut(g_tmpCalc, g_taille_max);
		if (g_test_larg2 < g_larg_max + 1)
		{
			g_tampon = resitue(g_tmpCalc, (4 * (g_nbr_courant[1] + 1)), g_taille_max);
			ft_boucle_f1_special_2(flag, g_nbr_courant);
		}
		i2++;
	}
}

int		*try_tetris_2_special(int *t1, int *t2, int taille, int **spc,
		int k, int passage, int target)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	if (k != 0)
		rewind_tetris(t2, target);
	while (!is_valid(t2, taille, spc[k]) || overlap_3(t1, t2, passage))
		assign_spot(t2);
	while (j < taille * taille)
	{
		while (i < passage && flag == 0)
		{
			if (j == t1[i] && g_flagTRY == 1)
			{
				g_final[j] = g_affichageLettre[j];
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
				g_final[j] = g_affichageLettre[j] + 1;
			else
				g_final[j] = 0;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (g_final);
}

int		*try_tetris_2_2(int *t1, int *t2, int taille, int **spc,
		int k, int passage, int target)
{
	int i;
	int j;
	int flag;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	flag = 0;
	if (k != 0)
		rewind_tetris(t2, 0);
	while ((!is_valid(t2, taille, spc[k]) ||
				overlap_3(t1, t2, passage)) && counter < 8)
	{
		assign_spot(t2);
		counter++;
	}
	while (j < taille * taille)
	{
		while (i < passage && flag == 0)
		{
			if (j == t1[i] && g_flagTRY == 1)
			{
				g_final[j] = g_affichageLettre[j];
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
				g_final[j] = g_affichageLettre[j] + 1;
			else
				g_final[j] = 0;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (g_final);
}
