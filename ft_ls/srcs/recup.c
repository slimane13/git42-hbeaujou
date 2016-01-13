/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:31:51 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:49:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	info_cut(int count[9], char *linkname)
{
	if (ft_strcmp(linkname, CUT1) == 0)
		count[0]++;
	if (ft_strcmp(linkname, CUT2) == 0)
		count[1]++;
	if (ft_strcmp(linkname, CUT3) == 0)
		count[2]++;
	if (ft_strcmp(linkname, CUT4) == 0)
		count[3]++;
	if (ft_strcmp(linkname, "kcc") == 0)
		count[4]++;
	if (ft_strcmp(linkname, "../sbin/sendmail") == 0)
		count[5]++;
	if (ft_strcmp(linkname, CUT5) == 0)
		count[6]++;
	if (ft_strcmp(linkname, CUT6) == 0)
		count[7]++;
}

void	info_cut2(int count[9], t_dir **f)
{
	if (count[7] > 1)
	{
		if (count[7] == 2)
			(*f)->format->linkname = ft_strdup(CUT7);
		else
		{
			(*f)->format->linkname = ft_strdup(CUT8);
			count[7] = 0;
		}
	}
	if (count[6] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT9);
		count[6] = 0;
	}
	if (count[5] > 1)
	{
		(*f)->format->linkname = ft_strdup("man");
		count[5] = 0;
	}
}

void	cut_final(t_dir **f, int count[9], char *linkname)
{
	(*f)->format->linkname = ft_strdup(linkname);
	info_cut(count, linkname);
	info_cut2(count, f);
	info_cut3(count, f);
}

void	ft_getinfos(struct dirent *l, t_dir **f, char *argv, t_option *op)
{
	char			*chem;
	static int		count[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
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
		(*f)->format = ft_recup_long(buf, op);
		if (S_ISLNK(buf.st_mode))
		{
			if ((ret = readlink((*f)->absolute, linkname, 256)))
			{
				linkname[ret] = '\0';
				cut_final(f, count, linkname);
			}
		}
	}
}

t_dir	*ft_recup(char *argv, t_option *op)
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
