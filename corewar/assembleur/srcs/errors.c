/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 14:26:46 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/21 15:20:40 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	exit_prgm_nbr(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_rg_big(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_type_rg(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_type_ind(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}

void	exit_prgm_type_dir_l(char *str, char *str2)
{
	ft_printf("Fonction : %s | Commande : %s | Ligne : %d\n",
			str, str2, g_lines_tot);
	exit(0);
}
