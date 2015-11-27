/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/27 16:00:05 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//char	**remplitMatr(int a, char *str)
//{
//}

int		main(int argc, char **argv)
{
	char	**matrResult;
	char	**tetriList;
	int		**points;
	int		*final;
	int		*tmp;
	int		tailleMax;
	int		nbrTetri;
	int		tailleF;
	int		i;

	if (argc != 2)
		return (0);
	nbrTetri = lireFile(argv[1]);
	tailleMax = 4 * nbrTetri;
	tetriList = recupTetri(nbrTetri, tailleMax, argv[1]);
	i = nbrTetri;
	if (!(points = malloc(sizeof(int *) * i)))
		return (0);
	printf("%d", i);
	printf("\n");
	while (i > 0)
	{
		points[i - 1] = situePoint(tetriList[i - 1]);
		i--;
	}
	tmp = ft_strdup(points[0]);
	final = try_tetris_test(tmp, points[1], 4);
//	afficheFinal(final);
	printf("%d", nbrTetri);
	printf("\n");
	printf("%s", tetriList[0]);
	printf("\n");
	printf("%s", tetriList[1]);
	printf("\n");
	printf("%d", points[0][0]);
	printf("  ");
	printf("%d", points[0][1]);
	printf("  ");
	printf("%d", points[0][2]);
	printf("  ");
	printf("%d", points[0][3]);
	printf("\n");
	printf("%d", points[1][0]);
	printf("  ");
	printf("%d", points[1][1]);
	printf("  ");
	printf("%d", points[1][2]);
	printf("  ");
	printf("%d", points[1][3]);
	printf("\n");
	printf("\n");
	printf("%d", final[0]);
	printf("%d", final[1]);
	printf("%d", final[2]);
	printf("%d", final[3]);
	printf("\n");
	printf("%d", final[4]);
	printf("%d", final[5]);
	printf("%d", final[6]);
	printf("%d", final[7]);
	printf("\n");
	printf("%d", final[8]);
	printf("%d", final[9]);
	printf("%d", final[10]);
	printf("%d", final[11]);
	printf("\n");
	printf("%d", final[12]);
	printf("%d", final[13]);
	printf("%d", final[14]);
	printf("%d", final[15]);
	printf("\n");
	printf("%d", tmp[0]%4);
	printf("%d", tmp[0]/4);
	return (0);
}
