/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:21:38 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 19:28:27 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cut_flag_number(char **str, int count[3], int *flag, char *c)
{
	*c = '.';
	if (ft_isalpha(str[count[0]][1]) != 0)
		return (0);
	*flag = ft_atoi_spec(str[count[0]]);
	return (*flag);
}

int	cut_flag_number_2(char **str, int count[3], int *flag, char *c)
{
	str[count[0]][0] = '0';
	if (*c == 'h')
		*flag = ft_atoi_length(str[count[0]]);
	else
		*flag = ft_atoi_spec(str[count[0]]);
	*c = '.';
	return (*flag);
}
