/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   couleurs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:12:36 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:35:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_colors(t_dir *file, t_option *op)
{
	if (S_ISLNK(file->buf.st_mode))
	{
		ft_putstr(file->name);
		if (op->format == 1)
		{
			ft_putstr(" -> ");
			ft_putstr(file->format->linkname);
		}
	}
	else
		ft_putstr(file->name);
	ft_putendl("");
}

void	ft_putcolors(t_dir *file, t_option *op)
{
	if (op->pipe == 1 && S_ISDIR(file->buf.st_mode))
		file->name = ft_makedir(file->name);
	if (op->colors == 1)
	{
		if (S_ISDIR(file->buf.st_mode))
			ft_putstr("\033[33;31m");
		if (S_ISLNK(file->buf.st_mode))
		{
			ft_putstr("\033[33;32m");
			ft_putstr(file->name);
			if (op->format == 1)
			{
				ft_putstr("\033[33;37m -> ");
				ft_putstr(file->format->linkname);
			}
		}
		else
			ft_putstr(file->name);
		ft_putendl("\033[33;37m");
	}
	else
	{
		if (ft_strcmp(file->name, "-dir") != 0)
			no_colors(file, op);
	}
}
