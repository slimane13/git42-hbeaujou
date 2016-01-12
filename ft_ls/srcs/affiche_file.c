/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 23:12:07 by bsautron          #+#    #+#             */
/*   Updated: 2016/01/12 12:21:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_the_file(t_dir **begin, t_option *op)
{
	t_len		len;
	t_dir		*temp;

	temp = *begin;
	len = ft_format(begin, op);
	while (temp)
	{
		ft_ls_long_or_not(temp, op, len);
		temp = temp->next;
	}
}

static void	ft_getinfos_file(t_dir **file, char *argv, t_option *op)
{
	char		*linkname;
	struct stat	buf;

	bzero(&buf, sizeof(buf));
	lstat(argv, &buf);
	ft_lstadd_ls(file, buf);
	(*file)->name = ft_strdup(argv);
	(*file)->absolute = ft_strdup(argv);
	(*file)->format = ft_recup_long(buf, op);
	if (S_ISLNK(buf.st_mode))
	{
		linkname = (char *)malloc(sizeof(char) * 256);
		if (readlink(argv, linkname, 256))
			(*file)->format->linkname = ft_strdup(linkname);
	}
}

void		ft_printfile(char **argv, t_option *op, int *nb)
{
	int				i;
	t_dir			*file;

	i = 0;
	file = NULL;
	while (i < nb[OUT_FILES])
	{
		ft_getinfos_file(&file, argv[i], op);
		i++;
	}
	ft_lstsort(&file, op);
	ft_print_the_file(&file, op);
}
