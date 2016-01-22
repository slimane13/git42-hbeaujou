/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fct_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:07:40 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 16:46:38 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_line_4_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	cut_param_4(&vars, test);
	while (vars->str2[vars->j] != '\0')
		vars->j++;
	vars->i++;
	vars->param4 = ft_strsub(vars->str2, vars->i, vars->j);
	make_line_4(file, vars);
	free(vars);
}

void	add_line_5_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	cut_1_5_param(&vars, test);
	cut_2_5_param(&vars, test);
	make_line_5(file, vars);
	free(vars);
}

void	add_line_6_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	while (vars->str2[vars->i] !=
			g_op_tab[test - 1].name[ft_strlen(g_op_tab[test - 1].name) - 1])
		vars->i++;
	vars->i++;
	vars->name = ft_strsub(vars->str2, 0, vars->i);
	vars->j = vars->i;
	cut_1_6_param(&vars, test);
	cut_2_6_param(&vars, test);
	make_line_6(file, vars);
	free(vars);
}
