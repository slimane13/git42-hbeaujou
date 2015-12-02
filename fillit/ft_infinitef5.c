/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:59:52 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/02 10:09:45 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f21(void)
{
	i21 = 0;
	if (flagF21 == 0)
	{
		clean21 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF21 = 1;
	}
	ft_strcpy_int(clean21, tmpCalc, tailleMax * tailleMax);
	while (i21 < iterMax)
	{
		tampon = resitue(clean21, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i21);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f20();
		i21++;
	}
}

void	ft_boucle_f22(void)
{
	i22 = 0;
	if (flagF22 == 0)
	{
		clean22 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF22 = 1;
	}
	ft_strcpy_int(clean22, tmpCalc, tailleMax * tailleMax);
	while (i22 < iterMax)
	{
		tampon = resitue(clean22, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i22);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f21();
		i22++;
	}
}

void	ft_boucle_f23(void)
{
	i23 = 0;
	if (flagF23 == 0)
	{
		clean23 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF23 = 1;
	}
	ft_strcpy_int(clean23, tmpCalc, tailleMax * tailleMax);
	while (i23 < iterMax)
	{
		tampon = resitue(clean23, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i23);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f22();
		i23++;
	}
}

void	ft_boucle_f24(void)
{
	i24 = 0;
	if (flagF24 == 0)
	{
		clean24 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF24 = 1;
	}
	ft_strcpy_int(clean24, tmpCalc, tailleMax * tailleMax);
	while (i24 < iterMax)
	{
		tampon = resitue(clean24, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i24);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f23();
		i24++;
	}
}

void	ft_boucle_f25(void)
{
	i25 = 0;
	if (flagF25 == 0)
	{
		clean25 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flagF25 = 1;
	}
	ft_strcpy_int(clean25, tmpCalc, tailleMax * tailleMax);
	while (i25 < iterMax)
	{
		tampon = resitue(clean25, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i25);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f24();
		i25++;
	}
}
