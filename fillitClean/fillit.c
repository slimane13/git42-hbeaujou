/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:56:10 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/11 10:41:55 by ebouther         ###   ########.fr       */
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
		ft_error_exit();
	g_nbr_tetri = lire_file(argv[1]);
	g_len_mx = 2 * (g_nbr_tetri);
	if (g_nbr_tetri == 1 || g_nbr_tetri == 0)
	{
		g_len_mx = 4;
		g_nbr_tetri++;
	}
	ite = g_nbr_tetri;
	if (!(tetri_list = (char **)malloc(sizeof(char *) * g_nbr_tetri)) ||
			!(g_points = malloc(sizeof(int *) * ite)) ||
			!(g_var = lire_to_tab(argv[1], tetri_list)))
		ft_error_exit();
	cut_main(&ite, tetri_list);
	if (!(g_final = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx))) ||
		!(g_tmp_calc = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx))) ||
		!(g_tampon = (int *)malloc(sizeof(int) * g_len_mx)) ||
		!(g_show_l = (int *)malloc(sizeof(int) * (g_len_mx * g_len_mx))))
		ft_error_exit();
	resolve();
	return (0);
}
