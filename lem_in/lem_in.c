/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 13:58:51 by hbeaujou         ###   ########.fr       */
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
	apply_map_to_tun(&map);
	put_fromend(&map);
	///////////////////////// DEBUT DU CODE DE TEST ////////////////////////
	tmp = map;
	ft_printf("Il y a maximum %d chemins exactement differents\n\n", nbr_path(&map));
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
				ft_putstr(tmp2->p_map->room->name);
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
			tmp2 = tmp->room->next;
			ft_putstr(" et ses tunnels : ");
			while (tmp2)
			{
				ft_putstr(tmp2->p_map->room->name);
				ft_putchar(' ');
				tmp2 = tmp2->next;
			}
	}
	if (tmp->room->start == 1)
		ft_putstr("et c'est le depart ");
	else if (tmp->room->end == 1)
		ft_putstr("et c'est l'arrivee ");
	ft_printf("\n\n");
	tmp = map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	///////////////// CODE DE RESOLUTION ///////////////////////////////////
//	/*
	ft_printf("Salle de start : %s\n", tmp->room->name);
	ft_printf("---------------------------------\n");
	while (tmp->room->end != 1)
	{
		ft_printf("Coups de la fin : %d depuis la salle : %s\n", tmp->room->from_end, tmp->room->name);
		if (tmp->room->next->p_map->room->from_end < tmp->room->from_end)
			tmp = tmp->room->next->p_map;
		else
			tmp = tmp->room->next->next->p_map;
	}
	ft_printf("Arrivee a la salle : %s\n\n", tmp->room->name);
//	*/
	///////////////////// FIND DU CODE DE TEST /////////////////////////////
	return (0);
}
