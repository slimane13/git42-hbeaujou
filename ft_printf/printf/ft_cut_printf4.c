/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 19:53:29 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:53:30 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_print_x1(t_var **var, char **str, int count[3], va_list liste)
{
	if (cl1 == 'x' && cl2 != 'h' && cl2 != 'l' && cl2 != 'j' && cl2 != 'z')
		ft_cut_entiertx3_n(str, var, count, liste);
	else if (cl1 == 'x' && ((cl2 == 'l' && cl3 == 'l') || cl2 == 'z' ||
			cl2 == 'j'))
		ft_cut_entiertx3_ull(str, var, count, liste);
	else if (cl1 == 'x' && cl2 == 'l')
		ft_cut_entiertx3_ul(str, var, count, liste);
	else if (cl1 == 'x' && cl2 == 'h' && cl3 == 'h')
		ft_cut_entiertx3_char(str, var, count, liste);
	else if (cl1 == 'x' && cl2 == 'h')
		ft_cut_entiertx3_short(str, var, count, liste);
	else if (cl1 == 'X' && cl2 != 'h' && cl2 != 'l' && cl2 != 'j' && cl2 != 'z')
		ft_cut_entiertx3_majl(str, var, count, liste);
	else if (cl1 == 'X' && ((cl2 == 'l' && cl3 == 'l') || cl2 == 'z' ||
				cl2 == 'j'))
		ft_cut_entiertx3_majull(str, var, count, liste);
	else if (cl1 == 'X' && cl2 == 'l')
		ft_cut_entiertx3_majul(str, var, count, liste);
	else if (cl1 == 'X' && cl2 == 'h' && cl3 == 'h')
		ft_cut_entiertx3_mchar(str, var, count, liste);
	else if (cl1 == 'X' && cl2 == 'h')
		ft_cut_entiertx3_mshort(str, var, count, liste);
}
