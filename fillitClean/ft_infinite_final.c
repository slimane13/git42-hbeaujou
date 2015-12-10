/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 09:04:22 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 14:22:42 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26_big(int flag[26], int g_nbr_crt[26])
{
	int			boucle[3];
	static int	*backtrack;

	boucle[2] = 0;
	ft_strcpy_int(backtrack, g_tmp_calc, g_len_mx * g_len_mx);
	while (boucle[2]++ < g_iter_max)
	{
		g_tampon = resitue(backtrack, (4 * g_nbr_crt[25]), g_len_mx);
		g_tmp_calc = try_tetris_2(g_tampon, g_points[g_nbr_crt[25]],
				(4 * g_nbr_crt[25]), i26);
		g_tampon = resitue(g_tmp_calc, (4 * g_nbr_crt[25]), g_len_mx);
		ft_boucle_f25_big(flag, g_nbr_crt);
		boucle[2]++;
	}
}

void	choix_boucle(int nbr)
{
	int flag[26];
	int g_nbr_crt[26];
	int pp;

	pp = 0;
	while (pp < 26)
	{
		g_nbr_crt[pp] = 0;
		flag[pp++] = 0;
	}
	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr, flag, g_nbr_crt);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr, flag, g_nbr_crt);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr, flag, g_nbr_crt);
}

void	choix_boucle_tier1(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr < 5)
		lance_boucle_14(nbr, flag, g_nbr_crt);
	else
		lance_boucle_59(nbr, flag, g_nbr_crt);
}

void	choix_boucle_tier2(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr < 5)
		lance_boucle_14_2(nbr, flag, g_nbr_crt);
	else
		lance_boucle_59_2(nbr, flag, g_nbr_crt);
}

void	choix_boucle_tier3(int nbr, int flag[26], int g_nbr_crt[26])
{
	if (nbr < 5)
		lance_boucle_14_3(nbr, flag, g_nbr_crt);
	else
		lance_boucle_59_3(nbr, flag, g_nbr_crt);
}
