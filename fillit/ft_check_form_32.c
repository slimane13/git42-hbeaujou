/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_32.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 15:13:14 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/04 15:48:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax - 2)
	{
		if (t1[3]/tailleMax > 0 && t1[3]%tailleMax < tailleMax - 2)
			return (1);
	}
	return (0);
}

int	check2_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax - 2)
	{
		if (t1[3]/tailleMax > 0 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check3_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax - 2)
	{
		if (t1[3]/tailleMax > 0 && t1[3]%tailleMax > 1)
			return (1);
	}
	return (0);
}

int	check4_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax - 2)
	{
		if (t1[1]/tailleMax > 0 && t1[3]%tailleMax > 1)
			return (1);
	}
	return (0);
}

int	check5_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 0 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check6_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < 1)
	{
		if (t1[3]/tailleMax > 0 && t1[2]%tailleMax < tailleMax - 2)
			return (1);
	}
	return (0);
}

int	check7_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax- 1)
	{
		if (t1[3]/tailleMax > 0 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check8_32(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 1 && t1[0]%tailleMax < tailleMax- 2)
	{
		if (t1[3]/tailleMax > 0 && t1[2]%tailleMax > 0)
			return (1);
	}
	return (0);
}
