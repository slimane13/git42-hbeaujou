/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:11:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:39:14 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	***ft_gettab(char **argv, int argc, int *nb, t_option *op)
{
	int		i;
	int		j;
	int		k;
	char	***tab;

	i = 0;
	tab = (char ***)malloc(sizeof(char **) * 3);
	while (i < 3)
	{
		tab[i] = (char **)malloc(sizeof(char *) * (nb[i] + 1));
		j = 0;
		k = 0;
		while (j < argc)
		{
			if (ft_checkargv(argv[j], op) == i)
			{
				tab[i][k] = ft_strdup(argv[j]);
				k++;
			}
			j++;
			tab[i][k] = 0;
		}
		i++;
	}
	return (tab);
}

void	print_tab(char ***tab, int *nb)
{
	int		i;

	i = 0;
	while (i < nb[0])
	{
		ft_putendl(tab[0][i]);
		i++;
	}
	i = 0;
	while (i < nb[1])
	{
		ft_putendl(tab[1][i]);
		i++;
	}
	i = 0;
	while (i < nb[2])
	{
		ft_putendl(tab[2][i]);
		i++;
	}
}

char	***ft_maketab_of_argv(char **argv, int argc, t_option *op)
{
	char	***tab;
	int		*nb_out;

	if (argc)
	{
		nb_out = ft_getnb_out(argv, argc, op);
		tab = ft_gettab(argv, argc, nb_out, op);
	}
	else
	{
		tab = (char ***)malloc(sizeof(char **) * 3);
		if (op->listed == 1)
		{
			tab[1] = (char **)malloc(sizeof(char *) * 1);
			tab[1][0] = ft_strdup(".");
		}
		else
		{
			tab[2] = (char **)malloc(sizeof(char *) * 1);
			tab[2][0] = ft_strdup(".");
		}
	}
	return (tab);
}
