/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:27:22 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/13 12:06:46 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_flag_one(char *format, char *str, int var[3])
{
	str[var[1]] = '%';
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	str[var[1]] = '%';
}

void	add_flag_two(char *format, char *str, int var[3])
{
	str[var[1]] = '%';
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	var[0]++;
	str[var[1]] = format[var[0]];
	var[1]++;
	str[var[1]] = '%';
}

void	add_flag_three(char *format, char *str, int var[3])
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
	str[var[1]] = '%';
}

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
