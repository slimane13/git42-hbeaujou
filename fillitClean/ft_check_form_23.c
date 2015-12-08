/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_23.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:56:59 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:37:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[0] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[3] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check2(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[0] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[3] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check3(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[2] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[3] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check4(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[3] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[1] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check5(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[3] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[2] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check6(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[2] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[3] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check7(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[3] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[0] % taille_max > 0)
			return (1);
	}
	return (0);
}

int	check8(int *t1)
{
	if (t1[0] / taille_max < taille_max - 2 &&
			t1[0] % taille_max < taille_max - 1)
	{
		if (t1[3] / taille_max > 1 && t1[3] % taille_max > 0)
			return (1);
	}
	return (0);
}
