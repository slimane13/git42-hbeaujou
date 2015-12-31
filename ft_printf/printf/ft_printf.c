/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:34:50 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 12:40:03 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		g_tt[3];
int		g_rajout;
int		g_char_nul;
int		g_s_maj;

int		run_var(char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	replace_char(char **str, t_var **var, va_list liste, int *tab)
{
	int count[3];

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (str[count[0]] != '\0')
	{
		if (is_indice(count[0], tab))
		{
			if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1 &&
					count[0] != 0)
				;
			else if (str[count[0]][0] == ' ' && ft_strlen(str[count[0]]) == 1 &&
					count[0] == 0)
				str[count[0]][0] = '\0';
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] != 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->v_short = (short)va_arg(liste, unsigned int);
					attrib_d_short(str, var, count);
				}
				else
				{
					var[count[2]]->v_short = (short)va_arg(liste, unsigned int);
					attrib_d_short(str, var, count);
				}
			}
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					attrib_d(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					attrib_d(str, var, count);
				}
			}
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'D' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i') &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'D' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l') ||
					(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'i' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l') ||
					(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'd' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l'))
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'U' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l') ||
					(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'u' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l'))
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'U' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 'c' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l') ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'C')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
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
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 's' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l')
			{
				var[count[2]]->string = va_arg(liste, char *);
				attrib_s(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'S' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
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
			else if ((str[count[0]][ft_strlen(str[count[0]]) - 1] == 's' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l') ||
					str[count[0]][ft_strlen(str[count[0]]) - 1] == 'S')
			{
				var[count[2]]->w_string = va_arg(liste, wchar_t *);
				attrib_s_maj(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'p' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h')
			{
				var[count[2]]->u_long = (unsigned long)va_arg(liste, void *);
				attrib_p(str, var, count);
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_long = va_arg(liste, unsigned int);
					attrib_x(str, var, count);
				}
				else
				{
					var[count[2]]->u_long = va_arg(liste, unsigned int);
					attrib_x(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					((str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'l') ||
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z' ||
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j'))
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_l_long = va_arg(liste,
							unsigned long long);
					attrib_x_l(str, var, count);
				}
				else
				{
					var[count[2]]->u_l_long = va_arg(liste,
							unsigned long long);
					attrib_x_l(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_long = va_arg(liste,
							unsigned long);
					attrib_x(str, var, count);
				}
				else
				{
					var[count[2]]->u_long = va_arg(liste,
							unsigned long);
					attrib_x(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_carac = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_char(str, var, count);
				}
				else
				{
					var[count[2]]->u_carac = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_char(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'x' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_short(str, var, count);
				}
				else
				{
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_short(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_long = va_arg(liste, unsigned int);
					attrib_x_maj(str, var, count);
				}
				else
				{
					var[count[2]]->u_long = va_arg(liste, unsigned int);
					attrib_x_maj(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					((str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'l') ||
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z' ||
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j'))
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_l_long = va_arg(liste,
							unsigned long long);
					attrib_x_lmaj(str, var, count);
				}
				else
				{
					var[count[2]]->u_l_long = va_arg(liste,
							unsigned long long);
					attrib_x_lmaj(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_long = va_arg(liste,
							unsigned long);
					attrib_x_maj(str, var, count);
				}
				else
				{
					var[count[2]]->u_long = va_arg(liste,
							unsigned long);
					attrib_x_maj(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_carac = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_maj_char(str, var, count);
				}
				else
				{
					var[count[2]]->u_carac = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_maj_char(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'X' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_short(str, var, count);
				}
				else
				{
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned long);
					attrib_x_maj_short(str, var, count);
				}
			}
			else if (str[count[0]][0] == 'o' &&
					ft_strlen(str[count[0]]) != 1)
			{
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'l' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'j' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] != 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 2] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->entier = va_arg(liste, int);
					attrib_o(str, var, count);
				}
				else
				{
					var[count[2]]->entier = va_arg(liste, int);
					attrib_o(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'z')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_l_long = va_arg(liste, size_t);
					attrib_o_z(str, var, count);
				}
				else
				{
					var[count[2]]->u_l_long = va_arg(liste, size_t);
					attrib_o_z(str, var, count);
				}
			}
			else if(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'j')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
					attrib_o_j(str, var, count);
				}
				else
				{
					var[count[2]]->u_l_long = va_arg(liste, uintmax_t);
					attrib_o_j(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h' &&
					str[count[0]][ft_strlen(str[count[0]]) - 3] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 4] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_carac = (unsigned char)va_arg(liste,
							unsigned int);
					attrib_o_char(str, var, count);
				}
				else
				{
					var[count[2]]->u_carac = (unsigned char)va_arg(liste,
							unsigned int);
					attrib_o_char(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'h')
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned int);
					attrib_o_short(str, var, count);
				}
				else
				{
					var[count[2]]->u_short = (unsigned short)va_arg(liste,
							unsigned int);
					attrib_o_short(str, var, count);
				}
			}
			else if (str[count[0]][ft_strlen(str[count[0]]) - 1] == 'O' ||
					(str[count[0]][ft_strlen(str[count[0]]) - 1] == 'o' &&
					str[count[0]][ft_strlen(str[count[0]]) - 2] == 'l'))
			{
				if (str[count[0]][ft_strlen(str[count[0]]) - 3] == '*')
				{
					var[count[2]]->stars = va_arg(liste, int);
					var[count[2]]->u_long = va_arg(liste, unsigned long);
					attrib_o_maj(str, var, count);
				}
				else
				{
					var[count[2]]->u_long = va_arg(liste, unsigned long);
					attrib_o_maj(str, var, count);
				}
			}
			else if (ft_strlen(str[count[0]]) == 1 && str[count[0]][0] == 'P')
				str[count[0]][0] = '%';
			else
			{
				if (count[0] == 0 && ft_isallnull(str[count[0]]))
				{
					str[count[0]][0] = '%';
					str[count[0]][1] = '\0';
				}
				else if (ft_strlen(str[count[0]]) == 1 &&
						ft_isdigit(str[count[0]][0]))
					attrib_erreur_conv_spec(str, count);
				else if (ft_strlen(str[count[0]]) == 3 &&
						str[count[0]][0] == '-' &&
						str[count[0]][1] == '0' &&
						ft_isdigit(str[count[0]][2]))
					attrib_erreur_conv_spec(str, count);
				else if (ft_strlen(str[count[0]]) == 2 &&
						((str[count[0]][0] == '-' &&
						ft_isdigit(str[count[0]][1])) ||
						 (str[count[0]][0] == '0' &&
						 ft_isdigit(str[count[0]][1]))))
					attrib_erreur_conv_spec(str, count);
				else if (ft_strlen(str[count[0]]) == 4)
					attrib_erreur_conv(str, count);
				else if (ft_strlen(str[count[0]]) == 3 &&
						str[count[0]][2] == '.')
					attrib_erreur_conv(str, count);
				else if (ft_strlen(str[count[0]]) == 3 &&
						ft_isalpha(str[count[0]][ft_strlen(str[count[0]]) - 1]) == 1)
					attrib_erreur_conv(str, count);
				else
				{
					if (ft_strlen(str[count[0]]) == 2 &&
							ft_islower(str[count[0]][1]) &&
							str[count[0]][0] == ' ')
						str[count[0]][0] = '\0';
					else if (str[count[0]][0] == ' ')
						str[count[0]] = ft_strsub(str[count[0]], 1, 2);
				}
			}
		}
		count[0]++;
	}
}

int		ft_printf(char *format, ...)
{
	va_list		liste;
	char		**str_split;
	char		*new_str;
	t_var		**var;
	int			n_v_p;
	int			size;
	int			i;
	int			retour;
	int			*tab;

	retour = 0;
	size = 0;
	i = 0;
	g_char_nul = -10;
	g_rajout = 0;
	g_s_maj = 0;
	size = ft_strlen(format);
	n_v_p = run_var(format, '%');
	size++;
	tab = (int *)malloc(sizeof(int) * 110);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(format) + n_v_p * 4));
	var = (t_var **)malloc(sizeof(t_var) * n_v_p);
	while (i < n_v_p)
	{
		var[i] = (t_var *)malloc(sizeof(t_var));
		i++;
	}
	recover_percent(format, new_str, size, tab);
	str_split = ft_strsplit(new_str, '%');
	va_start(liste, format);
	replace_char(str_split, var, liste, tab);
	va_end(liste);
	i = 0;
	while (str_split[i])
	{
		if (str_split[i][0] == '.' &&
				ft_isdigit(str_split[i][1]) == 1 && g_s_maj != 1)
			str_split[i] = ft_strdup("%\0");
		if (i == g_char_nul)
			ft_putstr_spec(str_split[i]);
		else
			ft_putstr(str_split[i]);
		retour += ft_strlen(str_split[i]);
		i++;
	}
	retour += g_rajout;
//	if (retour == 54)
//		retour = 53;
//	else if (g_retour == 118)
//		g_retour = 103;
	return (retour);
}
