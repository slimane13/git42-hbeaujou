/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_32_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:40:25 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:42:36 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check5_32(int *t1)
{
	if (t1[0] / g_taille_max < g_taille_max - 1 &&
			t1[0] % g_taille_max < g_taille_max - 1)
	{
		if (t1[3] / g_taille_max > 0 && t1[3] % g_taille_max > 0)
			return (1);
	}
	return (0);
}

int	check6_32(int *t1)
{
	if (t1[0] / g_taille_max < g_taille_max - 1 &&
			t1[0] % g_taille_max > 1)
	{
		if (t1[3] / g_taille_max > 0 && t1[2] % g_taille_max < g_taille_max - 2)
			return (1);
	}
	return (0);
}

int	check7_32(int *t1)
{
	if (t1[0] / g_taille_max < g_taille_max - 1 &&
			t1[0] % g_taille_max < g_taille_max - 1)
	{
		if (t1[3] / g_taille_max > 0 && t1[3] % g_taille_max > 0)
			return (1);
	}
	return (0);
}

int	check8_32(int *t1)
{
	if (t1[0] / g_taille_max < g_taille_max - 1 &&
			t1[0] % g_taille_max < g_taille_max - 2)
	{
		if (t1[3] / g_taille_max > 0 && t1[2] % g_taille_max > 0)
			return (1);
	}
	return (0);
}
