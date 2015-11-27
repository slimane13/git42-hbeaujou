/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:26:23 by hbeaujou          #+#    #+#             */
/*   Updated: 2015/11/27 15:47:39 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//char	*tab_int_to_char(int *tab)
//{
//}

int		*tab_char_to_int(char *str)
{
	int	i;
	int	*tab;

	i = 0;
	tab = malloc(sizeof(int) * 16);
	while (str[i] != '\0')
	{
		tab[i] = atoi(&str[i]);
		i++;
	}
	return (tab);
}

int		overlap(int *t1, int *t2)
{
	if (t1[0] == t2[0] || t1[0] == t2[1] || t1[0] == t2[2] || t1[0] == t2[3] ||
			t1[1] == t2[0] || t1[1] == t2[1] || t1[1] == t2[2] || t1[1] == t2[3] ||
			t1[2] == t2[0] || t1[2] == t2[1] || t1[2] == t2[2] || t1[2] == t2[3] ||
			t1[3] == t2[0] || t1[3] == t2[1] || t1[3] == t2[2] || t1[3] == t2[3])
		return (1);
	return (0);
}

int		isValid(int *t1, int taille, int *spc)
{
/*	if (((t1[0]%taille > 3 || t1[0]/taille > 3) ||
			(t1[1]%taille > 3 || t1[1]/taille > 3) ||
			(t1[2]%taille > 3 || t1[2]/taille > 3) ||
			(t1[3]%taille > 3 || t1[3]/taille > 3)) && keepForm(t1, spc, taille) == 0) */
	if (keepForm(t1, spc, taille) == 0)
		return (0);
	return (1);
}

void	assignSpot(int *tab)
{
	tab[0] = tab[0] + 1;
	tab[1] = tab[1] + 1;
	tab[2] = tab[2] + 1;
	tab[3] = tab[3] + 1;
}

int		*try_tetris_test(int *t1, int *t2, int taille)
{
	int i;
	int	*final;
	int j;
	int *spc;

	final = (int *)malloc(sizeof(int) * (taille * taille));
	spc = (int *)malloc(sizeof(int) * 2);
	spc[0] = 2;
	spc[1] = 2;
	i = 0;
	j = 0;
	while (!isValid(t1, taille, spc) || overlap(t1, t2))
		assignSpot(t1);
	while (j < taille * taille)
	{
		if (j == t1[0] || j == t1[1] || j == t1[2] || j == t1[3])
			final[j] = 1;
		else if (j == t2[0] || j == t2[1] || j == t2[2] || j == t2[3])
			final[j] = 2;
		else
			final[j] = 0;
		j++;
	}
	printf("dans try %d", t1[0]%taille);
	printf("\n");
	printf("dans try / %d", t1[0]/taille);
	printf("\n");
	printf("\n");
	printf("dans try 1 %d", t1[1]%taille);
	printf("\n");
	printf("dans try 1 / %d", t1[1]/taille);
	printf("\n");
	printf("\n");
	printf("dans try 2 %d", t1[2]%taille);
	printf("\n");
	printf("dans try 2 / %d", t1[2]/taille);
	printf("\n");
	printf("\n");
	printf("dans try 3 %d", t1[3]%taille);
	printf("\n");
	printf("dans try 3 / %d", t1[3]/taille);
	printf("\n");
	printf("\n");
	return (final);
}
