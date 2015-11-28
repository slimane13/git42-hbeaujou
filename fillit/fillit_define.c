/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:17:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/28 15:56:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void rewind_tetris(int *tab)
{
	while (tab[0] > 0)
	{
		tab[0] = tab[0] - 1;
		tab[1] = tab[1] - 1;
		tab[2] = tab[2] - 1;
		tab[3] = tab[3] - 1;
	}
}

int *resitue(int *tab, int taille)
{
	int *final;
	int i;
	int count;

	i = 0;
	count = 0;
	final = malloc(sizeof(int) * taille);
	while (i < 16)
	{
		if (tab[i] != 0)
		{
			final[count] = i;
			count++;
		}
		i++;
	}
	return (final);
}

int **struct_to_tab(t_map *beg)
{
	t_map *tmp;
	int	**tab;
	int count;

	tmp = beg;
	printf("%d", tmp->x);
	count = 0;
	while (tmp)
	{
		printf("WW\n");
		count++;
		tmp = tmp->nxt_map;
	}
	tab = (int **)malloc(sizeof(int *) * count);
	tmp = beg;
	count = 0;
	while (tmp)
	{
		tab[count] = (int *)malloc(sizeof(int) * 2);
		tab[count][0] = tmp->x;
		tab[count][1] = tmp->y;
		count++;
		tmp = tmp->nxt_map;
	}
	return (tab);
}
