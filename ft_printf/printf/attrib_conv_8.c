/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:00:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 11:29:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_ascii_code_point(int val)
{
	return (val >= 0x0000 && val <= 0x007F);
}

int		utf8encode(char *buf, int codepoint)
{
	int count;
	int offset;
	int i;
	int temp;

	count = 0;
	offset = 0;
	if (is_ascii_code_point(codepoint))
		return (cut_utf8_1(buf, codepoint));
	if (codepoint >= 0x0080 && codepoint <= 0x07FF)
		cut_utf8_2(&count, &offset);
	else if (codepoint >= 0x0800 && codepoint <= 0xFFFF)
		cut_utf8_3(&count, &offset);
	else if (codepoint >= 0x10000 && codepoint <= 0x10FFFF)
		cut_utf8_4(&count, &offset);
	i = 0;
	buf[i] = (codepoint >> (6 * count)) + offset;
	i++;
	count++;
	while (--count > 0)
	{
		temp = codepoint >> (6 * (count - 1));
		buf[i++] = 0x80 | (temp & 0x3f);
	}
	return (i);
}

void	attrib_erreur_conv(char **str, int count[3])
{
	t_cut t_v;

	ft_cut_init_erreur(&t_v, str, count);
	if (t_v.flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (t_v.flag == 3500)
		ft_cut_flag_erreur1(&t_v, str, count);
	else if (t_v.flag != -1 && t_v.flag != 1000 && t_v.flag != 2000 &&
			t_v.flag != 3500 && t_v.flag != 3000 &&
			t_v.flag != 4000 && t_v.flag != 5000)
		ft_cut_flag_erreur2(&t_v, str, count);
	count[2]++;
}

void	attrib_x_lmaj(char **str, t_var **var, int count[3])
{
	t_cut t_v;

	ft_cut_init_x_lmaj(&t_v, var, str, count);
	if (t_v.flag == 5000)
		ft_cut_flag_x1_lmaj(&t_v, var, str, count);
	else if (t_v.flag == 3000)
		ft_cut_flag_x2(&t_v, var, str, count);
	else if (t_v.flag == 3500)
		ft_cut_flag_x3(&t_v, var, str, count);
	if (t_v.flag != 0 && t_v.flag != -1 && t_v.flag != 1000 &&
			t_v.flag != 2000 && t_v.flag != 3500 &&
			t_v.flag != 3000 && t_v.flag != 5000 && t_v.spec == 0)
		ft_cut_flag_x4(&t_v, str, count);
	else if (t_v.flag == 0 && t_v.c == '.' && t_v.spec == 0)
		str[count[0]][0] = '\0';
	count[2]++;
}
