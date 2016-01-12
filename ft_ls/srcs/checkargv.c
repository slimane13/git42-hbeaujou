/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:19:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/12 15:19:45 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	error1;
int error2;

int	ft_checkfile(char *argv)
{
	struct stat	buf;

	if (lstat(argv, &buf) == 0)
		return (1);
	else
	{
		if (error2 < 2)
		{
			ft_putstr("ft_ls: ");
			perror(argv);
		}
		error1 = 1;
		error2++;
	}
	return (0);
}

int	ft_checkdir(char *argv, t_option *op)
{
	struct stat	buf;

	if ((op->listed != LISTED && stat(argv, &buf) == 0 && lstat(argv, &buf) == 0
				&& S_ISDIR(buf.st_mode))
			|| (S_ISLNK(buf.st_mode) && op->format == NO_LONG && opendir(argv)))
		return (1);
	return (0);
}

int			ft_checkargv(char *argv, t_option *op)
{
	if (ft_checkdir(argv, op))
		return (2);
	if (ft_checkfile(argv))
		return (1);
	return (0);
}
