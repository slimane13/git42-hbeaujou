/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 10:38:43 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/02 14:45:40 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	ft_switch(int *tab)
{
	int tmp;
	
	tmp = tab[0];
	tab[0] = tab[1];
	tab[1] = tmp;
}

void	ft_both_switch(int *tab, int *tab2)
{
	ft_switch(tab);
	ft_switch(tab2);
}

void ft_to_first(int *tab, int *tab2)
{
	ft_avance(tab);
	tab[0] = tab2[0];
	ft_recule(tab2);
}

void	ft_rotate_begin(int *tab)
{
	int tmp;
	int i;

	i = 0;
	tmp = tab[0];
	ft_recule(tab);
	while (tab[i + 1] != 0 && tab[i + 1] != '\0')
		i++;
	tab[i + 1] = tmp;
}

void	ft_both_rotate_begin(int *tab, int *tab2)
{
	ft_rotate_begin(tab);
	ft_rotate_begin(tab2);
}
