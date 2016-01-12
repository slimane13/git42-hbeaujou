/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maketab_of_argv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:10:05 by bsautron          #+#    #+#             */
/*   Updated: 2016/01/12 12:48:33 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	***ft_gettab(char **argv, int argc, int *nb, t_option *op)
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

void		print_tab(char ***tab, int *nb)
{
	int		i;

	i = 0;
	ft_putendl("-->LES ERREURS");
	while (i < nb[OUT_ERROR])
	{
		ft_putendl(tab[OUT_ERROR][i]);
		i++;
	}
	i = 0;
	ft_putendl("\n-->LES FILES");
	while (i < nb[OUT_FILES])
	{
		ft_putendl(tab[OUT_FILES][i]);
		i++;
	}
	i = 0;
	ft_putendl("\n-->LES DIRS");
	while (i < nb[OUT_DIR])
	{
		ft_putendl(tab[OUT_DIR][i]);
		i++;
	}
	ft_putendl("_____");
}

char		***ft_maketab_of_argv(char **argv, int argc, t_option *op)
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
		if (op->listed == LISTED)
		{
			tab[OUT_FILES] = (char **)malloc(sizeof(char *) * 1);
			tab[OUT_FILES][0] = ft_strdup(".");
		}
		else
		{
			tab[OUT_DIR] = (char **)malloc(sizeof(char *) * 1);
			tab[OUT_DIR][0] = ft_strdup(".");
		}
	}
	return (tab);
}
