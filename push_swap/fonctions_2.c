/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 21:43:35 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 11:55:37 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_rotate_last(int *tab)
{
    int tmp;
    int i;

    i = 0;
    while (tab[i] != 0 && tab[i] != '\0')
        i++;
    i--;
    tmp = tab[i];
    ft_avance(tab);
    tab[0] = tmp;
}

void ft_both_rotate_last(int *tab, int *tab2)
{
    ft_rotate_last(tab);
    ft_rotate_last(tab2);
}

void ft_recule(int *tab)
{
    int i;

    i = 0;
    while(tab[i] != 0 && tab[i] != '\0')
    {
        tab[i] = tab[i + 1];
        i++;
    }
}

void ft_avance(int *tab)
{
    int i;
	int k;

    i = 0;
	k = 0;
    while(tab[i] != 0 && tab[i] != '\0')
        i++;
	k = i;
    tab[i + 1] = tab[i];
    while (i > 0)
    {
        tab[i] = tab[i - 1];
        i--;
    }
	tab[k] = 0;
}
