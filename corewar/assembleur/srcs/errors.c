/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/26 13:34:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exit_prgm_nbr(char *str, char *str2)
{
	ft_putstr_fd("Fonction : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" | Commande : ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(" | Ligne : ", 2);
	ft_putstr_fd(ft_itoa(g_lines_tot), 2);
	ft_putstr_fd(" | Bad Type\n", 2);
	exit(0);
}

void	exit_prgm_rg_big(char *str, char *str2)
{
	ft_putstr_fd("Fonction : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" | Commande : ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(" | Ligne : ", 2);
	ft_putstr_fd(ft_itoa(g_lines_tot), 2);
	ft_putstr_fd(" | Wrong registre\n", 2);
	exit(0);
}

void	exit_prgm_type_rg(char *str, char *str2)
{
	ft_putstr_fd("Fonction : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" | Commande : ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(" | Ligne : ", 2);
	ft_putstr_fd(ft_itoa(g_lines_tot), 2);
	ft_putstr_fd(" | Bad Type\n", 2);
	exit(0);
}

void	exit_prgm_type_ind(char *str, char *str2)
{
	ft_putstr_fd("Fonction : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" | Commande : ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(" | Ligne : ", 2);
	ft_putstr_fd(ft_itoa(g_lines_tot), 2);
	ft_putstr_fd(" | Bad Type\n", 2);
	exit(0);
}

void	exit_prgm_type_dir_l(char *str, char *str2)
{
	ft_putstr_fd("Fonction : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(" | Commande : ", 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(" | Ligne : ", 2);
	ft_putstr_fd(ft_itoa(g_lines_tot), 2);
	ft_putstr_fd(" | Bad Type\n", 2);
	exit(0);
}
