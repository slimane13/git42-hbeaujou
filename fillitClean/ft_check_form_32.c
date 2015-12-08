/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:13:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:20:28 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max - 1)
	{
		if (t1[3]/taille_max > 0 && t1[3]%taille_max < taille_max - 2)
			return (1);
	}
	return (0);
}

int	check2_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max - 2)
	{
		if (t1[3]/taille_max > 0 && t1[3]%taille_max > 0)
			return (1);
	}
	return (0);
}

int	check3_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max - 2)
	{
		if (t1[3]/taille_max > 0 && t1[3]%taille_max > 1)
			return (1);
	}
	return (0);
}

int	check4_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max - 2)
	{
		if (t1[1]/taille_max > 0 && t1[3]%taille_max > 1)
			return (1);
	}
	return (0);
}

int	check5_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max - 1)
	{
		if (t1[3]/taille_max > 0 && t1[3]%taille_max > 0)
			return (1);
	}
	return (0);
}

int	check6_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max > 1)
	{
		if (t1[3]/taille_max > 0 && t1[2]%taille_max < taille_max - 2)
			return (1);
	}
	return (0);
}

int	check7_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max- 1)
	{
		if (t1[3]/taille_max > 0 && t1[3]%taille_max > 0)
			return (1);
	}
	return (0);
}

int	check8_32(int *t1)
{
	if (t1[0]/taille_max < taille_max - 1 && t1[0]%taille_max < taille_max- 2)
	{
		if (t1[3]/taille_max > 0 && t1[2]%taille_max > 0)
			return (1);
	}
	return (0);
}
