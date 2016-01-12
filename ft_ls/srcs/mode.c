/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:38:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/12 13:38:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_type_letter(mode_t mode)
{
	if (S_ISREG(mode))
		ft_putchar('-');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else
		ft_putchar('?');
}

static void	ft_mode_usr(mode_t mode)
{
	if (mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISUID)
	{
		if (mode & 0100)
			ft_putchar('s');
		else
			ft_putchar('S');
	}
	else if (mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		ft_mode_grp(mode_t mode)
{
	if (mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISGID)
	{
		if (mode & 0010)
			ft_putchar('s');
		else
			ft_putchar('l');
	}
	else if (mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		ft_mode_oth(mode_t mode)
{
	if (mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (mode & S_ISVTX)
	{
		if (mode & 0001)
			ft_putchar('t');
		else
			ft_putchar('T');
	}
	else if (mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void		ft_mode(char *argv, mode_t mode)
{
	if (mode)
	{
		ft_type_letter(mode);
		ft_mode_usr(mode);
		ft_mode_grp(mode);
		ft_mode_oth(mode);
		if (listxattr(argv, NULL, 0, XATTR_NOFOLLOW) > 0)
			ft_putchar('@');
		else
			ft_putchar(' ');
	}
	ft_putchar(' ');
}
