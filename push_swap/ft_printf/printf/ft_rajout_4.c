/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:51:02 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/31 12:34:12 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cut_flag_check4(int *nbr)
{
	*nbr = *nbr + 1;
	return (1000);
}

int		cut_flag_check5(int *nbr)
{
	*nbr = *nbr + 1;
	return (1500);
}

int		cut_flag_check6(int *nbr)
{
	*nbr = *nbr + 1;
	return (3000);
}

int		cut_flag_check7(int *nbr, char *c, char **str, int count[3])
{
	if (str[count[0]][1] == '.')
		*c = '.';
	*nbr = *nbr + 1;
	return (5000);
}

void	attrib_erreur_conv_spec(char **str, int count[3])
{
	int i;
	int flagi;
	int c;

	if (str[count[0]][0] == '0')
		c = '0';
	flagi = ft_atoi(str[count[0]]);
	i = 0;
	str[count[0]][0] = '%';
	str[count[0]][1] = '\0';
	while (i < flagi - 1)
	{
		if (c == '0')
			str[count[0]] = ft_strjoin("0", str[count[0]]);
		else
			str[count[0]] = ft_strjoin(" ", str[count[0]]);
		i++;
	}
	while (i > flagi + 1)
	{
		str[count[0]] = ft_strjoin(str[count[0]], " ");
		i--;
	}
}
