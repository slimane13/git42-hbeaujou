/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:13:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:00:37 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_dir(t_dir **begin_list)
{
	t_dir	*temp;

	temp = *begin_list;
	while (temp)
	{
		free(temp->dossier);
		free(temp->name);
		free(temp->absolute);
		free(temp->format->uid_name);
		free(temp->format->gid_name);
		free(temp->format->time);
		temp = temp->next;
	}
	*begin_list = NULL;
}

int		ft_nbfiles(t_dir **begin, t_option *op)
{
	int		f;
	t_dir	*temp;

	temp = *begin;
	f = 0;
	while (temp)
	{
		if (op->hide == 0)
		{
			if (temp->name[0] != '.')
				f++;
		}
		else
			f++;
		temp = temp->next;
	}
	return (f);
}

void	ft_getlen(t_dir *temp, t_len *len, t_option *op)
{
	len->total_blocks += temp->buf.st_blocks;
	if (ft_intlen(temp->buf.st_nlink) > len->links)
		len->links = ft_intlen(temp->buf.st_nlink);
	if (ft_strlen(temp->format->uid_name) > len->uid)
		len->uid = ft_strlen(temp->format->uid_name);
	if (ft_strlen(temp->format->gid_name) > len->gid)
		len->gid = ft_strlen(temp->format->gid_name);
	if (ft_intlen(temp->buf.st_size) > len->size)
		len->size = ft_intlen(temp->buf.st_size);
	if (op->format == 1 && (S_ISBLK(temp->buf.st_mode)
				|| S_ISCHR(temp->buf.st_mode)))
	{
		if (ft_intlen(major(temp->buf.st_rdev)) > len->major)
			len->major = ft_intlen(major(temp->buf.st_rdev));
		if (ft_intlen(minor(temp->buf.st_rdev)) > len->minor)
			len->minor = ft_intlen(minor(temp->buf.st_rdev));
	}
}

t_len	ft_format(t_dir **begin, t_option *op)
{
	t_dir	*temp;
	t_len	len;

	len = ft_initlen();
	temp = *begin;
	while (temp)
	{
		if ((op->hide == 0 && temp->name[0] != '.')
				|| op->listed == 1)
			ft_getlen(temp, &len, op);
		else if (op->hide == 1)
			ft_getlen(temp, &len, op);
		len.nb_files += 1;
		temp = temp->next;
	}
	len.maj_min = len.major + len.minor;
	if (len.maj_min >= 2)
	{
		len.dev = 1;
		len.maj_min = 9;
	}
	return (len);
}
