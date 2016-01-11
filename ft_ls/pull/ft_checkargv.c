/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:45:39 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 16:05:12 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_checkfile(char *argv)
{
	struct stat	buf;

	if (lstat(argv, &buf) == 0)
		return (1);
	return (0);
}

static int	ft_checkdir(char *argv, t_option *op)
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
