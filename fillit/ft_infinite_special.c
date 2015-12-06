/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infinite_special.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/06 17:10:59 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/06 17:49:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_boucle_f1_special(int flag[26])
{
	int i;

	i = 0;
	if (flag[0] == 0)
	{
		clean = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant = nbrCourant2 + 1;
		flag[0] = 1;
	}
	while (i < 16)
	{
		tmpCalc = try_tetris_2(tampon, points[nbrCourant], tailleMax, var,
				nbrCourant, (4 * (nbrCourant + 1)), i);
		testLarg = calc_larg(tmpCalc, tailleMax);
		testHaut = calc_haut(tmpCalc, tailleMax);
		affiche(tmpCalc);
		printf("\n");
		if ((testLarg < largMax && abs_minus(testLarg, testHaut) < absTmp) ||
				(testHaut < hautMax && abs_minus(testLarg, testHaut) < absTmp))
		{
			ft_strcpy_int(clean, tmpCalc, tailleMax * tailleMax);
			largMax = calc_larg(final, tailleMax);
			hautMax = calc_haut(final, tailleMax);
			absTmp = abs_minus(largMax, hautMax);
		}
		i++;
	}
}

void	ft_boucle_f2_special(int flag[26])
{
	int	testHaut2;
	int	testLarg2;

	i2 = 0;
	testHaut2 = 0;
	testLarg2 = 0;
	if (flag[1] == 0)
	{
		clean2 = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
		nbrCourant2 = nbrCourant3 + 1;
		flag[1] = 1;
	}
	ft_strcpy_int(clean2, tmpCalc, tailleMax * tailleMax);
	while (i2 < 16)
	{
		tampon = resitue(clean2, (4 * nbrCourant2), tailleMax);
		tmpCalc = try_tetris_2(tampon, points[nbrCourant2], tailleMax, var,
				nbrCourant2, (4 * (nbrCourant2 + 1)), i2);
		testLarg2 = calc_larg(tmpCalc, tailleMax);
		testHaut2 = calc_haut(tmpCalc, tailleMax);
		if (testLarg2 < largMax + 1)
		{
			tampon = resitue(tmpCalc, (4 * nbrCourant2), tailleMax);
			ft_boucle_f1_special(flag);
		}
		i2++;
	}
}
