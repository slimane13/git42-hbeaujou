/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 11:17:38 by hbeaujou         ###   ########.fr       */
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
	tab = struct_to_tab(ft_get_maps(rd, g_nbr_tetri), tetri_list);
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

void	attrib_iter(void)
{
	if (g_nbr_tetri < 6)
		attrib_iter_first();
	else
		attrib_iter_second();
}

int		main(int argc, char **argv)
{
	char	**tetri_list;
	int		ite;

	if (argc != 2)
		return (0);
	g_nbr_tetri = lire_file(argv[1]);
	g_len_mx = 2 * (g_nbr_tetri);
	if (g_nbr_tetri == 1 || g_nbr_tetri == 0)
	{
		g_len_mx = 4;
		g_nbr_tetri++;
	}
	ite = g_nbr_tetri;
	if (!(g_points = malloc(sizeof(int *) * ite)))
		return (0);
	tetri_list = (char **)malloc(sizeof(char *) * g_nbr_tetri);
	g_var = lire_to_tab(argv[1], tetri_list);
	while (ite > 0)
	{
		g_points[ite - 1] = situe_point(tetri_list[ite - 1]);
		ite--;
	}
	rewind_tetris(g_points[0], 0);
	g_flag_try = 0;
	g_final = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
	g_tmp_calc = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
	g_tampon = (int *)malloc(sizeof(int) * g_len_mx);
	g_show_l = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx));
	resolve();
	return (0);
}
