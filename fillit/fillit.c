/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/29 17:21:18 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "fillit.h"

int		lireFile(char *str)
{
	int rd;
	char c;
	int flag;
	int count;

	rd = open(str, O_RDONLY);
	flag = 0;
	count = 0;
	while (read(rd, &c, 1))
	{
		if (c != '\n')
			flag = 0;
		else if (c == '\n')
			flag++;
		if (flag == 2)
			count++;
	}
	if (count > 0)
		count++;
	return (count);
}

int 	**lireToTab(char *str)
{
	int rd;
	int **tab;

	rd = open(str, O_RDONLY);
	tab = struct_to_tab(ft_get_maps(rd));
	return (tab);
}

int		*situePoint(char *str)
{
	int *pos;
	int i;
	int j;
	int etage;

	i = 0;
	j = 0;
	etage = 0;
	if (!(pos = malloc(sizeof(int) * 4)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '\n')
		{
			if (str[i] == '\n')
				etage++;
			i++;
		}
		else
		{
			pos[j] = i - etage;
			j++;
			i++;
		}
	}
	return (pos);
}

char	**recupTetri(int a, int max, char *s)
{
	char **tableTetri;
	int i;
	int j;
	int rd;
	char c;
	int flag;
	
	i = 0;
	j = 0;
	flag = 0;
	if (!(tableTetri = malloc(sizeof(char *) * a)))
		return (NULL);
	while (i < a)
	{
		tableTetri[i] = malloc(sizeof(char ) * (max * max));
		i++;
	}
	i = 0;
	rd = open(s, O_RDONLY);
	while (read(rd, &c, 1))
	{
		if (c == '\n')
			flag++;
		else
			flag = 0;
		if (flag == 2)
		{
			i++;
			j = 0;
		}
		else
		{
			tableTetri[i][j] = c;
			j++;
		}
	}
	return (tableTetri);
}

int		main(int argc, char **argv)
{
	char	**matrResult;
	char	**tetriList;
	int		**points;
	int		**var;
	int		*final;
	int 	*tampon;
	int		tailleMax;
	int		nbrTetri;
	int		tailleF;
	int		i;

	if (argc != 2)
		return (0);
	nbrTetri = lireFile(argv[1]);
	tailleMax = 2 * nbrTetri;
	tetriList = recupTetri(nbrTetri, tailleMax, argv[1]);
	i = nbrTetri;
	if (!(points = malloc(sizeof(int *) * i)))
		return (0);
	while (i > 0)
	{
		points[i - 1] = situePoint(tetriList[i - 1]);
		i--;
	}
//	var = lireToTab(argv[1]);
	var = (int **)malloc(sizeof(int *) * 3);
	var[0] = (int *)malloc(sizeof(int) * 2);
	var[1] = (int *)malloc(sizeof(int) * 2);
	var[2] = (int *)malloc(sizeof(int) * 2);
	var[0][0] = 2;
	var[0][1] = 2;
	var[1][0] = 2;
	var[1][1] = 3;
	var[2][0] = 2;
	var[2][1] = 2;
	rewind_tetris(points[0]);
	final = try_tetris(points[1], points[0], tailleMax, var, 0);
	affiche(tetriList, final);
	i = 2;
	while (i < nbrTetri)
	{
		tampon = resitue(final, (4 * i));
		final = try_tetris_2(tampon, points[i], tailleMax, var, i, (4 * i));
		i++;
		affiche(tetriList, final);
	}
	tampon = resitue(final, (4 * i));
	printf("%d\n",calc_larg(tampon, tailleMax));	
	printf("%d\n",calc_haut(tampon, tailleMax));	
	return (0);
}
