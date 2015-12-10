/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_32_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:40:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/10 15:26:32 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check5_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx > 0)
	{
		if (t1[3] / g_len_mx > 0 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check6_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx > 1)
	{
		if (t1[3] / g_len_mx > 0 && t1[2] % g_len_mx < g_len_mx - 2)
			return (1);
	}
	return (0);
}

int	check7_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx > 0)
	{
		if (t1[3] / g_len_mx > 0 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check8_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 2)
	{
		if (t1[3] / g_len_mx > 0 && t1[2] % g_len_mx > 0)
			return (1);
	}
	return (0);
}
