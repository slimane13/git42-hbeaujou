/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/06 18:27:06 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map	*map;
	t_map	*tmp;
	t_tun	*tmp2;
	t_path	*tmp3;
	t_path	*path;
	t_path	*path2;
	int		n;
	int		nb_path;

	n = 1;
	///////////////////////// PARTIE OBLIGATOIRE ///////////////////////////
	read_map(&map);
	apply_map_to_tun(&map);
	nb_path = nbr_path(&map);
	//////////////////////// AJOUT DU PREMIER PATH ////////////////////////
	put_fromend(&map);
	clean_flag(&map);
	tmp = map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	path = fromend_to_path(&tmp);
	clean_flag(&map);
	path_to_flag(&path, &map, 1);
	//////////////////////// AJOUT DU DEUXIEME PATH ///////////////////////
	tmp = map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	put_fromend(&map);
	clean_flag(&map);
	path_to_flag(&path, &map, 1);
	tmp = map;
	while (tmp->room->end != 1)
		tmp = tmp->next;
	tmp->room->flag = 0;
	tmp = map;
	while (tmp->room->start != 1)
		tmp = tmp->next;
	path2 = fromend_to_path(&tmp);
	///////////////////////////// FIN DES PATH ///////////////////////////
	ft_printf("Il y a maximum %d chemins exactement differents\n\n", nb_path);
	//////////////////// AFFICHAGE DE TOUTES LES SALLES ////////////////////
	tmp = map;
	while (tmp->next)
	{
		ft_printf("nom de la %deme salle : %s", n, tmp->room->name);
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
	ft_printf("nom de la %deme salle : %s", n, tmp->room->name);
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
	///////////////// AFFICHAGE DES FROM_END DES SALLES /////////////////////
	tmp = map;
	ft_printf("------------------\n From_end : \n\n");
	while (tmp)
	{
		ft_printf("salle : %s , from_end : %d\n", tmp->room->name, tmp->room->from_end);
		tmp = tmp->next;
	}
	ft_printf("\n");
	///////////////// AFFICHAGE RESOLUTION N1 ///////////////////////////////
	tmp3 = path;
	////////////////// TEST DES FLAGS /////////////////////////////////////
	tmp = map;
	ft_printf("--------------------\n Salles utilisees :\n\n");
	while (tmp)
	{
		if (tmp->room->flag != 0)
			ft_printf("salle : %s avec flag : %d\n", tmp->room->name, tmp->room->flag);
		tmp = tmp->next;
	}
	/////////////////////// TEST PARCOURS VIA PATH ///////////////////////
	ft_printf("\n---------------------- \n Parcours :\n\n");
	while (tmp3)
	{
		ft_printf("salle : %s\n", tmp3->name);
		tmp3 = tmp3->next;
	}
	ft_printf("\n");
	/////////////////////// TEST PARCOURS VIA PATH2 ///////////////////////
	tmp3 = path2;
	ft_printf("\n---------------------- \n Parcours :\n\n");
	while (tmp3)
	{
		ft_printf("salle : %s\n", tmp3->name);
		tmp3 = tmp3->next;
	}
	ft_printf("\n");
	return (0);
}
