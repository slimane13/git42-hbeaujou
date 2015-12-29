/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_u2_maj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:56:01 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 16:00:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_cut_flag_u3_1maj(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k > (*t_v).flag + (*t_v).s_nbr + (*t_v).neg)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		(*t_v).k--;
	}
}

void    ft_cut_flag_u3_2maj(t_cut *t_v, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).flag - (*t_v).s_nbr - (*t_v).neg)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
}
