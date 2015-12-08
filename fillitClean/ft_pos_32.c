/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:44:27 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 17:28:27 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	first_half_32(int pos, int *t1)
{
	if (pos == 1)
	{
		if (check1_32(t1) == 1)
			return (1);
	}
	else if (pos == 2)
	{
		if (check2_32(t1) == 1)
			return (1);
	}
	else if (pos == 3)
	{
		if (check3_32(t1) == 1)
			return (1);
	}
	else if (pos == 4)
	{
		if (check4_32(t1) == 1)
			return (1);
	}
	return (0);
}

int	second_half_32(int pos, int *t1)
{
	if (pos == 5)
	{
		if (check5_32(t1) == 1)
			return (1);
	}
	else if (pos == 6)
	{
		if (check6_32(t1) == 1)
			return (1);
	}
	else if (pos == 7)
	{
		if (check7_32(t1) == 1)
			return (1);
	}
	else if (pos == 8)
	{
		if (check8_32(t1) == 1)
			return (1);
	}
	return (0);
}

int	check_pos_32(int pos, int *t1)
{
	if (pos < 5)
		return (first_half_32(pos, t1));
	else
		return (second_half_32(pos, t1));
	return (0);
}
