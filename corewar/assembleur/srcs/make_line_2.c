/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 15:20:36 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/22 17:36:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	make_line_4(t_function **file, t_tempo *vars)
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
	tmp3 = new_instruct(vars->param4, check_param(vars->param4), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}

void	make_line_5(t_function **file, t_tempo *vars)
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
	tmp3 = new_instruct(vars->param4, check_param(vars->param4), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param5, check_param(vars->param5), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}

void	make_line_6(t_function **file, t_tempo *vars)
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
	tmp3 = new_instruct(vars->param4, check_param(vars->param4), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param5, check_param(vars->param5), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
	tmp3 = new_instruct(vars->param6, check_param(vars->param6), 0);
	ft_lstaddend_instruct(&tmp->lines, tmp3);
}

void	check_space_label(int i, char *str)
{
	if (str[i + 1] == LABEL_CHAR)
	{
		ft_printf("Erreur d'ecriture du label - ligne : %d\n", g_lines_tot);
		exit(0);
	}
}
