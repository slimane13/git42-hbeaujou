/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:54:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/11 16:00:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*path;
int		g_test;
int		g_nbrf;

void	modif_names(t_file **files)
{
	t_file	*tmp;
	int		max;
	int		p;

	max = 0;
	p = 0;
	tmp = *files;
	while (tmp)
	{
		p = ft_strlen(tmp->name);
		p = p + 8 - (p % 8);
		if (p > max)
			max = p;
		tmp = tmp->next;
	}
	tmp = *files;
	while (tmp)
	{
		p = ft_strlen(tmp->name);
		tmp->modif = ft_strdup(tmp->name);
		while (p < max)
		{
			tmp->modif = ft_strjoin(tmp->modif, " ");
			p++;
		}
		tmp = tmp->next;
	}
}

void	affiche_files_acone(t_file **files, t_flag **flags, int ac)
{
	int 	i;
	int		nb;
	char	*tmp2;
	t_file	*tmp;

	i = 1;
	nb = nbr_files(files);
	tmp = *files;
	while (tmp)
	{
		if ((i % 5 == 0 && i != 0) || i == nb || EFUN == 1)
		{
			if ((S_ISDIR(tmp->stats.st_mode)) == 1 && tmp->name[0] != '.' &&
					ft_strcmp(tmp->name, "..") != 0 && ac > 2)
			{
				if (g_nbrf != 1)
					ft_printf("%s:\n", tmp->name);
				tmp2 = ft_strjoin("./", tmp->name);
				ft_printf("%c", 0);
				argc_one(files, flags, tmp2, ac);
			}
			else
				ft_printf("%s\n", tmp->name);
		}
		else
			ft_printf("%s", tmp->modif);
		i++;
		tmp = tmp->next;
		if (tmp)
		{
			if ((S_ISDIR(tmp->stats.st_mode)) == 1 && tmp->name[0] != '.' &&
				ft_strcmp(tmp->name, "..") != 0 && ac > 2)
			{
				ft_printf("\n");
				if (!tmp->next)
					ft_printf("\n");
			}
		}
	}
}

void	argc_one(t_file **files, t_flag **flags, char *str, int ac)
{
	DIR				*dir;
	char			*path2;
	char			*tmp2;
	struct dirent	*ent;
	struct stat		t_stats;
	struct stat		l_stats;
	t_file			*tmp;

	*files = NULL;
	if ((dir = opendir (str)) != NULL)
	{
		while ((ent = readdir (dir)) != NULL)
		{
			if (g_test != 0)
				path2 = ft_strjoin(path, "/");
			path2 = ft_strjoin(path2, ent->d_name);
			g_test = 1;
			stat(path2, &t_stats);
			lstat(ent->d_name, &l_stats);
			if ((ent->d_name[0] == '.' ||
						ft_strcmp(ent->d_name, "..") == 0) && EFA == 0)
				;
			else
			{
				tmp = new_file(ent->d_name, &t_stats, &l_stats);
				ft_lstaddend_file(files, tmp);
			}
		}
		closedir (dir);
	}
	else
		perror ("");
	modif_names(files);
	if (EFT == 1)
		tri_time(files);
	else
		tri_char(files);
	if (EFR == 1)
		tri_rev(files);
	if (EFL == 1)
		affiche_column(files, flags, str, ac);
	else
	{
		affiche_files_acone(files, flags, ac);
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
					if (EFRM == 1 && EFUN == 1)
						ft_printf ("\n%s:\n", tmp2);
					else
						ft_printf ("\n%s :\n", tmp2);
					argc_one(files, flags, path, ac);
				}
				tmp = tmp->next;
			}
		}
	}
	tmp = *files;
}

void	init_flags(t_flag **flags)
{
	EFL = 0;
	EFRM = 0;
	EFA = 0;
	EFR = 0;
	EFT = 0;
	EFU = 0;
	EFF = 0;
	EFG = 0;
	EFD = 0;
	EFUN = 0;
}

int		ft_ls(int ac, char **av)
{
	t_file			*files;
	t_file			*tmp;
	t_flag			*flags;

	if (!(flags = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	files = NULL;
	init_flags(&flags);
	if (ac == 1 || ac == 2)
	{
		if (ac == 2)
			parsing_one(av, &flags);
		argc_one(&files, &flags, "./", ac);
		return EXIT_SUCCESS;
	}
	else
	{
		parsing(av, &flags, &files);
		if (FL == 0)
		{
			modif_names(&files);
			if (FT == 1)
				tri_time_onlyfiles(&files);
			affiche_files_acone(&files, &flags, ac);
		}
		else
		{
			tmp = files;
			while (tmp)
			{
				ft_printf("%s:\n", tmp->name);
				argc_one(&files, &flags, tmp->name, ac);
				tmp = tmp->next;
				if (tmp)
					ft_printf("\n");
			}
		}
	}
	exit(EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	g_nbrf = 0;
	while (av[g_nbrf])
		g_nbrf++;
	if (ac > 1)
	{
		if (av[1][0] == '-' && av[1][1] != '-')
			g_nbrf--;
	}
	if (ac > 2)
	{
		if (ft_strcmp(av[2], "--") == 0)
			g_nbrf--;
	}
	g_nbrf--; 
	g_test = 0;
	path = ft_strdup("./");
	ft_ls(ac, av);
	return (1);
}
