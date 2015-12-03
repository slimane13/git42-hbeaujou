/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:06:41 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 15:57:19 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f26(void)
{
	i26 = 0;
	if (flagF26 == 0)
	{
		clean26 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF26 = 1;
	}
	ft_strcpy_int(clean26, tmpCalc, tailleMax * tailleMax);
	while (i26 < iterMax)
	{
		tampon = resitue(clean26, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i26);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f25();
		i26++;
	}
}

void	choix_boucle(int nbr)
{
	if (nbr > 0 && nbr < 10)
		choix_boucle_tier1(nbr);
	else if (nbr >= 10 && nbr < 19)
		choix_boucle_tier2(nbr);
	else if (nbr >= 19)
		choix_boucle_tier3(nbr);
	else
	{
	}
}

void	choix_boucle_tier1(int nbr)
{
	if (nbr == 1)
	{
		nbrCourant2 = -1;
		ft_boucle_f1();
	}
	else if (nbr == 2)
	{
		nbrCourant3 = -1;
		ft_boucle_f2();
	}
	else if (nbr == 3)
	{
		nbrCourant4 = -1;
		ft_boucle_f3();
	}
	else if (nbr == 4)
	{
		nbrCourant5 = -1;
		ft_boucle_f4();
	}
	else if (nbr == 5)
	{
		nbrCourant6 = -1;
		ft_boucle_f5();
	}
	else if (nbr == 6)
	{
		nbrCourant7 = -1;
		ft_boucle_f6();
	}
	else if (nbr == 7)
	{
		nbrCourant8 = -1;
		ft_boucle_f7();
	}
	else if (nbr == 8)
	{
		nbrCourant9 = -1;
		ft_boucle_f8();
	}
	else if (nbr == 9)
	{
		nbrCourant10 = -1;
		ft_boucle_f9();
	}
	else
	{
	}
}

void	choix_boucle_tier2(int nbr)
{
	if (nbr == 10)
		ft_boucle_f10();
	else if (nbr == 11)
		ft_boucle_f11();
	else if (nbr == 12)
		ft_boucle_f12();
	else if (nbr == 13)
		ft_boucle_f13();
	else if (nbr == 14)
		ft_boucle_f14();
	else if (nbr == 15)
		ft_boucle_f15();
	else if (nbr == 16)
		ft_boucle_f16();
	else if (nbr == 17)
		ft_boucle_f17();
	else if (nbr == 18)
		ft_boucle_f18();
	else
	{
	}
}

void	choix_boucle_tier3(int nbr)
{
	if (nbr == 19)
		ft_boucle_f19();
	else if (nbr == 20)
		ft_boucle_f20();
	else if (nbr == 21)
		ft_boucle_f21();
	else if (nbr == 22)
		ft_boucle_f22();
	else if (nbr == 23)
		ft_boucle_f23();
	else if (nbr == 24)
		ft_boucle_f24();
	else if (nbr == 25)
		ft_boucle_f25();
	else if (nbr == 26)
		ft_boucle_f26();
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
