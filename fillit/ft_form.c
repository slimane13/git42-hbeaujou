/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:14:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/12/03 14:03:02 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	keepForm(int *t1, int *spc, int taille) // spc[0] = largeur - spc[1] = hauteur
{
	int esp1;
	int esp2;
	int esp3;

	esp1 = t1[1] - t1[0];
	esp2 = t1[2] - t1[1];
	esp3 = t1[3] - t1[2];
	if (spc[0] == 1)
	{
		if (t1[0]/taille <= taille - 4)
			return (1);
	}
	else if (spc[0] == 2 && spc[1] == 3)
	{
/*		if (pos == 1)
			if (check1(t1) == 1)
				return (1);
		else if (pos == 2)
			if (check2(t1) == 1)
				return (1);
		else if (pos == 3)
			if (check3(t1) == 1)
				return (1);
		else if (pos == 4)
			if (check4(t1) == 1)
				return (1);
		else if (pos == 5)
			if (check5(t1) == 1)
				return (1);
		else if (pos == 6)
			if (check6(t1) == 1)*/
		if (t1[3]/taille > 1)
		{
			if (t1[3]%taille < taille - 1 && t1[3]%taille > 0)
				return (1);
		}
	}
	else if (spc[0] == 2 && spc[1] == 2)
	{
		if (t1[0]%taille != taille - 1 && t1[0]/taille < taille - 1)
		{
			if (t1[3]/taille != 0 && t1[3]%taille < taille && t1[3]%taille != 0 )
				return (1);
		}
	}
	else if (spc[0] == 3 && spc[1] == 2)
	{
		if (t1[0]%taille >= 0 && t1[0]%taille < taille - 2)
		{
			if (t1[3]/taille >= 0 && t1[3]/taille < taille)
				return (1);
		}
	}
	else if (spc[0] == 4)
	{
		if (t1[0]%taille < taille - 4)
			return (1);
	} 
	return (0);
}
