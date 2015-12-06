/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:38:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 18:15:00 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11(int flag[26])
{
	i11 = 0;
	if (flag[10] == 0)
	{
		clean11 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[10] = 1;
	}
	ft_strcpy_int(clean11, tmpCalc, tailleMax * tailleMax);
	while (i11 < iterMax)
	{
		tampon = resitue(clean11, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i11);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f10(flag);
		i11++;
	}
}

void	ft_boucle_f12(int flag[26])
{
	i12 = 0;
	if (flag[11] == 0)
	{
		clean12 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[11] = 1;
	}
	ft_strcpy_int(clean12, tmpCalc, tailleMax * tailleMax);
	while (i12 < iterMax)
	{
		tampon = resitue(clean12, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i12);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f11(flag);
		i12++;
	}
}

void	ft_boucle_f13(int flag[26])
{
	i13 = 0;
	if (flag[12] == 0)
	{
		clean13 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[12] = 1;
	}
	ft_strcpy_int(clean13, tmpCalc, tailleMax * tailleMax);
	while (i13 < iterMax)
	{
		tampon = resitue(clean13, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i13);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f12(flag);
		i13++;
	}
}

void	ft_boucle_f14(int flag[26])
{
	i14 = 0;
	if (flag[13] == 0)
	{
		clean14 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[13] = 1;
	}
	ft_strcpy_int(clean14, tmpCalc, tailleMax * tailleMax);
	while (i14 < iterMax)
	{
		tampon = resitue(clean14, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i14);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f13(flag);
		i14++;
	}
}

void	ft_boucle_f15(int flag[26])
{
	i15 = 0;
	if (flag[14] == 0)
	{
		clean15 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant++;
		flag[14] = 1;
	}
	ft_strcpy_int(clean15, tmpCalc, tailleMax * tailleMax);
	while (i15 < iterMax)
	{
		tampon = resitue(clean15, (4 * nbrCourant), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * nbrCourant), i15);
		tampon = resitue(tmpCalc, (4 * nbrCourant), tailleMax);
		ft_boucle_f14(flag);
		i15++;
	}
}
