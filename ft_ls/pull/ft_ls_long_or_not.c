/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_long_or_not.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:49:55 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/04 16:03:39 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_date_aux(t_dir *file)
{
	write(1, file->format->time + 3, 8);
	write(1, file->format->time + 19, 5);
}

static void	ft_date(t_dir *file, t_option *op)
{
	time_t		t;

	if (op->date == DATE_CREATE)
	{
		if (time(&t) - file->buf.st_birthtime > 15778800
				|| t < file->buf.st_birthtime)
			ft_date_aux(file);
		else
			write(1, file->format->time + 3, 13);
	}
	else if (op->date == DATE_ACCES)
	{
		if (time(&t) - file->buf.st_atime > 15778800 || t < file->buf.st_atime)
			ft_date_aux(file);
		else
			write(1, file->format->time + 3, 13);
	}
	else
	{
		if (time(&t) - file->buf.st_mtime > 15778800 || t < file->buf.st_mtime)
			ft_date_aux(file);
		else
			write(1, file->format->time + 3, 13);
	}
}

static void	ft_link(t_dir *file, t_len len, size_t i)
{
	if (S_ISBLK(file->buf.st_mode) || S_ISCHR(file->buf.st_mode))
	{
		while (i++ < 5 - ft_intlen(major(file->buf.st_rdev)))
			ft_putchar (' ');
		ft_putnbr(major(file->buf.st_rdev));
		ft_putchar(',');
		i = 0;
		while (i++ < 4 - ft_intlen(minor(file->buf.st_rdev)))
			ft_putchar(' ');
		ft_putnbr(minor(file->buf.st_rdev));
	}
	else
	{
		if (len.dev)
		{
			while (i++ < len.maj_min - ft_intlen(file->buf.st_size) + 1)
				ft_putchar(' ');
		}
		else
		{
			while (i++ < len.size - ft_intlen(file->buf.st_size) + 2)
				ft_putchar(' ');
		}
		ft_putnbr(file->buf.st_size);
	}
}

static void	ft_print_long(t_dir *file, t_len len, t_option *op, size_t u)
{
	size_t		i;

	i = 0;
	ft_mode(file->absolute, file->buf.st_mode);
	while (i++ < len.links - ft_intlen(file->buf.st_nlink))
		ft_putchar(' ');
	ft_putnbr(file->buf.st_nlink);
	ft_putchar(' ');
	ft_putstr(file->format->uid_name);
	i = 0;
	while (i++ < len.uid - ft_strlen(file->format->uid_name) + u)
		ft_putchar(' ');
	ft_putstr(file->format->gid_name);
	i = 0;
	while (i++ < len.gid - ft_strlen(file->format->gid_name))
		ft_putchar(' ');
	ft_link(file, len, 0);
	if (op->long_date == LONG_DATE)
		write(1, file->format->time + 3, 21);
	else
		ft_date(file, op);
	ft_putchar(' ');
}

void		ft_ls_long_or_not(t_dir *file, t_option *op, t_len len)
{
	size_t		u;

	u = 2;
	if (op->uid == NO_UID)
		u = 0;
	if (op->format == LONG)
		ft_print_long(file, len, op, u);
	ft_putcolors(file, op);
}
