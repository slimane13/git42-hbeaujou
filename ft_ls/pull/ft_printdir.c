/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 05:24:36 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/05 08:03:37 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_error(char *argv, int first)
{
	if (!first)
	{
		ft_putendl_fd("", 2);
		ft_putstr_fd(argv, 2);
		ft_putendl_fd(":", 2);
	}
	ft_putstr_fd("ft_ls: ", 2);
	perror(ft_getname(argv));
}

static void	ft_print_long(t_dir *file, t_option *op, t_len len, int *p)
{
	if (op->sup_hide == SUP_HIDE && op->hide == NO_HIDE)
	{
		if (!ft_strequ(file->name, ".") && !ft_strequ(file->name, ".."))
		{
			ft_ls_long_or_not(file, op, len);
			*p = *p + 1;
		}
	}
	else if (op->hide == NO_HIDE)
	{
		if (file->name[0] != '.')
		{
			ft_ls_long_or_not(file, op, len);
			*p = *p + 1;
		}
	}
	else
	{
		ft_ls_long_or_not(file, op, len);
		*p = *p + 1;
	}
}

static void	ft_printdir_none(t_option *op, int first, t_dir **begin, int *p)
{
	t_dir	*temp;
	t_len	len;
	int		nb_f;

	temp = *begin;
	len = ft_format(&temp, op);
	nb_f = ft_nbfiles(&temp, op);
	if (first == 0 && *p > 0)
	{
		ft_putendl("");
		ft_putstr_chem(temp->dossier);
		ft_putendl(":");
	}
	if ((nb_f > 0) && op->format == LONG
			&& (len.nb_files > 2 || (len.nb_files && op->hide == HIDE)))
	{
		ft_putstr("total ");
		ft_putnbr(len.total_blocks);
		ft_putendl("");
	}
	while (temp)
	{
		ft_print_long(temp, op, len, p);
		temp = temp->next;
	}
}

static void	ft_printdir_rec(char *argv, t_option *op, int first, int *p)
{
	t_dir	*current;
	t_dir	*temp;

	if ((current = ft_recup(argv, op)) != NULL)
	{
		temp = current;
		ft_lstsort(&current, op);
		if (!ft_hide_dir(argv) || op->hide == HIDE)
			ft_printdir_none(op, first, &temp, p);
		while (temp)
		{
			if (S_ISDIR(temp->buf.st_mode) && (!ft_strequ(temp->name, ".")
						&& !ft_strequ(temp->name, "..")))
			{
				ft_printdir_rec(temp->absolute, op, 0, p);
			}
			temp = temp->next;
		}
		ft_free_dir(&current);
	}
	else
		ft_error(argv, first);
}

void		ft_printdir(char *argv, t_option *op)
{
	t_dir	*current;
	int		p;

	p = 0;
	if (op->rec == RECURSIVE)
		ft_printdir_rec(argv, op, 1, &p);
	else
	{
		if ((current = ft_recup(argv, op)) != NULL)
		{
			ft_lstsort(&current, op);
			ft_printdir_none(op, 1, &current, &p);
		}
		else
			ft_error(argv, 1);
	}
}
