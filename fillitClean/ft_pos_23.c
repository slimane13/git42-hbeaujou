/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_23.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:46:07 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 17:18:41 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	first_half_23(int pos, int *t1)
{
	if (pos == 1)
	{
		if (check1(t1) == 1)
			return (1);
	}
	else if (pos == 2)
	{
		if (check2(t1) == 1)
			return (1);
	}
	else if (pos == 3)
	{
		if (check3(t1) == 1)
			return (1);
	}
	else if (pos == 4)
	{
		if (check4(t1) == 1)
			return (1);
	}
	return (0);
}

int	second_half_23(int pos, int *t1)
{
	if (pos == 5)
	{
		if (check5(t1) == 1)
			return (1);
	}
	else if (pos == 6)
	{
		if (check6(t1) == 1)
			return (1);
	}
	else if (pos == 7)
	{
		if (check7(t1) == 1)
			return (1);
	}
	else if (pos == 8)
	{
		if (check8(t1) == 1)
			return (1);
	}
	return (0);
}

int	check_pos_23(int pos, int *t1)
{
	if (pos < 5)
		return (first_half_23(pos, t1));
	else
		return (second_half_23(pos, t1));
	return (0);
}
