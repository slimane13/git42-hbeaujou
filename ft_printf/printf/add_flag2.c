/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 18:46:19 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/30 18:46:26 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag_four(char *format, char *str, int var[3])
{
	str[var[1]] = '%';
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	str[var[1]] = '%';
}

void	add_flag_five(char *format, char *str, int var[3])
{
	str[var[1]] = '%';
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	str[var[1]] = '%';
}

void	add_flag_six(char *format, char *str, int var[3])
{
	str[var[1]] = '%';
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	str[var[1]] = '%';
}
