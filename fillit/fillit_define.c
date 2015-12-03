/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:17:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 18:34:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void rewind_tetris(int *tab, int i)
{
	if (tab[0] > i)
	{
		while (tab[0] > i)
		{
			tab[0] = tab[0] - 1;
			tab[1] = tab[1] - 1;
			tab[2] = tab[2] - 1;
			tab[3] = tab[3] - 1;
		}
	}
	else if (tab[0] < i)
	{
		while (tab[0] < i)
		{
			tab[0] = tab[0] + 1;
			tab[1] = tab[1] + 1;
			tab[2] = tab[2] + 1;
			tab[3] = tab[3] + 1;
		}
	}
	else
	{
	}
}

int *resitue(int *tab, int taille, int tailleMax)
{
	int *passe;
	int i;
	int count;

	i = 0;
	count = 0;
	passe = (int *)malloc(sizeof(int) * (4 + 4 * taille));
	while (i < (tailleMax * tailleMax))
	{
		if (tab[i] != 0)
		{
			passe[count] = i;
			count++;
		}
		i++;
	}
	return (passe);
}

int **struct_to_tab(t_map *beg, char **tetriList)
{
	t_map *tmp;
	int	**tab;
	int count;

	tmp = beg;
	count = 0;
	while (tmp)
	{
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
		tetriList[count] = ft_strdup(tmp->content);
		count++;
		tmp = tmp->nxt_map;
	}
	return (tab);
}

