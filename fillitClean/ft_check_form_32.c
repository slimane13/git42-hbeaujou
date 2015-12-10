/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:13:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:40:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 0 && t1[3] % g_len_mx < g_len_mx - 2)
			return (1);
	}
	return (0);
}

int	check2_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 2)
	{
		if (t1[3] / g_len_mx > 0 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check3_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 2)
	{
		if (t1[3] / g_len_mx > 0 && t1[3] % g_len_mx > 1)
			return (1);
	}
	return (0);
}

int	check4_32(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 1 &&
			t1[0] % g_len_mx < g_len_mx - 2)
	{
		if (t1[1] / g_len_mx > 0 && t1[3] % g_len_mx > 1)
			return (1);
	}
	return (0);
}
