/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 14:28:08 by ebouther         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26_big(int flag[26], int nbrCourant[26])
{
	int i26;

	i26 = 0;
	if (flag[25] == 0)
	{
		clean26 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant[25] = nbrCourant[26] + 1;
		flag[25] = 1;
	}
	ft_strcpy_int(clean26, tmpCalc, taille_max * taille_max);
	while (i26 < iter_max)
	{
		tampon = resitue(clean26, (4 * nbrCourant[25]), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant[25]], taille_max, var,
				nbrCourant[25], (4 * nbrCourant[25]), i26);
		tampon = resitue(tmpCalc, (4 * nbrCourant[25]), taille_max);
		ft_boucle_f25_big(flag, nbrCourant);
		i26++;
	}
}

void	choix_boucle(int nbr)
{
	int flag[26];
	int nbrCourant[26];
	int pp;
   
	pp = 0;
	while (pp < 26)
	{
		nbrCourant[pp] = 0;
		flag[pp++] = 0;
	}

	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr, flag, nbrCourant);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr, flag, nbrCourant);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr, flag, nbrCourant);
}

void	choix_boucle_tier1(int nbr, int flag[26], int nbrCourant[26])
{
	if (nbr == 1)
	{
		nbrCourant[1] = -1;
		ft_boucle_f1_special(flag, nbrCourant);
	}
	else if (nbr == 2)
	{
		nbrCourant[2] = -1;
		ft_boucle_f2_special(flag, nbrCourant);
	}
	else if (nbr == 3)
	{
		nbrCourant[3] = -1;
		ft_boucle_f3_big(flag, nbrCourant);
	}
	else if (nbr == 4)
	{
		nbrCourant[4] = -1;
		ft_boucle_f4_big(flag, nbrCourant);
	}
	else if (nbr == 5)
	{
		nbrCourant[5] = -1;
		ft_boucle_f5_big(flag, nbrCourant);
	}
	else if (nbr == 6)
	{
		nbrCourant[6] = -1;
		ft_boucle_f6_big(flag, nbrCourant);
	}
	else if (nbr == 7)
	{
		nbrCourant[7] = -1;
		ft_boucle_f7_big(flag, nbrCourant);
	}
	else if (nbr == 8)
	{
		nbrCourant[8] = -1;
		ft_boucle_f8_big(flag, nbrCourant);
	}
	else if (nbr == 9)
	{
		nbrCourant[9] = -1;
		ft_boucle_f9_big(flag, nbrCourant);
	}
}

void	choix_boucle_tier2(int nbr, int flag[26], int nbrCourant[26])
{
	if (nbr == 10)
	{
		nbrCourant[10] = -1;
		ft_boucle_f10_big(flag, nbrCourant);
	}
	else if (nbr == 11)
	{
		nbrCourant[11] = -1;
		ft_boucle_f11_big(flag, nbrCourant);
	}
	else if (nbr == 12)
	{
		nbrCourant[12] = -1;
		ft_boucle_f12_big(flag, nbrCourant);
	}
	else if (nbr == 13)
	{
		nbrCourant[13] = -1;
		ft_boucle_f13_big(flag, nbrCourant);
	}
	else if (nbr == 14)
	{
		nbrCourant[14] = -1;
		ft_boucle_f14_big(flag, nbrCourant);
	}
	else if (nbr == 15)
	{
		nbrCourant[15] = -1;
		ft_boucle_f15_big(flag, nbrCourant);
	}
	else if (nbr == 16)
	{
		nbrCourant[16] = -1;
		ft_boucle_f16_big(flag, nbrCourant);
	}
	else if (nbr == 17)
	{
		nbrCourant[17] = -1;
		ft_boucle_f17_big(flag, nbrCourant);
	}
	else if (nbr == 18)
	{
		nbrCourant[18] = -1;
		ft_boucle_f18_big(flag, nbrCourant);
	}
}

void	choix_boucle_tier3(int nbr, int flag[26], int nbrCourant[26])
{
	if (nbr == 19)
	{
		nbrCourant[19] = -1;
		ft_boucle_f19_big(flag, nbrCourant);
	}
	else if (nbr == 20)
	{
		nbrCourant[20] = -1;
		ft_boucle_f20_big(flag, nbrCourant);
	}
	else if (nbr == 21)
	{
		nbrCourant[21] = -1;
		ft_boucle_f21_big(flag, nbrCourant);
	}
	else if (nbr == 22)
	{
		nbrCourant[22] = -1;
		ft_boucle_f22_big(flag, nbrCourant);
	}
	else if (nbr == 23)
	{
		nbrCourant[23] = -1;
		ft_boucle_f23_big(flag, nbrCourant);
	}
	else if (nbr == 24)
	{
		nbrCourant[24] = -1;
		ft_boucle_f24_big(flag, nbrCourant);
	}
	else if (nbr == 25)
	{
		nbrCourant[25] = -1;
		ft_boucle_f25_big(flag, nbrCourant);
	}
	else if (nbr == 26)
	{
		nbrCourant[26] = -1;
		ft_boucle_f26_big(flag, nbrCourant);
	}
	else
	{
	}
}

void	remp_blank(int *tab)
{
	int i;

	i = 0;
	while (i < taille_max * taille_max)
	{
		tab[i] = 0;
		i++;
	}
}
