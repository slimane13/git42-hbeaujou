/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef3_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:09:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:53:58 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f11_big(int flag[26], int nbr_courant[26])
{
	int			test_haut11;
	int			test_larg11;
	int			i11;
	static int	*backtrack;

	i11 = 0;
	test_larg11 = 0;
	test_haut11 = 0;
	if (flag[10] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[10] = nbr_courant[11] + 1;
		flag[10] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i11 < iter_max && test_haut11 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i11, &test_larg11, &test_haut11, 11);
		if (test_larg11 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[10]), taille_max);
			ft_boucle_f10_big(flag, nbr_courant);
		}
		i11++;
	}
}

void	ft_boucle_f12_big(int flag[26], int nbr_courant[26])
{
	int			test_larg12;
	int			test_haut12;
	int			i12;
	static int	*backtrack;

	test_haut12 = 0;
	test_larg12 = 0;
	i12 = 0;
	if (flag[11] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[11] = nbr_courant[12] + 1;
		flag[11] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i12 < iter_max && test_haut12 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i12, &test_larg12, &test_haut12, 12);
		if (test_larg12 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[11]), taille_max);
			ft_boucle_f11_big(flag, nbr_courant);
		}
		i12++;
	}
}

void	ft_boucle_f13_big(int flag[26], int nbr_courant[26])
{
	int			test_larg13;
	int			test_haut13;
	int			i13;
	static int	*backtrack;

	test_haut13 = 0;
	test_larg13 = 0;
	i13 = 0;
	if (flag[12] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[12] = nbr_courant[13] + 1;
		flag[12] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i13 < iter_max && test_haut13 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i13, &test_larg13, &test_haut13, 13);
		if (test_larg13 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[12]), taille_max);
			ft_boucle_f12_big(flag, nbr_courant);
		}
		i13++;
	}
}

void	ft_boucle_f14_big(int flag[26], int nbr_courant[26])
{
	int			test_larg14;
	int			test_haut14;
	int			i14;
	static int	*backtrack;

	test_haut14 = 0;
	test_larg14 = 0;
	i14 = 0;
	if (flag[13] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[13] = nbr_courant[14] + 1;
		flag[13] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i14 < iter_max && test_haut14 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i14, &test_larg14, &test_haut14, 14);
		if (test_larg14 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[13]), taille_max);
			ft_boucle_f13_big(flag, nbr_courant);
		}
		i14++;
	}
}

void	ft_boucle_f15_big(int flag[26], int nbr_courant[26])
{
	int			test_larg15;
	int			test_haut15;
	int			i15;
	static int	*backtrack;

	test_haut15 = 0;
	test_larg15 = 0;
	i15 = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[14] = nbr_courant[15] + 1;
		flag[14] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i15 < iter_max)
	{
		calc(backtrack, nbr_courant, i15, &test_larg15, &test_haut15, 15);
		if (test_larg15 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[14]), taille_max);
			ft_boucle_f14_big(flag, nbr_courant);
		}
		i15++;
	}
}
