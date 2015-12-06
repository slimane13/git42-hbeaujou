/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:46:30 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:59 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16(int flag[26])
{
	i16 = 0;
	if (flag[15] == 0)
	{
		clean16 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[15] = 1;
	}
	ft_strcpy_int(clean16, tmpCalc, tailleMax * tailleMax);
	while (i16 < iterMax)
	{
		tampon = resitue(clean16, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i16);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f15(flag);
		i16++;
	}
}

void	ft_boucle_f17(int flag[26])
{
	i17 = 0;
	if (flag[16] == 0)
	{
		clean17 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[16] = 1;
	}
	ft_strcpy_int(clean17, tmpCalc, tailleMax * tailleMax);
	while (i17 < iterMax)
	{
		tampon = resitue(clean17, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i17);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f16(flag);
		i17++;
	}
}

void	ft_boucle_f18(int flag[26])
{
	i18 = 0;
	if (flag[17] == 0)
	{
		clean18 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[17] = 1;
	}
	ft_strcpy_int(clean18, tmpCalc, tailleMax * tailleMax);
	while (i18 < iterMax)
	{
		tampon = resitue(clean18, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i18);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f17(flag);
		i18++;
	}
}

void	ft_boucle_f19(int flag[26])
{
	i19 = 0;
	if (flag[18] == 0)
	{
		clean19 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[18] = 1;
	}
	ft_strcpy_int(clean19, tmpCalc, tailleMax * tailleMax);
	while (i19 < iterMax)
	{
		tampon = resitue(clean19, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i19);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f18(flag);
		i19++;
	}
}

void	ft_boucle_f20(int flag[26])
{
	i20 = 0;
	if (flag[19] == 0)
	{
		clean20 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[19] = 1;
	}
	ft_strcpy_int(clean20, tmpCalc, tailleMax * tailleMax);
	while (i20 < iterMax)
	{
		tampon = resitue(clean20, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i20);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f19(flag);
		i20++;
	}
}
