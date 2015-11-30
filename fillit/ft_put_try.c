/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:26:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/30 14:13:17 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*tab_char_to_int(char *str)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(int) * 36);
	while (str[i] != '\0')
	{
		tab[i] = atoi(&str[i]);
		i++;
	}
	return (tab);
}

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

int		isValid(int *t1, int taille, int *spc)
{
	if (keepForm(t1, spc, taille) == 0)
		return (0);
	return (1);
}

void	assignSpot(int *tab)
{
	tab[0] = tab[0] + 1;
	tab[1] = tab[1] + 1;
	tab[2] = tab[2] + 1;
	tab[3] = tab[3] + 1;
}

int		*try_tetris(int *t1, int *t2, int taille, int **spc, int k)
{
	int i;
	int	*final;
	int j;

	final = (int *)malloc(sizeof(int) * (taille * taille));
	i = 0;
	j = 0;
	rewind_tetris(t1, 0);
	while (!isValid(t1, taille, spc[k]) || overlap_3(t1, t2, 4))
		assignSpot(t1);
	while (j < taille * taille)
	{
		if (j == t1[0] || j == t1[1] || j == t1[2] || j == t1[3])
			final[j] = 2;
		else if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
			final[j] = 1;
		else
			final[j] = 0;
		j++;
	}
	return (final);
}

int		*try_tetris_2(int *t1, int *t2, int taille, int **spc, int k, int passage, int target)
{
	int i;
	int	*final;
	int j;
	int flag;

	final = (int *)malloc(sizeof(int) * (taille * taille));
	i = 0;
	j = 0;
	flag = 0;
	rewind_tetris(t2, target);
	while (!isValid(t2, taille, spc[k]) || overlap_3(t1, t2, passage))
		assignSpot(t2);
	while (j < taille * taille)
	{
		while (i < passage && flag == 0)
		{
			if (j == t1[i])
			{
				final[j] = 1;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
		{
			if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
				final[j] = 2;
			else
				final[j] = 0;
		}
		j++;
		i = 0;
		flag = 0;
	}
	return (final);
}
