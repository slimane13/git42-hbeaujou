/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:35:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 15:20:56 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void		ft_lstaddend_line(t_line **alst, t_line *new_r)
{
	t_line	*tmp;

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

void		ft_lstaddend_instruct(t_line **alst, t_instruct *new_r)
{
	t_line		*tmp2;
	t_instruct	*tmp;

	tmp2 = *alst;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp = tmp2->content;
	if (!tmp)
		tmp2->content = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
	}
}

t_function	*new_function(char *str)
{
	t_function *res;

	if (!(res = (t_function *)malloc(sizeof(t_function))))
		return (NULL);
	res->header = 0;
	res->bytes_written = 0;
	if (str != NULL)
		res->label = ft_strdup(str);
	else
		str = NULL;
	res->lines = NULL;
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_line		*new_line(int count)
{
	t_line *res;

	if (!(res = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	res->numero = count;
	res->content = NULL;
	res->next = NULL;
	return (res);
}

t_instruct	*new_instruct(char *str, int typ, int opcod)
{
	t_instruct *res;

	if (!(res = (t_instruct *)malloc(sizeof(t_instruct))))
		return (NULL);
	res->name = ft_strdup(str);
	res->type = typ;
	res->opcode = opcod;
	res->next = NULL;
	return (res);
}
