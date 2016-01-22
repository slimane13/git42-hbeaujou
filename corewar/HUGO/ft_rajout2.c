/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:15:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 15:38:53 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_line_3_param(t_function **file, char *line, int test)
{
	t_tempo		*vars;

	vars = (t_tempo *)malloc(sizeof(t_tempo));
	vars->j = 0;
	vars->i = 0;
	g_nb_line++;
	vars->str2 = ft_strtrim(line);
	vars->str2 = deblank(vars->str2);
	vars->str2 = rem_com_if(vars->str2);
	cut_param_3(&vars, test);
	make_line_3(file, vars);
	free(vars);
}

void	exit_prgm_type_dir_n(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_lab_in(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_fk_dir(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	ft_lstaddend_funct(t_function **alst, t_function *new_r)
{
	t_function	*tmp;

	tmp = *alst;
	if (!tmp)
		*alst = new_r;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_r;
		new_r->prev = tmp;
	}
}
