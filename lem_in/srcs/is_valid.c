/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:41:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 12:27:37 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_valid_coord(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != ' ')
			return (0);
		if (ft_isdigit(line[i]) == 1 &&
				(line[i + 1] == ' ' || line[i + 1] == '\0'))
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	else
		return (0);
}

int			is_valid_tunnel(char *line)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (0);
		else if (line[i] == '-')
			nbr++;
		i++;
	}
	if (nbr != 1)
		return (0);
	return (1);
}

void		ft_lstaddend_path(t_path **alst, t_path *new_r)
{
	t_path	*tmp;

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

void		ft_lstaddend_reseau(t_reseau **alst, t_reseau *new_r)
{
	t_reseau	*tmp;

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

t_path		*new_path(char *str)
{
	t_path *res;

	if (!(res = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	res->name = ft_strdup(str);
	res->next = NULL;
	return (res);
}

t_reseau	*new_reseau(int choix, t_path *path)
{
	t_reseau *res;

	if (!(res = (t_reseau *)malloc(sizeof(t_reseau))))
		return (NULL);
	res->choix = choix;
	res->next = NULL;
	res->path = path;
	return (res);
}
