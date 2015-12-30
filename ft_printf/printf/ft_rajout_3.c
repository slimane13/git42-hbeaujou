/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 19:32:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 19:40:01 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cut_utf8_1(char *buf, int code)
{
	buf[0] = (char)code;
	return (1);
}

void	cut_utf8_2(int *count, int *offset)
{
	*count = 1;
	*offset = 0xC0;
}

void	cut_utf8_3(int *count, int *offset)
{
	*count = 2;
	*offset = 0xE0;
}

void	cut_utf8_4(int *count, int *offset)
{
	*count = 3;
	*offset = 0xF0;
}
