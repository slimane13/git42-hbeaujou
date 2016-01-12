/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcolors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 15:30:52 by bsautron          #+#    #+#             */
/*   Updated: 2016/01/12 12:26:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_colors(t_dir *file, t_option *op)
{
	if (S_ISLNK(file->buf.st_mode))
	{
		ft_putstr(file->name);
		if (op->format == LONG)
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
	if (op->pipe == PIPE && S_ISDIR(file->buf.st_mode))
		file->name = ft_makedir(file->name);
	if (op->colors == COLORS)
	{
		if (S_ISDIR(file->buf.st_mode))
			ft_putstr("\033[33;31m");
		if (S_ISLNK(file->buf.st_mode))
		{
			ft_putstr("\033[33;32m");
			ft_putstr(file->name);
			if (op->format == LONG)
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
