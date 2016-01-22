/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:07:51 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 16:15:15 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	cut_check_p1(char *str, char *str2, int *tab, int i)
{
	if (is_number(str) == 1 && the_number(str) <= REG_NUMBER)
	{
		if (is_in_tab(T_REG, tab, i))
			;
		else
			exit_prgm_type_rg(str2, str);
	}
	else
		exit_prgm_rg_big(str2, str);
}

void	cut_cut_p2(char *str, char *str2, int *tab, int i)
{
	if (is_label_char(ft_strsub(str, 2, ft_strlen(str) - 3)) == 1)
	{
		if (is_in_tab(T_DIR, tab, i))
			;
		else
			exit_prgm_type_dir_l(str2, str);
	}
	else
		exit_prgm_lab_in(str2, str);
}

void	cut_check_p2(char *str, char *str2, int *tab, int i)
{
	if (str[1] == LABEL_CHAR)
		cut_cut_p2(str, str2, tab, i);
	else
	{
		if (str[1] == '-')
			;
		else if (is_number(str) == 1)
		{
			if (is_in_tab(T_DIR, tab, i))
				;
			else
				exit_prgm_type_dir_n(str2, str);
		}
		else
			exit_prgm_fk_dir(str2, str);
	}
}

void	cut_check_p3(char *str, char *str2, int *tab, int i)
{
	if (is_number(str) == 1)
	{
		if (is_in_tab(T_IND, tab, i))
			;
		else
			exit_prgm_type_ind(str2, str);
	}
	else if (str[0] == LABEL_CHAR)
		if (is_in_tab(T_IND, tab, i))
			;
		else
			exit_prgm_type_ind(str2, str);
	else
		exit_prgm_nbr(str2, str);
}
