/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:06:55 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 18:29:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

t_file	*new_file(char *name)
{
	t_file	*res;

	if (!(res = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	res->next = NULL;
	res->name = ft_strdup(name);
	return (res);
}

void	parsing(char **av, t_flag **flag, t_file **files)
{
	t_file	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (av[j])
	{
		if (is_flag(av[j]) == 1)    ///////// A FAIRE
			attrib_flag(av[j], flag); //////////////// A FAIRE
		else
		{
			tmp = new_file(av[j]);
			ft_lstaddend_file(files, tmp);
		}
		j++;
	}
}
