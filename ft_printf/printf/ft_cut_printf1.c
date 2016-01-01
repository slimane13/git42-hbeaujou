/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_printf1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:33:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/01 19:30:23 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_print_d1(t_var **var, char **str, int count[3], va_list liste)
{
	if ((cl1 == 'd' || cl1 == 'i') && cl2 == 'h' && cl3 == 'j')
		ft_cut_entiertd3_ll(str, var, count, liste);
	else if ((cl1 == 'd' || cl1 == 'i') && cl2 == 'h' && cl3 != 'h' &&
			cl3 != 'z')
		ft_cut_entiertd3_short(str, var, count, liste);
	else if ((cl1 == 'd' || cl1 == 'i') && cl2 != 'h' && cl2 != 'l' &&
			cl2 != 'j' && cl2 != 'z')
		ft_cut_entiertd3_int(str, var, count, liste);
	else if ((cl1 == 'd' || cl1 == 'i') && cl2 == 'h' && cl3 == 'h')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->carac = (char)va_arg(liste, int);
			attrib_d_char(str, var, count);
		}
		else
		{
			var[count[2]]->carac = (char)va_arg(liste, int);
			attrib_d_char(str, var, count);
		}
	}
	else if ((cl1 == 'd' || cl1 == 'i') && ((cl2 == 'z') || (cl2 == 'h' &&
					cl3 == 'z')))
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->v_l_long = va_arg(liste, size_t);
			attrib_d_z(str, var, count);
		}
		else
		{
			var[count[2]]->v_l_long = va_arg(liste, size_t);
			attrib_d_z(str, var, count);
		}
	}
	else if (cl1 == 'D' && cl2 == 'l')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
			attrib_d_ll(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
			attrib_d_ll(str, var, count);
		}
	}
	else if ((cl1 == 'd' || cl1 == 'i') && cl2 == 'j')
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
			attrib_d_j(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
			attrib_d_j(str, var, count);
		}
	}
	else if ((cl1 == 'D' && cl2 != 'l') || (cl1 == 'i' && cl2 == 'l') ||
			(cl1 == 'd' && cl2 == 'l'))
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->v_long = va_arg(liste, long);
			attrib_d_maj(str, var, count);
		}
		else
		{
			var[count[2]]->v_long = va_arg(liste, long);
			attrib_d_maj(str, var, count);
		}
	}
}

void	ft_cut_print_u1(t_var **var, char **str, int count[3], va_list liste)
{
	if (cl1 == 'u' && cl2 != 'h' && cl2 != 'j' && cl2 != 'l' && cl2 != 'z')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
			attrib_u(str, var, count);
		}
		else
		{
			var[count[2]]->u_entier = (unsigned int)va_arg(liste, int);
			attrib_u(str, var, count);
		}
	}
	else if (cl1 == 'u' && cl2 == 'z')
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste, size_t);
			attrib_u_z(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste, size_t);
			attrib_u_z(str, var, count);
		}
	}
	else if (cl1 == 'u' && cl2 == 'j')
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
			attrib_u_j(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
			attrib_u_j(str, var, count);
		}
	}
	else if (cl1 == 'u' && cl2 == 'h' && cl3 == 'h')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_carac = (unsigned char)va_arg(liste,
					unsigned int);
			attrib_u_char(str, var, count);
		}
		else
		{
			var[count[2]]->u_carac = (unsigned char)va_arg(liste,
					unsigned int);
			attrib_u_char(str, var, count);
		}
	}
	else if (cl1 == 'u' && cl2 == 'h')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned int);
			attrib_u_short(str, var, count);
		}
		else
		{
			var[count[2]]->u_short = (unsigned short)va_arg(liste,
					unsigned int);
			attrib_u_short(str, var, count);
		}
	}
	else if ((cl1 == 'U' && cl2 != 'l') || (cl1 == 'u' && cl2 == 'l'))
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_long = va_arg(liste, unsigned long);
			attrib_u_maj(str, var, count);
		}
		else
		{
			var[count[2]]->u_long = va_arg(liste, unsigned long);
			attrib_u_maj(str, var, count);
		}
	}
	else if (cl1 == 'U' && cl2 == 'l')
	{
		if (cl2 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
			attrib_u_ll(str, var, count);
		}
		else
		{
			var[count[2]]->u_l_long = va_arg(liste, unsigned long long);
			attrib_u_ll(str, var, count);
		}
	}
}

void	ft_c_c_p_c1(t_var **var, char **str, int count[3], va_list liste)
{
	if (cl2 == '*')
	{
		var[count[2]]->stars = va_arg(liste, int);
		var[count[2]]->string = ft_itoa(va_arg(liste, int));
		attrib_c(str, var, count);
	}
	else
	{
		var[count[2]]->string = ft_itoa(va_arg(liste, int));
		attrib_c(str, var, count);
	}
}

void	ft_cut_print_c1(t_var **var, char **str, int count[3], va_list liste)
{
	if (cl1 == 'c' && cl2 != 'h' && cl2 != 'l')
		ft_c_c_p_c1(var, str, count, liste);
	else if ((cl1 == 'c' && cl2 == 'l') || cl1 == 'C')
	{
		if (cl3 == '*')
		{
			var[count[2]]->stars = va_arg(liste, int);
			var[count[2]]->w_entier = va_arg(liste, wint_t);
			attrib_c_maj(str, var, count);
		}
		else
		{
			var[count[2]]->w_entier = va_arg(liste, wint_t);
			attrib_c_maj(str, var, count);
		}
	}
}

void	ft_cut_print_s1(t_var **var, char **str, int count[3], va_list liste)
{
	if (cl1 == 's' && cl2 != 'h' && cl2 != 'l')
	{
		var[count[2]]->string = va_arg(liste, char *);
		attrib_s(str, var, count);
	}
	else if (cl1 == 'S' && cl2 == 'h' && cl3 == 'h')
	{
		var[count[2]]->w_string = va_arg(liste, wchar_t *);
		if (var[count[2]]->w_string == NULL)
		{
			var[count[2]]->string = "(null)";
			attrib_s(str, var, count);
		}
		else
			attrib_s_maj(str, var, count);
	}
	else if ((cl1 == 's' && cl2 == 'l') || cl1 == 'S')
	{
		var[count[2]]->w_string = va_arg(liste, wchar_t *);
		attrib_s_maj(str, var, count);
	}
}
