/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 19:23:17 by hbeaujou         ###   ########.fr       */
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
		ft_printf("nom du %deme element : %s", n, tmp->room->name);
		if (tmp->room->start == 1)
			ft_printf(" et c'est le depart\n");
		else if (tmp->room->end == 1)
			ft_printf(" et c'est l'arrivee\n");
		else
			ft_printf("\n");
		tmp = tmp->next;
		n++;
	}
	ft_printf("nom du %deme element : %s", n, tmp->room->name);
	if (tmp->room->start == 1)
		ft_printf(" et c'est le depart\n");
	else if (tmp->room->end == 1)
		ft_printf(" et c'est l'arrivee\n");
	else
		ft_printf("\n");
	///////////////////// FIND DU CODE DE TEST /////////////////////////////
	return (0);
}
