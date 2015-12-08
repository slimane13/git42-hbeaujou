/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:14:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/08 13:20:10 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	checkForm23(int esp[5])
{
	if (esp[0] == 1)
	{
		if (esp[3] == taille_max + 1)
			return (1);
		else if (esp[3] == taille_max)
			return (4);
	}
	else if (esp[1] == 1)
	{
		if (esp[3] == taille_max)
		{
			if (esp[4] == 2 * taille_max - 1)
				return (7);
			else
				return (2);
		}
		else if (esp[3] == taille_max + 1)
		{
			if (esp[4] == 2 * taille_max + 1)
				return (8);
			else
				return (5);
		}
	}
	else if (esp[2] == 1)
	{
		if (esp[3] == 2 * taille_max - 1)
			return (3);
		else if (esp[3] == 2 * taille_max)
			return (6);
	}
	return (0);
}

int checkForm32(int esp[5])
{
	if (esp[0] == 1)
	{
		if (esp[1] == taille_max)
			return (8);
		else if (esp[1] == taille_max - 2)
			return (7);
		else if (esp[4] == taille_max + 1)
			return (2);
		else if (esp[4] == taille_max)
			return (1);
		else if (esp[4] == taille_max + 2)
			return (3);
	}
	else if (esp[0] == taille_max)
		return (4);
	else if (esp[0] == taille_max - 1)
		return (5);
	else if (esp[0] == taille_max - 2)
		return (6);
	return (0);
}

int	keepForm(int *t1, int *spc, int taille)
{
	int esp[5];
	int pos;

	esp[0] = t1[1] - t1[0];
	esp[1] = t1[2] - t1[1];
	esp[2] = t1[3] - t1[2];
	esp[3] = t1[2] - t1[0];
	esp[4] = t1[3] - t1[0];
	if (spc[0] == 1)
	{
		if (t1[0]/taille <= taille - 4)
			return (1);
	}
	else if (spc[0] == 2 && spc[1] == 3)
	{
		pos = checkForm23(esp);
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
		else if (pos == 5)
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
	}
	else if (spc[0] == 2 && spc[1] == 2)
	{
		if (t1[0]%taille < taille - 1 && t1[0]/taille < taille - 1)
		{
			if (t1[3]/taille > 0 && t1[3]%taille > 0)
				return (1);
		}
	}
	else if (spc[0] == 3 && spc[1] == 2)
	{
		pos = checkForm32(esp);
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
		else if (pos == 5)
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
	}
	else if (spc[0] == 4)
	{
		if (t1[0]%taille == 0)
			return (1);
	} 
	return (0);
}
