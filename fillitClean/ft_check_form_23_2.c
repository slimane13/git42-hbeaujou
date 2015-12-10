/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_23_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:41:53 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:41:59 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check5(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[3] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[2] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check6(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[2] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check7(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[3] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[0] % g_len_mx > 0)
			return (1);
	}
	return (0);
}

int	check8(int *t1)
{
	if (t1[0] / g_len_mx < g_len_mx - 2 &&
			t1[0] % g_len_mx < g_len_mx - 1)
	{
		if (t1[3] / g_len_mx > 1 && t1[3] % g_len_mx > 0)
			return (1);
	}
	return (0);
}
