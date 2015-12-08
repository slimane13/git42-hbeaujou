/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:43:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26_big(int flag[26], int nbr_courant[26])
{
	int i26;

	i26 = 0;
	ft_strcpy_int(clean26, tmpCalc, taille_max * taille_max);
	while (i26 < iter_max)
	{
		tampon = resitue(clean26, (4 * nbr_courant[25]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbr_courant[25]], taille_max, var,
				nbr_courant[25], (4 * nbr_courant[25]), i26);
		tampon = resitue(tmpCalc, (4 * nbr_courant[25]), taille_max);
		ft_boucle_f25_big(flag, nbr_courant);
		i26++;
	}
}

void	choix_boucle(int nbr)
{
	int flag[26];
	int nbr_courant[26];
	int pp;
   
	pp = 0;
	while (pp < 26)
	{
		nbr_courant[pp] = 0;
		flag[pp++] = 0;
	}

	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr, flag, nbr_courant);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr, flag, nbr_courant);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr, flag, nbr_courant);
}

void	choix_boucle_tier1(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr < 5)
		lance_boucle_14(nbr, flag, nbr_courant);
	else
		lance_boucle_59(nbr, flag, nbr_courant);
}

void	choix_boucle_tier2(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr < 5)
		lance_boucle_14_2(nbr, flag, nbr_courant);
	else
		lance_boucle_59_2(nbr, flag, nbr_courant);
}

void	choix_boucle_tier3(int nbr, int flag[26], int nbr_courant[26])
{
	if (nbr == 19)
	{
		nbr_courant[19] = -1;
		ft_boucle_f19_big(flag, nbr_courant);
	}
	else if (nbr == 20)
	{
		nbr_courant[20] = -1;
		ft_boucle_f20_big(flag, nbr_courant);
	}
	else if (nbr == 21)
	{
		nbr_courant[21] = -1;
		ft_boucle_f21_big(flag, nbr_courant);
	}
	else if (nbr == 22)
	{
		nbr_courant[22] = -1;
		ft_boucle_f22_big(flag, nbr_courant);
	}
	else if (nbr == 23)
	{
		nbr_courant[23] = -1;
		ft_boucle_f23_big(flag, nbr_courant);
	}
	else if (nbr == 24)
	{
		nbr_courant[24] = -1;
		ft_boucle_f24_big(flag, nbr_courant);
	}
	else if (nbr == 25)
	{
		nbr_courant[25] = -1;
		ft_boucle_f25_big(flag, nbr_courant);
	}
	else if (nbr == 26)
	{
		nbr_courant[26] = -1;
		ft_boucle_f26_big(flag, nbr_courant);
	}
}
