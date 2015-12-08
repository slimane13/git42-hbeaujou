/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef2_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 15:18:08 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:13:13 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f6_big(int flag[26], int nbr_courant[26])
{
	int test_haut6;
	int test_larg6;
	int i6;

	i6 = 0;
	test_larg6 = 0;
	test_haut6 = 0;
	if (flag[5] == 0)
	{
		clean6 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[5] = nbr_courant[6] + 1;
		flag[5] = 1;
	}
	ft_strcpy_int(clean6, tmpCalc, taille_max * taille_max);
	while (i6 < iter_max && test_haut6 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean6, nbr_courant, i6, &test_larg6, &test_haut6, 6);
		if (test_larg6 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[5]), taille_max);
			ft_boucle_f5_big(flag, nbr_courant);
		}
		i6++;
	}
}

void	ft_boucle_f7_big(int flag[26], int nbr_courant[26])
{
	int test_larg7;
	int test_haut7;
	int i7;

	test_haut7 = 0;
	test_larg7 = 0;
	i7 = 0;
	if (flag[6] == 0)
	{
		clean7 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[6] = nbr_courant[7] + 1;
		flag[6] = 1;
	}
	ft_strcpy_int(clean7, tmpCalc, taille_max * taille_max);
	while (i7 < iter_max && test_haut7 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean7, nbr_courant, i7, &test_larg7, &test_haut7, 7);
		if (test_larg7 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[6]), taille_max);
			ft_boucle_f6_big(flag, nbr_courant);
		}
		i7++;
	}
}

void	ft_boucle_f8_big(int flag[26], int nbr_courant[26])
{
	int test_larg8;
	int test_haut8;
	int i8;

	test_haut8 = 0;
	test_larg8 = 0;
	i8 = 0;
	if (flag[7] == 0)
	{
		clean8 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[7] = nbr_courant[8] + 1;
		flag[7] = 1;
	}
	ft_strcpy_int(clean8, tmpCalc, taille_max * taille_max);
	while (i8 < iter_max && test_haut8 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean8, nbr_courant, i8, &test_larg8, &test_haut8, 8);
		if (test_larg8 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[7]), taille_max);
			ft_boucle_f7_big(flag, nbr_courant);
		}
		i8++;
	}
}

void	ft_boucle_f9_big(int flag[26], int nbr_courant[26])
{
	int test_larg9;
	int test_haut9;
	int i9;

	test_haut9 = 0;
	test_larg9 = 0;
	i9 = 0;
	if (flag[8] == 0)
	{
		clean9 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[8] = nbr_courant[9] + 1;
		flag[8] = 1;
	}
	ft_strcpy_int(clean9, tmpCalc, taille_max * taille_max);
	while (i9 < iter_max && test_haut9 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean9, nbr_courant, i9, &test_larg9, &test_haut9, 9);
		if (test_larg9 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[8]), taille_max);
			ft_boucle_f8_big(flag, nbr_courant);
		}
		i9++;
	}
}

void	ft_boucle_f10_big(int flag[26], int nbr_courant[26])
{
	int test_larg10;
	int test_haut10;
	int i10;

	test_haut10 = 0;
	test_larg10 = 0;
	i10 = 0;
	if (flag[9] == 0)
	{
		clean10 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[9] = nbr_courant[10] + 1;
		flag[9] = 1;
	}
	ft_strcpy_int(clean10, tmpCalc, taille_max * taille_max);
	while (i10 < iter_max && test_haut10 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean10, nbr_courant, i10, &test_larg10, &test_haut10, 10);
		if (test_larg10 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[9]), taille_max);
			ft_boucle_f9_big(flag, nbr_courant);
		}
		i10++;
	}
}
