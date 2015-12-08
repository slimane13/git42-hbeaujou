/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef5_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2515/12/08 13:24:24 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:12:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f21_big(int flag[26], int nbr_courant[26])
{
	int test_haut21;
	int test_larg21;
	int i21;

	i21 = 0;
	test_larg21 = 0;
	test_haut21 = 0;
	if (flag[20] == 0)
	{
		clean21 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[20] = nbr_courant[21] + 1;
		flag[20] = 1;
	}
	ft_strcpy_int(clean21, tmpCalc, taille_max * taille_max);
	while (i21 < iter_max && test_haut21 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean21, nbr_courant, i21, &test_larg21, &test_haut21, 21);
		if (test_larg21 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[20]), taille_max);
			ft_boucle_f10_big(flag, nbr_courant);
		}
		i21++;
	}
}

void	ft_boucle_f22_big(int flag[26], int nbr_courant[26])
{
	int test_larg22;
	int test_haut22;
	int i22;

	test_haut22 = 0;
	test_larg22 = 0;
	i22 = 0;
	if (flag[21] == 0)
	{
		clean22 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[21] = nbr_courant[22] + 1;
		flag[21] = 1;
	}
	ft_strcpy_int(clean22, tmpCalc, taille_max * taille_max);
	while (i22 < iter_max && test_haut22 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean22, nbr_courant, i22, &test_larg22, &test_haut22, 22);
		if (test_larg22 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[21]), taille_max);
			ft_boucle_f21_big(flag, nbr_courant);
		}
		i22++;
	}
}

void	ft_boucle_f23_big(int flag[26], int nbr_courant[26])
{
	int test_larg23;
	int test_haut23;
	int i23;

	test_haut23 = 0;
	test_larg23 = 0;
	i23 = 0;
	if (flag[22] == 0)
	{
		clean23 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[22] = nbr_courant[23] + 1;
		flag[22] = 1;
	}
	ft_strcpy_int(clean23, tmpCalc, taille_max * taille_max);
	while (i23 < iter_max && test_haut23 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean23, nbr_courant, i23, &test_larg23, &test_haut23, 23);
		if (test_larg23 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[22]), taille_max);
			ft_boucle_f22_big(flag, nbr_courant);
		}
		i23++;
	}
}

void	ft_boucle_f24_big(int flag[26], int nbr_courant[26])
{
	int test_larg24;
	int test_haut24;
	int i24;

	test_haut24 = 0;
	test_larg24 = 0;
	i24 = 0;
	if (flag[23] == 0)
	{
		clean24 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[23] = nbr_courant[24] + 1;
		flag[23] = 1;
	}
	ft_strcpy_int(clean24, tmpCalc, taille_max * taille_max);
	while (i24 < iter_max && test_haut24 < test_max + 1 && trouve == 0)
	{
		calc_attrib(clean24, nbr_courant, i24, &test_larg24, &test_haut24, 24);
		if (test_larg24 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[23]), taille_max);
			ft_boucle_f23_big(flag, nbr_courant);
		}
		i24++;
	}
}

void	ft_boucle_f25_big(int flag[26], int nbr_courant[26])
{
	int test_larg25;
	int test_haut25;
	int i25;

	test_haut25 = 0;
	test_larg25 = 0;
	i25 = 0;
	if (flag[24] == 0)
	{
		clean25 = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[24] = nbr_courant[25] + 1;
		flag[24] = 1;
	}
	ft_strcpy_int(clean25, tmpCalc, taille_max * taille_max);
	while (i25 < iter_max)
	{
		calc_attrib(clean25, nbr_courant, i25, &test_larg25, &test_haut25, 25);
		if (test_larg25 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[24]), taille_max);
			ft_boucle_f24_big(flag, nbr_courant);
		}
		i25++;
	}
}
