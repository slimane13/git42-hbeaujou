/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinitef4_big.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/17/08 18:21:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 09:55:08 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f16_big(int flag[26], int nbr_courant[26])
{
	int			test_haut16;
	int			test_larg16;
	int			i16;
	static int	*backtrack;

	i16 = 0;
	test_larg16 = 0;
	test_haut16 = 0;
	if (flag[15] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[15] = nbr_courant[16] + 1;
		flag[15] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i16 < iter_max && test_haut16 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i16, &test_larg16, &test_haut16, 16);
		if (test_larg16 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[15]), taille_max);
			ft_boucle_f10_big(flag, nbr_courant);
		}
		i16++;
	}
}

void	ft_boucle_f17_big(int flag[26], int nbr_courant[26])
{
	int			test_larg17;
	int			test_haut17;
	int			i17;
	static int	*backtrack;

	test_haut17 = 0;
	test_larg17 = 0;
	i17 = 0;
	if (flag[16] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[16] = nbr_courant[17] + 1;
		flag[16] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i17 < iter_max && test_haut17 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i17, &test_larg17, &test_haut17, 17);
		if (test_larg17 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[16]), taille_max);
			ft_boucle_f16_big(flag, nbr_courant);
		}
		i17++;
	}
}

void	ft_boucle_f18_big(int flag[26], int nbr_courant[26])
{
	int			test_larg18;
	int			test_haut18;
	int			i18;
	static int	*backtrack;

	test_haut18 = 0;
	test_larg18 = 0;
	i18 = 0;
	if (flag[17] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[17] = nbr_courant[18] + 1;
		flag[17] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i18 < iter_max && test_haut18 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i18, &test_larg18, &test_haut18, 18);
		if (test_larg18 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[17]), taille_max);
			ft_boucle_f17_big(flag, nbr_courant);
		}
		i18++;
	}
}

void	ft_boucle_f19_big(int flag[26], int nbr_courant[26])
{
	int			test_larg19;
	int			test_haut19;
	int			i19;
	static int	*backtrack;

	test_haut19 = 0;
	test_larg19 = 0;
	i19 = 0;
	if (flag[18] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[18] = nbr_courant[19] + 1;
		flag[18] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i19 < iter_max && test_haut19 < test_max + 1 && trouve == 0)
	{
		calc(backtrack, nbr_courant, i19, &test_larg19, &test_haut19, 19);
		if (test_larg19 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[18]), taille_max);
			ft_boucle_f18_big(flag, nbr_courant);
		}
		i19++;
	}
}

void	ft_boucle_f20_big(int flag[26], int nbr_courant[26])
{
	int			test_larg20;
	int			test_haut20;
	int			i20;
	static int	*backtrack;

	test_haut20 = 0;
	test_larg20 = 0;
	i20 = 0;
	if (flag[19] == 0)
	{
		backtrack = (int *)malloc(sizeof(int) * (taille_max * taille_max));
		nbr_courant[19] = nbr_courant[20] + 1;
		flag[19] = 1;
	}
	ft_strcpy_int(backtrack, tmpCalc, taille_max * taille_max);
	while (i20 < iter_max)
	{
		calc(backtrack, nbr_courant, i20, &test_larg20, &test_haut20, 20);
		if (test_larg20 < test_max + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbr_courant[19]), taille_max);
			ft_boucle_f19_big(flag, nbr_courant);
		}
		i20++;
	}
}
