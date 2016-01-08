/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_erreur2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 16:39:59 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 16:42:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_c_f_erreur2(t_cut *t_v, char **str, int count[3])
{
	(*t_v).k = 0;
	while ((*t_v).k < (*t_v).check - (*t_v).str_len)
	{
		str[count[0]] = ft_strjoin(" ", str[count[0]]);
		(*t_v).k++;
	}
}
