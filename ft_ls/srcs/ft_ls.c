/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:13:37 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:59:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	g_check;

char	*ft_makeabsolute(char *dir, char *file)
{
	char	*dst;

	dst = ft_strjoin(dir, file);
	return (dst);
}

int		main(int argc, char *argv[])
{
	g_check = 'z';
	ft_ls(argv + 1, argc - 1);
	return (0);
}

char	*ft_strjoin_dir(const char *s1, const char *s2)
{
	int		len_all;
	char	*dst;
	char	*temp_s1;

	temp_s1 = (char *)s1;
	if (s1 && s2)
	{
		temp_s1 = ft_strjoin(s1, "/");
		len_all = ft_strlen(s1) + ft_strlen(s2);
		dst = ft_memalloc(len_all + 1);
		if (dst)
		{
			ft_strcat(ft_strcpy(dst, temp_s1), s2);
			return (dst);
		}
	}
	return (NULL);
}

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
