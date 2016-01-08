/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/08 10:01:09 by hbeaujou         ###   ########.fr       */
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
	tmp2 = NULL;
	///////////////////////// PARTIE OBLIGATOIRE ///////////////////////////
	read_map(&map);
	apply_map_to_tun(&map);
	nb_path = nbr_path(&map);
	//////////////////////// AJOUT DU PREMIER PATH ////////////////////////
	build_first_reseau(&reseau, &map);
	//////////////////////// AJOUT DES AUTRES PATH ///////////////////////
	while (count <= nb_path && g_end_affiche != 2)
	{
		build_reseau(&reseau, &map, count);
		count++;
	}
	tmp = map;
	///////////////////////////// FIN DES PATH ///////////////////////////
//	ft_printf("\nIl y a maximum %d chemins exactement differents\n\n", nb_path);
	//////////////////// AFFICHAGE DE TOUTES LES SALLES ////////////////////
/*
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
*/
	///////////////// AFFICHAGE DES FROM_END RESTANTS /////////////////////
/*
	tmp = map;
	ft_printf("------------------\n From_end : \n\n");
	while (tmp)
	{
		ft_printf("salle : %s , from_end : %d\n", tmp->room->name, tmp->room->from_end);
		tmp = tmp->next;
	}
*/
	/////////////////////// TEST PARCOURS VIA RESEAU ///////////////////////
	tmp4 = reseau;
	ft_printf("\n[0;31;40m=========== START ============\n");
	while (tmp4)
	{
		ft_printf("\n[0;36;40m---------------------- \n Parcours n %d :\n\n", tmp4->choix);
		tmp3 = tmp4->path;
		while (tmp3)
		{
			ft_printf("[0;36;40mSalle : [0;37;40m%s\n", tmp3->name);
			tmp3 = tmp3->next;
		}
		tmp4 = tmp4->next;
	}
	ft_printf("\n");
	///////////////////////// AFFICHAGE DES FOURMIS /////////////////////////
	ft_printf("Il y a [0;35;40m%d [0;37;40mfourmis dans le labyrinthe\n", g_lem);
	nb_path = calc_path_n(&reseau);
	next_to_previous(&reseau);
	int i = 1;
	int n_path;
	while (g_end_affiche != 1)
	{
		avance_lem(&reseau, &i, n_path);
		n_path = 1;
		while (n_path <= nb_path)
		{
			affiche_path(n_path, &reseau);
			n_path++;
		}
		ft_printf("\n");
		g_total++;
	}
	g_total = g_total - 2;
	ft_printf("[0;37;40mIl y a eu [0;35;40m%d [0;37;40mtours jusqu'a ce que toutes les fourmis arrivent\n\n", g_total);
	ft_printf("[0;31;40m============ END =============\n\n");
	return (0);
}
