/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:02:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c_c_p_else(char **str, int count[3])
{
	if (ft_strlen(str[count[0]]) == 2 &&
			ft_islower(str[count[0]][1]) &&
			str[count[0]][0] == ' ')
		str[count[0]][0] = '\0';
	else if (str[count[0]][0] == ' ' &&
			ft_strlen(str[count[0]]) == 2)
		str[count[0]] = ft_strsub(str[count[0]], 1, 2);
}

void	ft_cut_print_else(char **str, int count[3])
{
	if (count[0] == 0 && ft_isallnull(str[count[0]]))
	{
		str[count[0]][0] = '%';
		str[count[0]][1] = '\0';
	}
	else if (ft_strlen(str[count[0]]) == 1 && is_d0)
		attrib_erreur_conv_spec(str, count);
	else if (ft_strlen(str[count[0]]) == 3 && strc0 == '-' && strc1 == '0' &&
			ft_isdigit(str[count[0]][2]))
		attrib_erreur_conv_spec(str, count);
	else if (ft_strlen(str[count[0]]) == 2 &&
			((strc0 == '-' && is_d1) || (strc0 == '0' && is_d1)))
		attrib_erreur_conv_spec(str, count);
	else if (ft_strlen(str[count[0]]) == 4)
		attrib_erreur_conv(str, count);
	else if (ft_strlen(str[count[0]]) == 3 &&
			str[count[0]][2] == '.')
		attrib_erreur_conv(str, count);
	else if (ft_strlen(str[count[0]]) == 3 &&
			ft_isalpha(str[count[0]][ft_strlen(str[count[0]]) - 1])
			== 1)
		attrib_erreur_conv(str, count);
	else
		ft_c_c_p_else(str, count);
}

void	ft_cut_print_p1(t_var **var, char **str, int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'p' &&
			str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
	{
		var[count[2]]->u_long = (unsigned long)va_arg(liste, void *);
		attrib_p(str, var, count);
	}
}

void	ft_cut_print_spec(t_var **var, char **str, int count[3], va_list liste)
{
	if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->u_l_long = va_arg(liste,
				unsigned long long);
		attrib_x_l(str, var, count);
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
	}
	else
	{
		var[count[2]]->u_l_long = va_arg(liste,
				unsigned long long);
		attrib_x_l(str, var, count);
		str[count[0]] = ft_strjoin("0x", str[count[0]]);
	}
}
