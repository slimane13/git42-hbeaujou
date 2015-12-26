/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attrib_conv_8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 15:00:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/21 15:52:14 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	attrib_erreur_conv(char **str, int count[3])
{
	int str_len;
	int flag;
	int k;
	int nbr;
	int nbrlen;
	char c;

	k = 0;
	c = 't';
	str_len = ft_strlen(str[count[0]]);
	flag = check_flag(str, count, &str_len, &c);
	nbrlen = ft_nbrlen(flag);
	if (flag < 0)
		nbrlen++;
	//nbr = ft_atoi(str[count[0]]);
	if (flag < 0)
		nbr = -flag;
	str[count[0]] = ft_strsub(str[count[0]], nbrlen, str_len);
	str_len = str_len - nbrlen;
	if (flag == -1)
		str[count[0]] = ft_strcpy(str[count[0]], "(null)");
	else if (flag != -1 && flag != 1000 && flag != 2000 &&
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
