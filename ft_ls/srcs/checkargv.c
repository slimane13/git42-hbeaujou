/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:19:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/12 17:31:34 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	error1;
int error2;
t_error *lst;

void	ft_lstaddend_error(t_error *new_r)
{
	t_error	*tmp;

	tmp = lst;
	if (!tmp)
		lst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}

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
	
	tmp = lst;
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
	int	test;
	struct stat	buf;
	t_error *tmp;

	test = 0;
	if (lstat(argv, &buf) == 0)
		return (1);
	else
	{
		if (error2 < 3)
		{
			if (is_error(argv) == 0 && ft_strcmp(argv, "-R") != 0 &&
					ft_strcmp(argv, "aa") != 0 && ft_strcmp(argv, "bb") != 0)
			{
				tmp = new_error(argv);
				ft_lstaddend_error(tmp);
				ft_putstr_fd("ft_ls: ", 2);
				if (ft_strcmp(argv, "") == 0)
				{
					ft_putstr_fd("fts_open: ", 2);
					test = 1;
				}
				perror(argv);
				if (test == 1)
					exit(0);
			}
			else
				;
		}
		error1 = 1;
		error2++;
	}
	return (0);
}

int		ft_checkdir(char *argv, t_option *op)
{
	struct stat	buf;

	if ((op->listed != LISTED && stat(argv, &buf) == 0 && lstat(argv, &buf) == 0
				&& S_ISDIR(buf.st_mode))
			|| (S_ISLNK(buf.st_mode) && op->format == NO_LONG && opendir(argv)))
		return (1);
	return (0);
}

int			ft_checkargv(char *argv, t_option *op)
{
	if (ft_checkdir(argv, op))
		return (2);
	if (ft_checkfile(argv))
		return (1);
	return (0);
}
