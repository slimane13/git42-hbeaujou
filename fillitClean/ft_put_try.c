/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:26:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 18:29:48 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		overlap_3(int *t1, int *t2, int taille)
{
	int i;

	i = 0;
	while (i < taille)
	{
		if (t1[i] == t2[0] || t1[i] == t2[1] || t1[i] == t2[2] ||
				t1[i] == t2[3])
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(int *t1, int taille, int *spc)
{
	if (keep_form(t1, spc, taille) == 0)
		return (0);
	return (1);
}

void	assign_spot(int *tab)
{
	tab[0] = tab[0] + 1;
	tab[1] = tab[1] + 1;
	tab[2] = tab[2] + 1;
	tab[3] = tab[3] + 1;
}

void	ft_boucle(int *i, int *j, int *flag, int *t1, int *t2, int passage)
{
	while (*i < passage && *flag == 0)
	{
		if (*j == t1[*i] && flagTRY == 1)
		{
			final[*j] = affichageLettre[*j];
			*flag = 1;
		}
		*i = *i + 1;
	}
	if (*flag == 0)
	{
		if (*j == t2[0] || *j == t2[1] || *j == t2[2] || *j == t2[3])
			final[*j] = affichageLettre[*j] + 1;
		else
			final[*j] = 0;
	}
	*j = *j + 1;
	*i = 0;
	*flag = 0;
}

int		*try_tetris_2(int *t1, int *t2, int taille, int **spc, int k,
		int passage, int target)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	rewind_tetris(t2, target);
	while (overlap_3(t1, t2, passage))
		assign_spot(t2);
	while (j < taille * taille)
		ft_boucle(&i, &j, &flag, t1, t2, passage);
	return (final);
}
