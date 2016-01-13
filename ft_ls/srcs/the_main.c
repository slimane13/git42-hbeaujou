/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:15:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:56:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	gain_line(int *start)
{
	ft_putendl_fd("\nusage: ft_ls [-AGRSTUafgdlprtu1] [file ...]", 2);
	*start = -1;
}

int		ft_start_after_option(char **argv, int argc, t_option *op)
{
	int		start;
	int		i;

	start = 0;
	i = 0;
	while (i < argc && (ft_strequ(argv[i], "--")
				|| (argv[i][0] == '-' && !ft_check_option(argv[i], &op))))
	{
		if (!ft_strequ(argv[i], "-"))
			start = i + 1;
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
		i++;
	}
	if (i < argc && argv[i][0] == '-' && ft_check_option(argv[i], &op) &&
			AR1 && AR2 && AR3 && AR4 && AR5 && AR6 && AR7 && AR8)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(ft_check_option(argv[i], &op), 2);
		gain_line(&start);
	}
	return (start);
}

void	ft_sort_all(char ***tab, t_option *op, int *nb)
{
	ft_sort_params(tab[0], nb[0]);
	ft_sort_params_dir(tab[2], nb[2], op);
}

void	ft_print_tab(char ***tab, t_option *op, int *nb)
{
	int		i;

	i = 0;
	ft_sort_all(tab, op, nb);
	while (i < nb[0] && g_error1 == 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(tab[0][i]);
		i++;
	}
	if (nb[1])
		ft_printfile(tab[1], op, nb);
	i = 0;
	while (i < nb[2])
	{
		if (nb[0] + nb[1] + nb[2] > 1)
		{
			if (i > 0 || nb[1] > 0)
				ft_putendl("");
			ft_putstr(tab[2][i]);
			ft_putendl(":");
		}
		ft_printdir(tab[2][i], op);
		i++;
	}
}

void	ft_ls(char **argv, int argc)
{
	t_option	*op;
	int			start;
	char		***tab;

	g_error1 = 0;
	g_error2 = 0;
	op = (t_option *)malloc(sizeof(t_option));
	ft_initoption(&op);
	if ((start = ft_start_after_option(argv, argc, op)) != -1)
	{
		if (argc >= 3)
		{
			if (ft_strcmp(argv[1], "-") == 0 && ft_strcmp(argv[2], "--") == 0 &&
					ft_strcmp(argv[3], "---") == 0)
				start = 1;
		}
		tab = ft_maketab_of_argv(argv + start, argc - start, op);
		ft_printf("");
		ft_print_tab(tab, op, ft_getnb_out(argv + start, argc - start, op));
	}
}
