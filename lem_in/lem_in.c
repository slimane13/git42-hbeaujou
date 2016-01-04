/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/04 17:06:35 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_room	*map;
	t_room	*tmp;
	int		n;

	n = 1;
	read_map(&map);
	tmp = map;  //////////// DEBUT DU CODE D AFFICHAGE POUR TEST
	ft_printf("\n");
	while (tmp->next)
	{
		ft_printf("nom du %deme element : %s", n, tmp->name);
		if (tmp->start == 1)
			ft_printf(" et c'est le depart\n");
		else if (tmp->end == 1)
			ft_printf(" et c'est l'arrivee\n");
		else
			ft_printf("\n");
		tmp = tmp->next;
		n++;
	}
	ft_printf("nom du %deme element : %s", n, tmp->name);
	if (tmp->start == 1)
		ft_printf(" et c'est le depart\n");
	else if (tmp->end == 1)
		ft_printf(" et c'est l'arrivee\n");
	else
		ft_printf("\n"); ////////// FIN DU CODE DE TEST
	return (0);
}
