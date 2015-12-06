/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form_23.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:56:59 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/04 15:46:54 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check1(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[0]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check2(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[1]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check3(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[2]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check4(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[3]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[1]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check5(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[3]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[2]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check6(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[2]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check7(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[3]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[0]%tailleMax > 0)
			return (1);
	}
	return (0);
}

int	check8(int *t1)
{
	if (t1[0]/tailleMax < tailleMax - 2 && t1[0]%tailleMax < tailleMax - 1)
	{
		if (t1[3]/tailleMax > 1 && t1[3]%tailleMax > 0)
			return (1);
	}
	return (0);
}
