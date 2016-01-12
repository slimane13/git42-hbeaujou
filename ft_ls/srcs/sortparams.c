/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 20:45:34 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 17:46:03 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_swap_str(char **a, char **b)
{
	char	*save;

	save = *a;
	*a = *b;
	*b = save;
}

static void	ft_sort_time(char **argv, int argc, t_option *op)
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
			if (op->rev == NO_REVERSE && bufi.st_mtime < bufj.st_mtime)
				ft_swap_str(&argv[i], &argv[j]);
			if (op->rev == REVERSE && bufi.st_mtime > bufj.st_mtime)
				ft_swap_str(&argv[i], &argv[j]);
			j++;
		}
		i++;
	}
}

void		ft_sort_params_dir(char **argv, int argc, t_option *op)
{
	if (op->by == BY_NAME && op->rev == NO_REVERSE)
		ft_sort_params(argv, argc);
	if (op->by == BY_NAME && op->rev == REVERSE)
		ft_sort_params_rev(argv, argc);
	if (op->by == BY_TIME)
		ft_sort_time(argv, argc, op);
}
