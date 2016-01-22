/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_add_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:55:36 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 16:46:51 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	cut_1_5_param(t_tempo **vars, int test)
{
	while ((*vars)->i < ft_strlen(g_op_tab[test - 1].name) - 1)
		(*vars)->i++;
	(*vars)->i++;
	(*vars)->name = ft_strsub((*vars)->str2, 0, (*vars)->i);
	(*vars)->j = (*vars)->i + 1;
	while ((*vars)->str2[(*vars)->i] != SEPARATOR_CHAR)
		(*vars)->i++;
	(*vars)->param1 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
	(*vars)->j = (*vars)->i + 1;
	while ((*vars)->str2[(*vars)->j] != SEPARATOR_CHAR)
		(*vars)->j++;
	(*vars)->i++;
	(*vars)->param2 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
	(*vars)->i = (*vars)->j + 1;
}

void	cut_2_5_param(t_tempo **vars, int test)
{
	while ((*vars)->str2[(*vars)->i] != SEPARATOR_CHAR)
		(*vars)->i++;
	(*vars)->j++;
	(*vars)->param3 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
	(*vars)->j = (*vars)->i + 1;
	while ((*vars)->str2[(*vars)->j] != SEPARATOR_CHAR)
		(*vars)->j++;
	(*vars)->i++;
	(*vars)->param4 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
	(*vars)->i = (*vars)->j + 1;
	while ((*vars)->str2[(*vars)->i] != '\0')
		(*vars)->i++;
	(*vars)->j++;
	(*vars)->param5 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
}
