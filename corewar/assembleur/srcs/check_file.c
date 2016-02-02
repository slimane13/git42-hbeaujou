/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 13:43:40 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/02/01 12:32:43 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		is_in_tab(int a, int *tab, int i)
{
	if (tab[i] & a)
		return (1);
	return (0);
}

void	check_params(char *str, int *tab, int i, char *str2)
{
	if (str[0] == 'r')
		cut_check_p1(str, str2, tab, i);
	else if (str[0] == DIRECT_CHAR)
		cut_check_p2(str, str2, tab, i);
	else
		cut_check_p3(str, str2, tab, i);
}

void	check_instruct(t_instruct **content, char *str2)
{
	t_instruct	*tmp;
	char		*str;
	int			i;
	int			test;

	tmp = *content;
	i = 0;
	str = tmp->name;
	tmp = tmp->next;
	while (tmp)
	{
		test = str_to_int(str);
		check_params(tmp->name, g_op_tab[test].params_types, i, str2);
		tmp = tmp->next;
		i++;
	}
}

void	check_funct(t_line **lines, char *str2)
{
	t_line	*tmp;

	tmp = *lines;
	while (tmp)
	{
		check_instruct(&tmp->content, str2);
		tmp = tmp->next;
	}
}

void	check_file(t_function **file)
{
	t_function *tmp;

	tmp = *file;
	if (!tmp)
	{
		ft_printf("No content\n");
		exit(1);
	}
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->header == 1 || tmp->header == 2)
	{
		ft_printf("Only comment and name\n");
		exit(0);
	}
	tmp = *file;
	while (tmp)
	{
		if (tmp->header == 0)
			check_funct(&tmp->lines, tmp->label);
		tmp = tmp->next;
	}
}
