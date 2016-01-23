/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:24:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/22 14:33:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		cut_check_begin(char *tmp)
{
	if (g_begin > 1)
		return (0);
	g_begin++;
	return (check_begin(tmp));
}

void	cut_param_3(t_tempo **vars, int test)
{
	while ((*vars)->i < (int)ft_strlen(g_op_tab[test - 1].name) - 1)
		(*vars)->i++;
	(*vars)->i++;
	(*vars)->name = ft_strsub((*vars)->str2, 0, (*vars)->i);
	(*vars)->j = (*vars)->i;
	while ((*vars)->str2[(*vars)->j] != SEPARATOR_CHAR)
		(*vars)->j++;
	(*vars)->param1 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
	(*vars)->i = (*vars)->j + 1;
	while ((*vars)->str2[(*vars)->i] != SEPARATOR_CHAR)
		(*vars)->i++;
	(*vars)->j++;
	(*vars)->param2 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
	(*vars)->j = (*vars)->i + 1;
	while ((*vars)->str2[(*vars)->j] != '\0')
		(*vars)->j++;
	(*vars)->i++;
	(*vars)->param3 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
}

void	cut_param_4(t_tempo **vars, int test)
{
	while ((*vars)->i < (int)ft_strlen(g_op_tab[test - 1].name) - 1)
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
	while ((*vars)->str2[(*vars)->i] != SEPARATOR_CHAR)
		(*vars)->i++;
	(*vars)->j++;
	(*vars)->param3 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
	(*vars)->j = (*vars)->i + 1;
}
