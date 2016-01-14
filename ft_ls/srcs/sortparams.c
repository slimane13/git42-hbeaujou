/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortparams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:15:32 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:06:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_str(char **a, char **b)
{
	char	*save;

	save = *a;
	*a = *b;
	*b = save;
}

void	ft_sort_time(char **argv, int argc, t_option *op)
{
	int			i;
	int			j;
	struct stat	bufi;
	struct stat	bufj;

	i = 0;
	while (i < argc)
	{
		lstat(argv[i], &bufi);
		j = i + 1;
		while (j < argc)
		{
			lstat(argv[j], &bufj);
			if (op->rev == 0 && bufi.st_mtime < bufj.st_mtime)
				ft_swap_str(&argv[i], &argv[j]);
			if (op->rev == 1 && bufi.st_mtime > bufj.st_mtime)
				ft_swap_str(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
}

void	ft_sort_params_dir(char **argv, int argc, t_option *op)
{
	if (op->by == 1 && op->rev == 0)
		ft_sort_params(argv, argc);
	if (op->by == 1 && op->rev == 1)
		ft_sort_params_rev(argv, argc);
	if (op->by == 2)
		ft_sort_time(argv, argc, op);
}
