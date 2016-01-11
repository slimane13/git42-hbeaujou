/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:06:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/11 14:55:09 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	exit_prgm(int c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	exit(0);
}

void	ft_lstaddend_file(t_file **alst, t_file *new_r)
{
	t_file	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}

t_file	*new_file(char *name, struct stat *sb, struct stat *sa)
{
	t_file	*res;

	if (!(res = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	res->next = NULL;
	res->previous = NULL;
	res->name = ft_strdup(name);
	res->stats = *sb;
	res->lstats = *sa;
	return (res);
}

void	parsing(char **av, t_flag **flag, t_file **files)
{
	t_file		*tmp;
	int			i;
	int			j;
	struct stat	t_stats;
	struct stat	l_stats;

	i = 0;
	j = 1;
	if (av[j][0] == '-')
	{
		if (is_flag(av[j]) == 1)
			attrib_flag(av[j], flag);
	   	else
			exit_prgm(is_flag(av[j]));
		j++;
	}
	if (ft_strcmp(av[j] , "--") == 0)
		j++;
	while (av[j])
	{
		stat(av[j], &t_stats);
		lstat(av[j], &l_stats);
		tmp = new_file(av[j], &t_stats, &l_stats);
		ft_lstaddend_file(files, tmp);
		j++;
	}
}

void	parsing_one(char **av, t_flag **flag)
{
	if (is_flag(av[1]) == 1)
		attrib_flag(av[1], flag);
	else
		exit_prgm(is_flag(av[1]));
}
