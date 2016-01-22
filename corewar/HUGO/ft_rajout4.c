/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:17:36 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 16:47:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	cut_1_6_param(t_tempo **vars, int test)
{
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

void	cut_2_6_param(t_tempo **vars, int test)
{
	while ((*vars)->str2[(*vars)->j] != SEPARATOR_CHAR)
		(*vars)->j++;
	(*vars)->i++;
	(*vars)->param4 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
	(*vars)->i = (*vars)->j + 1;
	while ((*vars)->str2[(*vars)->i] != SEPARATOR_CHAR)
		(*vars)->i++;
	(*vars)->j++;
	(*vars)->param5 = ft_strsub((*vars)->str2,
			(*vars)->j, (*vars)->i - (*vars)->j);
	(*vars)->j = (*vars)->i + 1;
	while ((*vars)->str2[(*vars)->j] != '\0')
		(*vars)->i++;
	(*vars)->i++;
	(*vars)->param6 = ft_strsub((*vars)->str2,
			(*vars)->i, (*vars)->j - (*vars)->i);
}

void	cut_parsing_1(t_function **file, char *line, int test)
{
	if (g_begin != 2)
		exit_prgm_nbr(NULL, NULL);
	add_fun(file, line, test);
}

void	cut_parsing_2(t_function **file, char *line, int test)
{
	int		i;
	char	*str3;

	str3 = NULL;
	i = 0;
	if (g_begin != 2)
		exit_prgm_nbr(NULL, NULL);
	while (line[i] != LABEL_CHAR)
		i++;
	i++;
	str3 = ft_strsub(line, 0, i);
	add_fun(file, str3, test);
	str3 = ft_strsub(line, i + 1, ft_strlen(line) - i);
	g_tmp = check_line(str3);
	add_command(g_tmp, file, str3);
}

void	cut_parsing_3(t_function **file, char *line, int test)
{
	int	i;

	i = 0;
	while (i < test)
		i++;
	i--;
	if (g_op_tab[i].nb_params == 1)
		add_line_1_param(file, line, test);
	else if (g_op_tab[i].nb_params == 2)
		add_line_2_param(file, line, test);
	else if (g_op_tab[i].nb_params == 3)
		add_line_3_param(file, line, test);
	else if (g_op_tab[i].nb_params == 4)
		add_line_4_param(file, line, test);
	else if (g_op_tab[i].nb_params == 5)
		add_line_5_param(file, line, test);
	else if (g_op_tab[i].nb_params == 6)
		add_line_6_param(file, line, test);
}
