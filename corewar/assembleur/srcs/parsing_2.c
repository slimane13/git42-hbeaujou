/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:03:47 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/26 12:10:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		str_to_int(char *str)
{
	int		i;

	i = 0;
	while (ft_strcmp(g_op_tab[i].name, str) != 0 &&
			ft_strcmp(g_op_tab[i].name, "0") != 0)
		i++;
	if (ft_strcmp(g_op_tab[i].name, "0") == 0)
	{
		ft_printf("Function with no parameters\n");
		exit(0);
	}
	return (i);
}

int		recup_opcode(char *str)
{
	int		i;

	i = 0;
	while (g_op_tab[i].name && ft_strcmp(g_op_tab[i].name, str) != 0)
		i++;
	if (!g_op_tab[i].name)
		return (0);
	return (g_op_tab[i].opcode);
}

int		check_name_double(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (0);
	return (1);
}

int		check_name_solo(char *str)
{
	int	i;
	int	j;
	int fini;

	i = 0;
	fini = 0;
	while (str[i] && fini == 0 && str[i] != ' ' && str[i] != '\t')
	{
		j = 0;
		while (LABEL_CHARS[j])
		{
			if (str[i] == LABEL_CHARS[j])
				break ;
			j++;
		}
		if (LABEL_CHARS[j] == '\0')
			fini = 1;
		else
			i++;
	}
	if (str[i] == LABEL_CHAR)
		return (1);
	check_space_label(i, str);
	return (0);
}
