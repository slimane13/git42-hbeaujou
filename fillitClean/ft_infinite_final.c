/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:30:40 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26_big(int flag[26])
{
	i26 = 0;
	if (flag[25] == 0)
	{
		clean26 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbrCourant++;
		flag[25] = 1;
	}
	ft_strcpy_int(clean26, tmpCalc, taille_max * taille_max);
	while (i26 < iter_max)
	{
		tampon = resitue(clean26, (4 * nbrCourant), taille_max);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], taille_max, var,
				nbrCourant, (4 * nbrCourant), i26);
		tampon = resitue(tmpCalc, (4 * nbrCourant), taille_max);
		ft_boucle_f25_big(flag);
		i26++;
	}
}

void	choix_boucle(int nbr)
{
	int flag[26];
	int pp;
   
	pp = 0;
	while (pp < 26)
		flag[pp++] = 0;

	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr, flag);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr, flag);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr, flag);
	else
	{
	}
}

void	choix_boucle_tier1(int nbr, int flag[26])
{
	if (nbr == 1)
	{
		nbrCourant2 = -1;
		ft_boucle_f1_special(flag);
	}
	else if (nbr == 2)
	{
		nbrCourant3 = -1;
		ft_boucle_f2_special(flag);
	}
	else if (nbr == 3)
	{
		nbrCourant4 = -1;
		ft_boucle_f3_big(flag);
	}
	else if (nbr == 4)
	{
		nbrCourant5 = -1;
		ft_boucle_f4_big(flag);
	}
	else if (nbr == 5)
	{
		nbrCourant6 = -1;
		ft_boucle_f5_big(flag);
	}
	else if (nbr == 6)
	{
		nbrCourant7 = -1;
		ft_boucle_f6_big(flag);
	}
	else if (nbr == 7)
	{
		nbrCourant8 = -1;
		ft_boucle_f7_big(flag);
	}
	else if (nbr == 8)
	{
		nbrCourant9 = -1;
		ft_boucle_f8_big(flag);
	}
	else if (nbr == 9)
	{
		nbrCourant10 = -1;
		ft_boucle_f9_big(flag);
	}
	else
	{
	}
}

void	choix_boucle_tier2(int nbr, int flag[26])
{
	if (nbr == 10)
	{
		nbrCourant11 = -1;
		ft_boucle_f10_big(flag);
	}
	else if (nbr == 11)
	{
		nbrCourant12 = -1;
		ft_boucle_f11_big(flag);
	}
	else if (nbr == 12)
	{
		nbrCourant13 = -1;
		ft_boucle_f12_big(flag);
	}
	else if (nbr == 13)
	{
		nbrCourant14 = -1;
		ft_boucle_f13_big(flag);
	}
	else if (nbr == 14)
	{
		nbrCourant15 = -1;
		ft_boucle_f14_big(flag);
	}
	else if (nbr == 15)
	{
		nbrCourant16 = -1;
		ft_boucle_f15_big(flag);
	}
	else if (nbr == 16)
	{
		nbrCourant17 = -1;
//		ft_boucle_f16_big(flag);
	}
	else if (nbr == 17)
	{
		nbrCourant18 = -1;
//		ft_boucle_f17_big(flag);
	}
	else if (nbr == 18)
	{
		nbrCourant19 = -1;
//		ft_boucle_f18_big(flag);
	}
	else
	{
	}
}

void	choix_boucle_tier3(int nbr, int flag[26])
{
	if (nbr == 19)
	{
		nbrCourant20 = -1;
		ft_boucle_f19_big(flag);
	}
	else if (nbr == 20)
	{
		nbrCourant21 = -1;
		ft_boucle_f20_big(flag);
	}
	else if (nbr == 21)
	{
		nbrCourant22 = -1;
		ft_boucle_f21_big(flag);
	}
	else if (nbr == 22)
	{
		nbrCourant23 = -1;
		ft_boucle_f22_big(flag);
	}
	else if (nbr == 23)
	{
		nbrCourant24 = -1;
		ft_boucle_f23_big(flag);
	}
	else if (nbr == 24)
	{
		nbrCourant25 = -1;
		ft_boucle_f24_big(flag);
	}
	else if (nbr == 25)
	{
		nbrCourant26 = -1;
		ft_boucle_f25_big(flag);
	}
	else if (nbr == 26)
	{
		nbrCourant27 = -1;
		ft_boucle_f26_big(flag);
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
