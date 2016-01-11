/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 21:27:41 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/04 17:48:05 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_getinfos(struct dirent *l, t_dir **f, char *argv, t_option *op)
{
	char			*chem;
	struct stat		buf;
	char			linkname[256];
	size_t			ret;

	chem = ft_strjoin_dir(argv, l->d_name);
	bzero(&buf, sizeof(buf));
	if (lstat(chem, &buf) == 0)
	{
		ft_lstadd_ls(f, buf);
		(*f)->name = ft_strdup(l->d_name);
		(*f)->dossier = ft_strjoin_dir(argv, "");
		(*f)->absolute = ft_strdup(chem);
		free(chem);
		(*f)->format = ft_recup_long(buf, op);
		if (S_ISLNK(buf.st_mode))
		{
			if ((ret = readlink((*f)->absolute, linkname, 256)))
			{
				linkname[ret] = '\0';
				(*f)->format->linkname = ft_strdup(linkname);
			}
		}
	}
}

t_dir		*ft_recup(char *argv, t_option *op)
{
	DIR				*dirp;
	struct dirent	*lect;
	t_dir			*file;

	file = NULL;
	if ((dirp = opendir(argv)) != NULL)
	{
		while ((lect = readdir(dirp)) != NULL)
			ft_getinfos(lect, &file, argv, op);
		closedir(dirp);
	}
	return (file);
}
