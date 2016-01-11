/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:29:47 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/11 15:12:19 by hbeaujou         ###   ########.fr       */
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
		while (p <= max)
		{
			tmp->modif = ft_strjoin(" ", tmp->modif);
			p++;
		}
		tmp = tmp->next;
	}
}

void	affiche_chmod(t_file *tmp)
{
	if ((S_ISDIR(tmp->stats.st_mode)) == 1)
		ft_putstr("d");
	else
		ft_putstr("-");
	ft_printf( (tmp->stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_printf( (tmp->stats.st_mode & S_IWUSR) ? "w" : "-");
	if ((tmp->stats.st_mode & S_IXUSR) == 1)
		ft_putstr("x");
	else
		ft_putstr("-");
	ft_printf( (tmp->stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_printf( (tmp->stats.st_mode & S_IWGRP) ? "w" : "-");
	if ((tmp->stats.st_mode & S_IXGRP) == 1)
		ft_putstr("x");
	else
		ft_putstr("-");
	ft_printf( (tmp->stats.st_mode & S_IROTH) ? "r" : "-");
	ft_printf( (tmp->stats.st_mode & S_IWOTH) ? "w" : "-");
	if ((tmp->stats.st_mode & S_IXOTH) == 1)
		ft_putstr("x");
	else
		ft_putstr("-");
	ft_putstr(" ");
}

void	affiche_column(t_file **files, t_flag **flags, char *str, int ac)
{
	int				max_size;
	int				tot;
	int				max_size2;
	char			*date;
	char			*tmp2;
	t_file			*tmp;
	struct 	passwd	*pwd;
	struct 	group	*pwd2;

	tot = 0;
	tmp = *files;
	max_size = max_len(files);
	size_to_modif(files, max_size);
	max_size2 = max_len_2(files);
	size_to_modif2(files, max_size);
	pwd = getpwuid(tmp->stats.st_uid);
	pwd2 = getgrgid(tmp->stats.st_gid);
	while (tmp)
	{
		tot = tot + tmp->stats.st_blocks;
		tmp = tmp->next;
	}
	tmp = *files;
	ft_printf("total %d\n", tot);
	while (tmp)
	{
		date = ctime(&tmp->stats.st_mtime);
		date = ft_strsub(date, 4, ft_strlen(date) - 13);
		affiche_chmod(tmp);
		ft_printf(" %s %s  %s  %s %s %s\n", tmp->modif2, pwd->pw_name,
				pwd2->gr_name, tmp->modif, date, tmp->name);
		tmp = tmp->next;
	}
	tmp = *files;
	if (EFRM == 1)
	{
		while (tmp)
		{
			if ((S_ISDIR(tmp->stats.st_mode)) == 1 && tmp->name[0] != '.' &&
					ft_strcmp(tmp->name, "..") != 0)
			{
				path = ft_strjoin(str, "/");
				path = ft_strjoin(path, tmp->name);
				tmp2 = ft_strsub(path, 3, ft_strlen(path));
				tmp2 = ft_strjoin("./", tmp2);
				ft_printf ("\n%s :\n", tmp2);
				argc_one(files, flags, path, ac);
			}
			tmp = tmp->next;
		}
	}
}
