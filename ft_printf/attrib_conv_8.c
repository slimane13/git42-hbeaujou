/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:00:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/29 16:57:08 by hbeaujou         ###   ########.fr       */
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
	if(is_ascii_code_point(codepoint)) {
		buf[0] = (char)codepoint;
		return 1;
	}

	if(codepoint >= 0x0080 && codepoint <= 0x07FF) {
		count = 1;
		offset = 0xC0;
	} else if(codepoint >= 0x0800 && codepoint <= 0xFFFF) {
		count = 2;
		offset = 0xE0;
	} else if(codepoint >= 0x10000 && codepoint <= 0x10FFFF) {
		count = 3;
		offset = 0xF0;
	}

	i = 0;
	buf[i] = (codepoint >> (6 * count)) + offset;
	i++;

	while(count > 0) {
		temp = codepoint >> (6 * (count - 1));
		buf[i++] = 0x80 | (temp & 0x3f);
		count--;
	}

	return i;
}

void	attrib_erreur_conv(char **str, int count[3])
{
	int str_len;
	int flag;
	int k;
	int nbr;
	int check;
	int check_double;
	int p;
	int diff;
	int nbrlen;
	char c;
	char z;
	char last;

	k = 0;
	diff = 0;
	p = 1;
	c = 't';
	z = 'y';
	last = 'u';
	str_len = ft_strlen(str[count[0]]);
	check = ft_atoi(str[count[0]]);
	check_double = ft_atoi_double(str[count[0]]);
	flag = check_flag(str, count, &str_len, &c);
	nbrlen = ft_nbrlen(flag);
	if (flag < 0)
		nbrlen++;
	if (flag < 0)
		nbr = -flag;
	if (str[count[0]][0] == '0')
		z = '0';
	if (ft_strlen(str[count[0]]) == 4)
		last = str[count[0]][3];
	str[count[0]] = ft_strsub(str[count[0]], nbrlen, str_len);
	str_len = str_len - nbrlen;
	if (flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (flag == 3500)
	{
		if (check_double >= str_len)
			diff = check_double;
		else
			diff = str_len;
		k = 1;
		while (k < check - diff)
		{
			if (z == '0')
				str[count[0]] = ft_strjoin("0", str[count[0]]);
			else
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
			k++;
		}
		if (last == 'u')
			str[count[0]] = ft_strjoin(str[count[0]], "%");
		else
			str[count[0]] = ft_charjoin(str[count[0]], last);
	}
	else if (flag != -1 && flag != 1000 && flag != 2000 && flag != 3500 &&
			flag != 3000 && flag != 4000 && flag != 5000)
	{
		if (flag < -1 && c != '0')
		{
			while (k > flag + str_len)
			{
				str[count[0]] = ft_strjoin(str[count[0]], " ");
				k--;
			}
		}
		else if (flag == 0 && c == '.')
			str[count[0]][0] = '\0';
		else if (flag > 0 && c == '.')
		{
			if (flag < 0)
				flag = -flag;
			str[count[0]] = ft_strsub(str[count[0]], 0, flag);
		}
		else
		{
			while (k < flag - str_len)
			{
				str[count[0]] = ft_strjoin(" ", str[count[0]]);
				k++;
			}
		}
	}
	count[2]++;
}
