/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:28:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 11:28:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_init_x_l(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).p = 1;
	(*t_v).diff = 0;
	(*t_v).spec = 0;
	(*t_v).c = 't';
	(*t_v).nbr = ft_nbrlen(var[count[2]]->u_l_long);
	(*t_v).l = ft_atoi_spec_o(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long,
			"0123456789abcdef");
	(*t_v).nbr = ft_strlen(str[count[0]]);
}

void	ft_cut_flag_x1_l(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	if (var[count[2]]->u_l_long != 0)
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
	(*t_v).flag = (*t_v).l;
	if (var[count[2]]->u_l_long == 0)
		(*t_v).spec = 0;
	else
		(*t_v).spec = 1;
	(*t_v).nbr++;
}

void	ft_cut_init_x_lmaj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	(*t_v).k = 0;
	(*t_v).p = 1;
	(*t_v).diff = 0;
	(*t_v).spec = 0;
	(*t_v).c = 't';
	(*t_v).nbr = ft_nbrlen(var[count[2]]->u_l_long);
	(*t_v).l = ft_atoi_spec_o(str[count[0]]);
	(*t_v).c_d = ft_atoi_double(str[count[0]]);
	(*t_v).check = ft_atoi_ultra(str[count[0]]);
	(*t_v).flag = check_flag(str, count, &(*t_v).nbr, &(*t_v).c);
	str[count[0]] = ft_ntoa_base_un(var[count[2]]->u_l_long,
			"0123456789ABCDEF");
	(*t_v).nbr = ft_strlen(str[count[0]]);
}

void	ft_cut_flag_x1_lmaj(t_cut *t_v, t_var **var, char **str, int count[3])
{
	while ((*t_v).k < (*t_v).c_d - (*t_v).nbr)
	{
		str[count[0]] = ft_strjoin("0", str[count[0]]);
		(*t_v).k++;
	}
	if (var[count[2]]->u_l_long != 0)
		str[count[0]] = ft_strjoin("0X", str[count[0]]);
	(*t_v).flag = (*t_v).l;
	if (var[count[2]]->u_l_long == 0)
		(*t_v).spec = 0;
	else
		(*t_v).spec = 1;
	(*t_v).nbr++;
}
