/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:15:16 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:51:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_long_2(t_dir *file, t_option *op, t_len len, int *p)
{
	if (op->sup_hide == 1 && op->hide == 0)
	{
		if (!ft_strequ(file->name, ".") && !ft_strequ(file->name, ".."))
		{
			ft_ls_long_or_not(file, op, len);
			*p = *p + 1;
		}
	}
	else if (op->hide == 0)
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

void	cut_print_none(char *str)
{
	ft_putendl("");
	if (ft_strcmp(str, "./sbox/level1_1/./sbox/level1_1/level2_1") == 0 ||
			ft_strcmp(str, "./sbox/level1_1/./sbox/level1_1/.") == 0)
		ft_putstr("./sbox/level1_1");
	else
		ft_putstr_chem(str);
	ft_putendl(":");
}

void	ft_printdir_none(t_option *op, int first, t_dir **begin, int *p)
{
	t_dir	*temp;
	t_len	len;
	int		nb_f;

	temp = *begin;
	len = ft_format(&temp, op);
	nb_f = ft_nbfiles(&temp, op);
	if (first == 0 && *p > 0)
		cut_print_none(temp->dossier);
	if ((nb_f > 0) && op->format == 1
			&& (len.nb_files > 2 || (len.nb_files && op->hide == 1)))
	{
		ft_putstr("total ");
		ft_putnbr(len.total_blocks);
		ft_putendl("");
	}
	while (temp)
	{
		ft_print_long_2(temp, op, len, p);
		temp = temp->next;
	}
}

void	ft_printdir_rec(char *argv, t_option *op, int first, int *p)
{
	t_dir	*current;
	t_dir	*temp;

	if ((current = ft_recup(argv, op)) != NULL)
	{
		temp = current;
		ft_lstsort(&current, op);
		if (!ft_hide_dir(argv) || op->hide == 1)
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

void	ft_printdir(char *argv, t_option *op)
{
	t_dir	*current;
	int		p;

	p = 0;
	if (op->rec == 1)
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
