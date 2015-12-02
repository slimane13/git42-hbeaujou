/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:38:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 10:05:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11(void)
{
	i11 = 0;
	if (flagF11 == 0)
	{
		clean11 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF11 = 1;
	}
	ft_strcpy_int(clean11, tmpCalc, tailleMax * tailleMax);
	while (i11 < iterMax)
	{
		tampon = resitue(clean11, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i11);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f10();
		i11++;
	}
}

void	ft_boucle_f12(void)
{
	i12 = 0;
	if (flagF12 == 0)
	{
		clean12 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF12 = 1;
	}
	ft_strcpy_int(clean12, tmpCalc, tailleMax * tailleMax);
	while (i12 < iterMax)
	{
		tampon = resitue(clean12, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i12);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f11();
		i12++;
	}
}

void	ft_boucle_f13(void)
{
	i13 = 0;
	if (flagF13 == 0)
	{
		clean13 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF13 = 1;
	}
	ft_strcpy_int(clean13, tmpCalc, tailleMax * tailleMax);
	while (i13 < iterMax)
	{
		tampon = resitue(clean13, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i13);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f12();
		i13++;
	}
}

void	ft_boucle_f14(void)
{
	i14 = 0;
	if (flagF14 == 0)
	{
		clean14 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF14 = 1;
	}
	ft_strcpy_int(clean14, tmpCalc, tailleMax * tailleMax);
	while (i14 < iterMax)
	{
		tampon = resitue(clean14, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i14);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f13();
		i14++;
	}
}

void	ft_boucle_f15(void)
{
	i15 = 0;
	if (flagF15 == 0)
	{
		clean15 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF15 = 1;
	}
	ft_strcpy_int(clean15, tmpCalc, tailleMax * tailleMax);
	while (i15 < iterMax)
	{
		tampon = resitue(clean15, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i15);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f14();
		i15++;
	}
}
