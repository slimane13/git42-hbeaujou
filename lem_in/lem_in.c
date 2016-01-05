/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 11:55:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	*map;
	t_map	*tmp;
	int		n;

	n = 1;
	read_map(&map);
	///////////////////////// DEBUT DU CODE DE TEST ////////////////////////
	tmp = map;
	while (tmp->next)
	{
		ft_putstr("nom du ");
		ft_putnbr(n);
		ft_putstr("eme element : ");
		ft_putstr(tmp->room->name);
		if (tmp->room->start == 1)
			ft_putstr(" et c'est le depart\n");
		else if (tmp->room->end == 1)
			ft_putstr(" et c'est l'arrivee\n");
		else
			ft_putchar('\n');
		tmp = tmp->next;
		n++;
	}
	ft_putstr("nom du ");
	ft_putnbr(n);
	ft_putstr("eme element : ");
	ft_putstr(tmp->room->name);
	if (tmp->room->start == 1)
		ft_putstr(" et c'est le depart\n");
	else if (tmp->room->end == 1)
		ft_putstr(" et c'est l'arrivee\n");
	else
		ft_putchar('\n');
	///////////////////// FIND DU CODE DE TEST /////////////////////////////
	return (0);
}
