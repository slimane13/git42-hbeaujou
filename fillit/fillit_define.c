/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_define.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:17:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/27 17:48:52 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*rewind_tetris(int *tab)
{

	return (0);
}

void detect_solo(int *tab)
{

}

void detect_topLeft(int *tab)
{

}

int **struct_to_tab(t_map *beg)
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
		tab[count][0] = tmp->x;
		tab[count][1] = tmp->y;
		tmp = tmp->nxt_map;
	}
	return (tab);
}
