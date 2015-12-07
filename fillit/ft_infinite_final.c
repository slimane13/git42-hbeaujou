/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/07 13:27:24 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26(int flag[26])
{
	i26 = 0;
	if (flag[25] == 0)
	{
		clean26 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[25] = 1;
	}
	ft_strcpy_int(clean26, tmpCalc, tailleMax * tailleMax);
	while (i26 < iterMax)
	{
		tampon = resitue(clean26, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i26);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f25(flag);
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
		ft_boucle_f9(flag);
	}
	else
	{
	}
}

void	choix_boucle_tier2(int nbr, int flag[26])
{
	if (nbr == 10)
		ft_boucle_f10(flag);
	else if (nbr == 11)
		ft_boucle_f11(flag);
	else if (nbr == 12)
		ft_boucle_f12(flag);
	else if (nbr == 13)
		ft_boucle_f13(flag);
	else if (nbr == 14)
		ft_boucle_f14(flag);
	else if (nbr == 15)
		ft_boucle_f15(flag);
	else if (nbr == 16)
		ft_boucle_f16(flag);
	else if (nbr == 17)
		ft_boucle_f17(flag);
	else if (nbr == 18)
		ft_boucle_f18(flag);
	else
	{
	}
}

void	choix_boucle_tier3(int nbr, int flag[26])
{
	if (nbr == 19)
		ft_boucle_f19(flag);
	else if (nbr == 20)
		ft_boucle_f20(flag);
	else if (nbr == 21)
		ft_boucle_f21(flag);
	else if (nbr == 22)
		ft_boucle_f22(flag);
	else if (nbr == 23)
		ft_boucle_f23(flag);
	else if (nbr == 24)
		ft_boucle_f24(flag);
	else if (nbr == 25)
		ft_boucle_f25(flag);
	else if (nbr == 26)
		ft_boucle_f26(flag);
	else
	{
	}
}

void	remp_blank(int *tab)
{
	int i;

	i = 0;
	while (i < tailleMax * tailleMax)
	{
		tab[i] = 0;
		i++;
	}
}
