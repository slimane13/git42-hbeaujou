/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_x_cc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:28:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 17:31:25 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_c_flag_x1(t_cut *t_v, char **str, int count[3], int *b)
{
	str[count[0]] = ft_strjoin("0", str[count[0]]);
	(*t_v).k++;
	*b = 1;
}

void	ft_c_c_flag_x12(t_cut *t_v, char **str, int count[3])
{
	str[count[0]] = ft_strjoin(" ", str[count[0]]);
	(*t_v).k++;
}
