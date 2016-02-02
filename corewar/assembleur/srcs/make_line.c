/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 14:21:34 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/26 13:47:11 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		check_what_is(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	j = i;
	while (str[j] != ' ' && str[j] != '\t')
		j++;
	str2 = ft_strsub(str, i, j - i);
	i = 0;
	while (g_op_tab[i].nb_params != 0 && ft_strcmp(g_op_tab[i].name, str2) != 0)
		i++;
	if (g_op_tab[i].nb_params == 0)
	{
		ft_printf("%s : Function unknown\n", str2);
		exit(0);
	}
	return (i + 1);
}

int		check_param(char *str)
{
	if (str[0] == 'r')
		return (REG);
	else if (str[0] == '%')
		return (DIRE);
	else
		return (INDIR);
}

void	make_line_1(t_function **file, t_tempo *vars)
{
	t_function	*tmp;
	t_line		*tmp2;
	t_instruct	*tmp3;

	tmp = *file;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = new_line(g_nb_line);
	ft_lstaddend_line(&tmp->lines, tmp2);
	tmp3 = new_instruct(vars->name, LABEL, recup_opcode(vars->name));
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param1, check_param(vars->param1), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}

void	make_line_2(t_function **file, t_tempo *vars)
{
	t_function	*tmp;
	t_line		*tmp2;
	t_instruct	*tmp3;

	tmp = *file;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = new_line(g_nb_line);
	ft_lstaddend_line(&tmp->lines, tmp2);
	tmp3 = new_instruct(vars->name, LABEL, recup_opcode(vars->name));
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param1, check_param(vars->param1), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param2, check_param(vars->param2), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}

void	make_line_3(t_function **file, t_tempo *vars)
{
	t_function	*tmp;
	t_line		*tmp2;
	t_instruct	*tmp3;

	tmp = *file;
	while (tmp->next)
		tmp = tmp->next;
	tmp2 = new_line(g_nb_line);
	ft_lstaddend_line(&tmp->lines, tmp2);
	tmp3 = new_instruct(vars->name, LABEL, recup_opcode(vars->name));
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param1, check_param(vars->param1), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param2, check_param(vars->param2), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param3, check_param(vars->param3), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}
