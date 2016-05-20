/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksourou <sksourou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/26 00:01:59 by sksourou          #+#    #+#             */
/*   Updated: 2015/10/20 17:34:30 by sksourou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	stock_fd(t_all *a, int fd)
{
	if (!(a->nbr = (int **)malloc(sizeof(int *) * a->nbr_line)) || \
		!(a->nbr_split = (int *)malloc(sizeof(int) * a->nbr_line)))
		exit(1);
	while (get_next_line(fd, &(a->line)) == 1)
	{
		if (a->line)
		{
			a->i = 0;
			a->line = all_to_space(a->line);
			a->split = ft_strsplit(a->line, ' ');
			a->nbr_split[a->k] = ft_count_split(a->split);
			if (!(a->nbr[a->j] = (int *)malloc(sizeof(int) * \
						a->nbr_split[a->k])))
				exit(1);
			while (a->split[a->i])
			{
				a->nbr[a->j][a->i] = ft_getnbr(a->split[a->i]);
				(a->i)++;
			}
			free(a->split);
			(a->j)++;
			(a->k)++;
		}
	}
}

void	init(t_all *all)
{
	all->j = 0;
	all->k = 0;
	all->scalx = 19;
	all->scaly = 20;
	all->startx = 700;
	all->starty = 100;
}

int		main(int ac, char **av)
{
	t_all	a;
	int		fd;
	int		i;

	i = 100;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		ft_count_line(&a, fd);
		fd = open(av[1], O_RDONLY);
		init(&a);
		stock_fd(&a, fd);
		close(fd);
		a.mlx = mlx_init();
		a.win = mlx_new_window(a.mlx, WIN_X, WIN_Y, WIN_NAME);
		mlx_expose_hook(a.win, get_hook, &a);
		mlx_key_hook(a.win, key_hook, &a);
		mlx_loop(a.mlx);
	}
	else
		ft_putendl("No File");
	return (0);
}
