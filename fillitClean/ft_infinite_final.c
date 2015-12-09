/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_g_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:55:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26_big(int flag[26], int g_nbr_courant[26])
{
	int			i26;
	static int	*backtrack;

	i26 = 0;
	ft_strcpy_int(backtrack, g_tmpCalc, g_taille_max * g_taille_max);
	while (i26 < g_iter_max)
	{
		g_tampon = resitue(backtrack, (4 * g_nbr_courant[25]), g_taille_max);
		g_tmpCalc = try_tetris_2(g_tampon, g_points[g_nbr_courant[25]], g_taille_max, g_var,
				g_nbr_courant[25], (4 * g_nbr_courant[25]), i26);
		g_tampon = resitue(g_tmpCalc, (4 * g_nbr_courant[25]), g_taille_max);
		ft_boucle_f25_big(flag, g_nbr_courant);
		i26++;
	}
}

void	choix_boucle(int nbr)
{
	int flag[26];
	int g_nbr_courant[26];
	int pp;

	pp = 0;
	while (pp < 26)
	{
		g_nbr_courant[pp] = 0;
		flag[pp++] = 0;
	}
	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr, flag, g_nbr_courant);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr, flag, g_nbr_courant);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr, flag, g_nbr_courant);
}

void	choix_boucle_tier1(int nbr, int flag[26], int g_nbr_courant[26])
{
	if (nbr < 5)
		lance_boucle_14(nbr, flag, g_nbr_courant);
	else
		lance_boucle_59(nbr, flag, g_nbr_courant);
}

void	choix_boucle_tier2(int nbr, int flag[26], int g_nbr_courant[26])
{
	if (nbr < 5)
		lance_boucle_14_2(nbr, flag, g_nbr_courant);
	else
		lance_boucle_59_2(nbr, flag, g_nbr_courant);
}

void	choix_boucle_tier3(int nbr, int flag[26], int g_nbr_courant[26])
{
	if (nbr < 5)
		lance_boucle_14_3(nbr, flag, g_nbr_courant);
	else
		lance_boucle_59_3(nbr, flag, g_nbr_courant);
}
