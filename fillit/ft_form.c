/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:14:45 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/27 15:59:11 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	keepForm(int *t1, int *spc, int taille) // spc[0] = largeur - spc[1] = hauteur
{
	printf("ICI LOL");
	printf("\n");
	if (spc[0] == 1)
	{
		printf("%d", t1[0]);
		if (t1[0] >= 0 && t1[0] < taille)
			return (1);
	}
//	else if (spc[0] = 2 && spc[1] == 3)
//	{
//		if (t1[0]%taille >= 0 && t1[0]%taille < taille - 1)
//		{
//			if (t1[3]/taille >= 0 && t1[3]/taille < taille)
//				return (1);
//		}
//	}
	else if (spc[0] == 2 && spc[1] == 2)
	{
		if (t1[0]%taille != taille - 1 && t1[0]/taille != taille - 1)
		{
			if (t1[3]/taille != 0 && t1[3]%taille != taille - 1)
				return (1);
		}
	}
//	else if (spc[0] == 3 && spc[1] == 2)
//	{
//		if (t1[0]%taille >= 0 && t1[0]%taille < taille)
//		{
//			if (t1[3]/taille >= 0 && t1[3]/taille < taille)
//				return (1);
//		}
//	}
	else if (spc[0] == 4)
	{
		if (t1[0]%taille >= 0 && t1[0]%taille < taille - 3)
		{
			if (t1[0]/taille >= 0 && t1[0]/taille < taille)
				return (1);
		}
	} 
	return (0);
}
