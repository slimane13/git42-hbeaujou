/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:46:30 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 10:04:46 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16(void)
{
	i16 = 0;
	if (flagF16 == 0)
	{
		clean16 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF16 = 1;
	}
	ft_strcpy_int(clean16, tmpCalc, tailleMax * tailleMax);
	while (i16 < iterMax)
	{
		tampon = resitue(clean16, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i16);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f15();
		i16++;
	}
}

void	ft_boucle_f17(void)
{
	i17 = 0;
	if (flagF17 == 0)
	{
		clean17 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF17 = 1;
	}
	ft_strcpy_int(clean17, tmpCalc, tailleMax * tailleMax);
	while (i17 < iterMax)
	{
		tampon = resitue(clean17, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i17);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f16();
		i17++;
	}
}

void	ft_boucle_f18(void)
{
	i18 = 0;
	if (flagF18 == 0)
	{
		clean18 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF18 = 1;
	}
	ft_strcpy_int(clean18, tmpCalc, tailleMax * tailleMax);
	while (i18 < iterMax)
	{
		tampon = resitue(clean18, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i18);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f17();
		i18++;
	}
}

void	ft_boucle_f19(void)
{
	i19 = 0;
	if (flagF19 == 0)
	{
		clean19 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF19 = 1;
	}
	ft_strcpy_int(clean19, tmpCalc, tailleMax * tailleMax);
	while (i19 < iterMax)
	{
		tampon = resitue(clean19, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i19);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f18();
		i19++;
	}
}

void	ft_boucle_f20(void)
{
	i20 = 0;
	if (flagF20 == 0)
	{
		clean20 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF20 = 1;
	}
	ft_strcpy_int(clean20, tmpCalc, tailleMax * tailleMax);
	while (i20 < iterMax)
	{
		tampon = resitue(clean20, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i20);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f19();
		i20++;
	}
}
