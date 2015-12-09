/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 17:02:48 by hbeaujou         ###   ########.fr       */
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

int 	**lireToTab(char *str, char **tetriList)
{
	int rd;
	int **tab;

	rd = open(str, O_RDONLY);
	tab = struct_to_tab(ft_get_maps(rd, nbrTetri), tetriList);
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
			tableTetri[i][j] = '\0';
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

void	attrib_iter(void)
{
	if (nbrTetri == 1)
		iterMax = 10;
	else if (nbrTetri == 2)
		iterMax = 21;
	else if (nbrTetri == 3)
		iterMax = 24;
	else if (nbrTetri == 4)
		iterMax = 28;
	else if (nbrTetri == 5)
		iterMax = 45;
	else if (nbrTetri == 6)
		iterMax = 58;
	else if (nbrTetri == 7)
		iterMax = 67;
	else if (nbrTetri == 8)
		iterMax = 75;
	else if (nbrTetri == 9)
		iterMax = 100;
	else if (nbrTetri == 10)
		iterMax = 120;
}

int		main(int argc, char **argv)
{
	char	**tetriList;
	int		ite;
	int		target;

	if (argc != 2)
		return (0);
	nbrTetri = lireFile(argv[1]);
	tailleMax = 2 * (nbrTetri);
	if (nbrTetri == 1 || nbrTetri == 0)
	{
		tailleMax = 4;
		nbrTetri++;
	}
	ite = nbrTetri;
	if (!(points = malloc(sizeof(int *) * ite)))
		return (0);
	tetriList = (char **)malloc(sizeof(char *) * nbrTetri);
	var = lireToTab(argv[1], tetriList);
	while (ite > 0)
	{
		points[ite - 1] = situePoint(tetriList[ite - 1]);
		ite--;
	}
	rewind_tetris(points[0], 0);
	flagTRY = 0;
	final = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	tmpCalc = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	tampon = (int *)malloc(sizeof(int) * tailleMax);
	affichageLettre = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	flagTRY = 1;
	remp_blank(tmpCalc);
	largMax = 100;
	trouve = 0;
	hautMax = 100;
	absTmp = 100;
	testMax = nbrTetri - nbrTetri/3;
	if (nbrTetri > 9)
	{
		testMax = nbrTetri/2 + 1;
	}
	attrib_iter();
//	iterMax = 50;//10 * nbrTetri + 10 * nbrTetri/4;
	if (nbrTetri == 2)
		iterMax = 14;
	if (nbrTetri > 2)
	{
		while (trouve == 0)
		{
			choix_boucle(nbrTetri);
			testMax++;
		}
	}
	else
	{
		choix_boucle(nbrTetri);
	}
	affiche(clean);
	return (0);
}
