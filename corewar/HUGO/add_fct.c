/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 11:05:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 16:46:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		g_nb_line;

void	add_c_name(t_function **file, char *line, int test)
{
	int			i;
	int			j;
	char		*tmp2;
	t_function	*tmp;

	i = 0;
	j = 0;
	tmp2 = ft_strtrim(line);
	tmp2 = ft_strsub(tmp2, ft_strlen(NAME_CMD_STRING), ft_strlen(tmp2));
	tmp2 = ft_strtrim(tmp2);
	tmp = new_function(tmp2);
	tmp->header = 1;
	ft_lstaddend_funct(file, tmp);
}

void	add_comment(t_function **file, char *line, int test)
{
	int			i;
	int			j;
	char		*tmp2;
	t_function	*tmp;

	i = 0;
	j = 0;
	tmp2 = ft_strtrim(line);
	tmp2 = ft_strsub(tmp2, ft_strlen(COMMENT_CMD_STRING), ft_strlen(tmp2));
	tmp2 = ft_strtrim(tmp2);
	tmp = new_function(tmp2);
	tmp->header = 2;
	ft_lstaddend_funct(file, tmp);
}

void	add_fun(t_function **file, char *line, int test)
{
	int			i;
	char		*tmp;
	t_function	*tmp2;

	i = 0;
	while (line[i] != LABEL_CHAR)
		i++;
	g_nb_line = 0;
	tmp = ft_strsub(line, 0, i);
	tmp2 = new_function(tmp);
	ft_lstaddend_funct(file, tmp2);
}

void	add_line_1_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	while (vars->i < ft_strlen(g_op_tab[test - 1].name) - 1)
		vars->i++;
	vars->i++;
	vars->name = ft_strsub(vars->str2, 0, vars->i);
	vars->j = vars->i;
	while (vars->str2[vars->i] != '\0')
		vars->i++;
	vars->param1 = ft_strsub(vars->str2, vars->j, vars->i - vars->j);
	make_line_1(file, vars);
	free(vars);
}

void	add_line_2_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	while (vars->i < ft_strlen(g_op_tab[test - 1].name) - 1)
		vars->i++;
	vars->i++;
	vars->name = ft_strsub(vars->str2, 0, vars->i);
	vars->j = vars->i + 1;
	while (vars->str2[vars->j] != SEPARATOR_CHAR)
		vars->j++;
	vars->param1 = ft_strsub(vars->str2, vars->i, vars->j - vars->i);
	vars->i = vars->j + 1;
	while (vars->str2[vars->i] != '\0')
		vars->i++;
	vars->j++;
	vars->param2 = ft_strsub(vars->str2, vars->j, vars->i);
	make_line_2(file, vars);
	free(vars);
}
