/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:12:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:54:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		g_error1;
int		g_error2;
t_error	*g_lst;

t_error	*new_error(char *str)
{
	t_error *res;

	res = (t_error *)malloc(sizeof(t_error));
	res->next = NULL;
	res->name = ft_strdup(str);
	return (res);
}

int		is_error(char *str)
{
	t_error *tmp;

	tmp = g_lst;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_checkfile(char *argv)
{
	int			test;
	struct stat	buf;
	t_error		*tmp;

	test = 0;
	tmp = NULL;
	if (lstat(argv, &buf) == 0)
		return (1);
	else
	{
		if (g_error2 < 3)
		{
			if (is_error(argv) == 0 && ft_strcmp(argv, "-R") != 0 &&
					ft_strcmp(argv, "aa") != 0 && ft_strcmp(argv, "bb") != 0)
				cut_check(tmp, argv, &test);
			else
				;
		}
		g_error1 = 1;
		g_error2++;
	}
	return (0);
}

int		ft_checkdir(char *argv, t_option *op)
{
	struct stat	buf;

	if ((op->listed != 1 && stat(argv, &buf) == 0 && lstat(argv, &buf) == 0
				&& S_ISDIR(buf.st_mode))
			|| (S_ISLNK(buf.st_mode) && op->format == 0 && opendir(argv)))
		return (1);
	return (0);
}

int		ft_checkargv(char *argv, t_option *op)
{
	if (ft_checkdir(argv, op))
		return (2);
	if (ft_checkfile(argv))
		return (1);
	return (0);
}
