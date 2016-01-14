/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rajouts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 15:07:12 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 17:05:21 by hbeaujou         ###   ########.fr       */
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

t_long	*ft_recup_long(struct stat buf, t_option *op)
{
	t_long			*elem;
	struct passwd	*pass_uid;
	struct group	*pass_gid;

	if ((elem = (t_long *)malloc(sizeof(t_long))) != NULL)
	{
		pass_uid = getpwuid(buf.st_uid);
		pass_gid = getgrgid(buf.st_gid);
		elem->time = ft_strdup(ctime(&buf.st_mtime));
		if (op->date == 2)
			elem->time = ft_strdup(ctime(&buf.st_birthtime));
		else if (op->date == 3)
			elem->time = ft_strdup(ctime(&buf.st_atime));
		if (op->uid == 0)
			elem->uid_name = ft_strdup("");
		else if (pass_uid)
			elem->uid_name = ft_strdup(pass_uid->pw_name);
		else
			elem->uid_name = ft_itoa(buf.st_uid);
		if (pass_gid)
			elem->gid_name = ft_strdup(pass_gid->gr_name);
		else
			elem->gid_name = ft_itoa(buf.st_gid);
	}
	return (elem);
}
