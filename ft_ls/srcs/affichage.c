/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:29:47 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 17:21:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		nbr_files(t_file **files)
{
	int 	tot;
	t_file	*tmp;

	tmp = *files;
	tot = 0;
	while (tmp)
	{
		tot++;
		tmp = tmp->next;
	}
	return (tot);
}

int		max_len(t_file **files)
{
	int		max;
	int		p;
	t_file	*tmp;

	max = 0;
	p = 0;
	tmp = *files;
	while (tmp)
	{
		p = tmp->stats.st_size;
		if (ft_nbrlen(p) > max)
			max = ft_nbrlen(p);
		tmp = tmp->next;
	}
	return (max);
}

void	size_to_modif(t_file **files, int max)
{
	int		p;
	t_file	*tmp;

	tmp = *files;
	p = 0;
	while (tmp)
	{
		tmp->modif = ft_itoa(tmp->stats.st_size);
		p = ft_strlen(tmp->modif);
		while (p < max)
		{
			tmp->modif = ft_strjoin(" ", tmp->modif);
			p++;
		}
		tmp = tmp->next;
	}
}
void	affiche_column(t_file **files, t_flag **flags)
{
	int				max_size;
	t_file			*tmp;
	struct 	passwd	*pwd;
	struct 	group	*pwd2;

	tmp = *files;
	max_size = max_len(files);
	size_to_modif(files, max_size);
	pwd = getpwuid(tmp->stats.st_uid);
	pwd2 = getgrgid(tmp->stats.st_gid);
	while (tmp)
	{
		ft_printf("%d %s  %s  %s %s\n", tmp->stats.st_nlink, pwd->pw_name,
				pwd2->gr_name, tmp->modif, tmp->name);
		tmp = tmp->next;
	}
}
