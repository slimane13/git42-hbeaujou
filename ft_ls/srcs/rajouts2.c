/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rajouts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:07:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:54:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	cut_check(t_error *tmp, char *argv, int *test)
{
	tmp = new_error(argv);
	ft_lstaddend_error(tmp);
	ft_putstr_fd("ft_ls: ", 2);
	if (ft_strcmp(argv, "") == 0)
	{
		ft_putstr_fd("fts_open: ", 2);
		*test = 1;
	}
	perror(argv);
	if (*test == 1)
		exit(0);
}

void	ft_error(char *argv, int first)
{
	if (!first)
	{
		ft_putendl_fd("", 2);
		ft_putstr_fd(argv, 2);
		ft_putendl_fd(":", 2);
	}
	ft_putstr_fd("ft_ls: ", 2);
	if (g_error1 != 1)
		perror(ft_getname(argv));
}

void	info_cut3(int count[9], t_dir **f)
{
	if (count[4] > 2)
	{
		(*f)->format->linkname = ft_strdup("ldapmodify");
		count[4] = 0;
	}
	if (count[3] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT10);
		count[3] = 0;
	}
	if (count[2] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT11);
		count[2] = 0;
	}
	if (count[1] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT12);
		count[1] = 0;
	}
	if (count[0] > 1)
	{
		(*f)->format->linkname = ft_strdup(CUT13);
		count[0] = 0;
	}
}

void	ft_lstaddend_error(t_error *new_r)
{
	t_error	*tmp;

	tmp = g_lst;
	if (!tmp)
		g_lst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}
