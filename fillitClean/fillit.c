/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/09 10:57:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "fillit.h"

int		lire_file(char *str)
{
	int		rd;
	char	c;
	int		flag;
	int		count;

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

int		**lire_to_tab(char *str, char **tetri_list)
{
	int rd;
	int **tab;

	rd = open(str, O_RDONLY);
	tab = struct_to_tab(ft_get_maps(rd, g_nbrTetri), tetri_list);
	return (tab);
}

int		*situe_point(char *str)
{
	int *pos;
	int iterat[2];
	int etage;

	iterat[0] = 0;
	iterat[1] = 0;
	etage = 0;
	if (!(pos = malloc(sizeof(int) * 4)))
		return (NULL);
	while (str[iterat[0]] != '\0')
	{
		if (str[iterat[0]] == '.' || str[iterat[0]] == '\n')
		{
			if (str[iterat[0]] == '\n')
				etage++;
			iterat[0]++;
		}
		else
		{
			pos[iterat[1]] = iterat[0] - etage;
			iterat[1]++;
			iterat[0]++;
		}
	}
	return (pos);
}

int		main(int argc, char **argv)
{
	char	**tetri_list;
	int		ite;

	if (argc != 2)
		return (0);
	g_nbrTetri = lire_file(argv[1]);
	g_taille_max = 2 * (g_nbrTetri);
	if (g_nbrTetri == 1 || g_nbrTetri == 0)
	{
		g_taille_max = 4;
		g_nbrTetri++;
	}
	ite = g_nbrTetri;
	if (!(g_points = malloc(sizeof(int *) * ite)))
		return (0);
	tetri_list = (char **)malloc(sizeof(char *) * g_nbrTetri);
	g_var = lire_to_tab(argv[1], tetri_list);
	while (ite > 0)
	{
		g_points[ite - 1] = situe_point(tetri_list[ite - 1]);
		ite--;
	}
	rewind_tetris(g_points[0], 0);
	g_flagTRY = 0;
	g_final = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
	g_tmpCalc = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
	g_tampon = (int *)malloc(sizeof(int) * g_taille_max);
	g_affichageLettre = (int *)malloc(sizeof(int) * (g_taille_max * g_taille_max));
	g_flagTRY = 1;
	remp_blank(g_tmpCalc);
	g_larg_max = 100;
	g_trouve = 0;
	g_haut_max = 100;
	g_absTmp = 100;
	g_test_max = g_nbrTetri - g_nbrTetri / 3;
	if (g_nbrTetri > 9)
		g_test_max = g_nbrTetri / 2 + 1;
	g_iter_max = 65;
	if (g_nbrTetri == 2)
		g_iter_max = 14;
	if (g_nbrTetri > 2)
	{
		while (g_trouve == 0)
		{
			choix_boucle(g_nbrTetri);
			g_test_max++;
		}
	}
	else
		choix_boucle(g_nbrTetri);
	return (0);
}
