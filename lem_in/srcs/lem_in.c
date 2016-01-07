/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/07 16:40:42 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	t_map		*map;
	t_map		*tmp;
	t_tun		*tmp2;
	t_path		*tmp3;
	t_path		*path;
	t_path		*path2;
	t_reseau	*tmp4;
	t_reseau	*reseau;
	int			n;
	int			count;
	int			nb_path;

	n = 1;
	count = 2;
	reseau = NULL;
	path = NULL;
	path2 = NULL;
	///////////////////////// PARTIE OBLIGATOIRE ///////////////////////////
	read_map(&map);
	apply_map_to_tun(&map);
	nb_path = nbr_path(&map);
	//////////////////////// AJOUT DU PREMIER PATH ////////////////////////
	build_first_reseau(&reseau, &map);
	//////////////////////// AJOUT DES AUTRES PATH ///////////////////////
	while (count <= nb_path)
	{
		build_reseau(&reseau, &map, count);
		count++;
	}
	tmp = map;
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
	///////////////// AFFICHAGE DES FROM_END RESTANTS /////////////////////
	tmp = map;
	ft_printf("------------------\n From_end : \n\n");
	while (tmp)
	{
		ft_printf("salle : %s , from_end : %d\n", tmp->room->name, tmp->room->from_end);
		tmp = tmp->next;
	}
	ft_printf("\n");
	/////////////////////// TEST PARCOURS VIA RESEAU ///////////////////////
	ft_printf("\n---------------------- \n Via reseau :\n\n");
	tmp4 = reseau;
	while (tmp4)
	{
		ft_printf("\n---------------------- \n Parcours n %d :\n\n", tmp4->choix);
		tmp3 = tmp4->path;
		while (tmp3)
		{
			ft_printf("Salle : %s\n", tmp3->name);
			tmp3 = tmp3->next;
		}
		tmp4 = tmp4->next;
	}
	ft_printf("\n");
	///////////////////////// AFFICHAGE DES FOURMIS /////////////////////////
	ft_printf("Il y a %d fourmis dans le labyrinthe\n\n", g_lem);
	next_to_previous(&reseau);
	int i = 0;
	int n_path;
	while (i < g_lem)
	{
		avance_lem(&reseau, i);
		n_path = 1;
		while (n_path <= nb_path)
		{
			affiche_path(n_path, &reseau);
			ft_printf(" ");
			n_path++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}
