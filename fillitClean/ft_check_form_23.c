/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_23.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:56:59 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:40:49 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[0] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check2(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[0] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check3(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[2] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check4(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[3] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[1] % g_len_mx > 0)
			return (1);
	}
	return (0);
}
