/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/05 13:52:57 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	*map;
	t_map	*tmp;
	t_tun	*tmp2;
	int		n;

	n = 1;
	read_map(&map);
	///////////////////////// DEBUT DU CODE DE TEST ////////////////////////
	tmp = map;
	while (tmp->next)
	{
		ft_putstr("nom de la ");
		ft_putnbr(n);
		ft_putstr("eme salle : ");
		ft_putstr(tmp->room->name);
		if (tmp->room->next != NULL)
		{
			tmp2 = tmp->room->next;
			ft_putstr(" et ses tunnels : ");
			while (tmp2)
			{
				ft_putstr(tmp2->name);
				ft_putchar(' ');
				tmp2 = tmp2->next;
			}
		}
		if (tmp->room->start == 1)
			ft_putstr("et c'est le depart");
		else if (tmp->room->end == 1)
			ft_putstr("et c'est l'arrivee");
		ft_putchar('\n');
		tmp = tmp->next;
		n++;
	}
	ft_putstr("nom de la ");
	ft_putnbr(n);
	ft_putstr("eme salle : ");
	ft_putstr(tmp->room->name);
	if (tmp->room->next != NULL)
	{
		ft_putstr(" et ses tunnels : ");
		ft_putstr(tmp->room->next->name);
	}
	if (tmp->room->start == 1)
		ft_putstr(" et c'est le depart ");
	else if (tmp->room->end == 1)
		ft_putstr(" et c'est l'arrivee ");
	///////////////////// FIND DU CODE DE TEST /////////////////////////////
	return (0);
}
