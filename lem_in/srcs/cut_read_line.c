/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_read_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:49:21 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 16:55:36 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	cut_read_1(void)
{
	g_after_start = 1;
	return (3);
}

int	cut_read_2(void)
{
	g_after_end = 1;
	return (4);
}

int	cut_read_3(void)
{
	if (g_begin_attrib_map == 1)
		return (0);
	g_begin_tunnel = 1;
	return (5);
}

int	cut_read_4(void)
{
	g_begin_attrib_map = 1;
	if (g_begin_tunnel == 0)
		return (0);
	return (6);
}

int	cut_read_5(void)
{
	if (g_catch_lem == 1)
		return (0);
	g_catch_lem = 1;
	return (1);
}
