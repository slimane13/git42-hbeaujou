/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 14:51:10 by hbeaujou         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	char	**tetriList;
	int		ite;
	int		target;

	if (argc != 2)
		return (0);
	nbrTetri = lireFile(argv[1]);
	tailleMax = 2 * (nbrTetri - 1);
	tetriList = recupTetri(nbrTetri, tailleMax, argv[1]);
	ite = nbrTetri;
	if (!(points = malloc(sizeof(int *) * ite)))
		return (0);
	while (ite > 0)
	{
		points[ite - 1] = situePoint(tetriList[ite - 1]);
		ite--;
	}
//	var = lireToTab(argv[1]); /////   tempo fonction elliot pdt que je test
	var = (int **)malloc(sizeof(int *) * 5);
	var[0] = (int *)malloc(sizeof(int) * 2);
	var[1] = (int *)malloc(sizeof(int) * 2);
	var[2] = (int *)malloc(sizeof(int) * 2);
	var[3] = (int *)malloc(sizeof(int) * 2);
	var[4] = (int *)malloc(sizeof(int) * 2);
//	var[5] = (int *)malloc(sizeof(int) * 2);
//	var[6] = (int *)malloc(sizeof(int) * 2);
//	var[7] = (int *)malloc(sizeof(int) * 2);
//	var[8] = (int *)malloc(sizeof(int) * 2);
//	var[9] = (int *)malloc(sizeof(int) * 2);
	var[0][0] = 1;
	var[0][1] = 4;
	var[1][0] = 2;
	var[1][1] = 3;
	var[2][0] = 2;
	var[2][1] = 2;
	var[3][0] = 2;
	var[3][1] = 2;
	var[4][0] = 3;
	var[4][1] = 2;
//	var[5][0] = 2;
//	var[5][1] = 2;
//	var[6][0] = 2;
//	var[6][1] = 3;
//	var[7][0] = 4;
//	var[7][1] = 1;
//	var[8][0] = 3;
//	var[8][1] = 2;
//	var[9][0] = 3;
//	var[9][1] = 2;
/////////////////////////////////////
	rewind_tetris(points[0], 0);
	flagTRY = 0;
	final = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	tmpCalc = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	clean = (int *)malloc(sizeof(int) * (tailleMax * tailleMax));
	tampon = (int *)malloc(sizeof(int) * tailleMax); // define direct final = points[0]
	tampon[0] = -1;
	tampon[1] = -1;
	tampon[2] = -1;
	tampon[3] = -1;
	tampon[4] = -1;
	tampon[5] = -1;
	tampon[6] = -1;
	tampon[7] = -1;
//	final = try_tetris_2(tampon, points[0], tailleMax, var, 0, 4, 0);
//	affiche(final);
	flagTRY = 1;
	remp_blank(tmpCalc);
	affiche(tmpCalc);
//	ft_strcpy_int(tmpCalc, final, (tailleMax * tailleMax));
	flagF1 = 0;
	flagF2 = 0;
	flagF3 = 0;
	flagF4 = 0;
	flagF5 = 0;	//   Big fonction define
	flagF6 = 0;
	flagF7 = 0;
	flagF8 = 0;
	flagF9 = 0;
	flagF10 = 0;
	flagF11 = 0;
	flagF12 = 0;
	flagF13 = 0;
	flagF14 = 0;
	flagF15 = 0;
	flagF16 = 0;
	flagF17 = 0;
	flagF18 = 0;
	flagF19 = 0;
	flagF20 = 0;
	flagF21 = 0;
	flagF22 = 0;
	flagF23 = 0;
	flagF24 = 0;
	flagF25 = 0;
	flagF26 = 0;
	largMax = 100;
	hautMax = 100;
	absTmp = 100;
	iterMax = 40;
	printf("AAA      %d      AAA\n", nbrTetri);
	nbrTetri = nbrTetri - 1;
	printf("AAA      %d      AAA\n", nbrTetri);
	choix_boucle(nbrTetri);
	affiche(clean);
//	ft_boucle_f4();
	return (0);
}
