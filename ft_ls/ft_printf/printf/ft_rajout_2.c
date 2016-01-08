/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:21:38 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 19:50:46 by hbeaujou         ###   ########.fr       */
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

int	cut_flag_check(char **str, int count[3], int *nbr)
{
	if (str[count[0]][0] == ' ' && str[count[0]][1] == '0')
	{
		*nbr = *nbr + 1;
		return (2500);
	}
	else if (str[count[0]][0] == ' ' && str[count[0]][1] != '+')
	{
		*nbr = *nbr + 1;
		return (2000);
	}
	return (-1);
}

int	cut_flag_check2(int *nbr)
{
	*nbr = *nbr + 1;
	return (4000);
}

int	cut_flag_check3(int *nbr)
{
	*nbr = *nbr + 1;
	return (4500);
}
