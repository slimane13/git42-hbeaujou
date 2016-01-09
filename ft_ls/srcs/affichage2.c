/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:51:17 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 18:08:05 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	into_dir(t_file **files, t_flag **flags, char *str)
{
	DIR				*dir;
	struct dirent	*ent;
	struct stat		t_stats;
	t_file			*tmp;

	if ((dir = opendir (str)) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
		{
			stat(ent->d_name, &t_stats);
			if (ft_strcmp(ent->d_name, ".") == 0 ||
					ft_strcmp(ent->d_name, "..") == 0)
				;
			else
			{
				tmp = new_file(ent->d_name, &t_stats);
				ft_lstaddend_file(files, tmp);
			}
		}
		closedir (dir);
	}
	else
		perror ("");
	modif_names(files);
	if (EFL == 1)
		affiche_column(files, flags);
	else
		affiche_files_acone(files);
}

int		max_len_2(t_file **files)
{
	int		max;
	int		p;
	t_file	*tmp;

	max = 0;
	p = 0;
	tmp = *files;
	while (tmp)
	{
		p = tmp->stats.st_nlink;
		if (ft_nbrlen(p) > max)
			max = ft_nbrlen(p);
		tmp = tmp->next;
	}
	return (max);
}

void	size_to_modif2(t_file **files, int max)
{
	int		p;
	t_file	*tmp;

	tmp = *files;
	p = 0;
	while (tmp)
	{
		tmp->modif2 = ft_itoa(tmp->stats.st_nlink);
		p = ft_strlen(tmp->modif2);
		while (p < max - 4)
		{
			tmp->modif2 = ft_strjoin(" ", tmp->modif2);
			p++;
		}
		tmp = tmp->next;
	}
}
