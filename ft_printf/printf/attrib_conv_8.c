/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:00:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 18:24:27 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int is_ascii_code_point(int val)
{
	return val >= 0x0000 && val <= 0x007F;
}

int utf8encode(char* buf, int codepoint)
{
	int count;
	int offset;
	int i;
	int temp;

	count = 0;
	offset = 0;
	if (is_ascii_code_point(codepoint))
	{
		buf[0] = (char)codepoint;
		return 1;
	}
	if (codepoint >= 0x0080 && codepoint <= 0x07FF)
	{
		count = 1;
		offset = 0xC0;
	}
	else if (codepoint >= 0x0800 && codepoint <= 0xFFFF)
	{
		count = 2;
		offset = 0xE0;
	}
	else if (codepoint >= 0x10000 && codepoint <= 0x10FFFF)
	{
		count = 3;
		offset = 0xF0;
	}
	i = 0;
	buf[i] = (codepoint >> (6 * count)) + offset;
	i++;
	while (count > 0)
	{
		temp = codepoint >> (6 * (count - 1));
		buf[i++] = 0x80 | (temp & 0x3f);
		count--;
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
