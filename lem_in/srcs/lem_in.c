/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:13:18 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/10 14:48:21 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_main(t_cut_m *cut)
{
	(*cut).n = 1;
	(*cut).count = 2;
	(*cut).map = NULL;
	(*cut).reseau = NULL;
	(*cut).path = NULL;
	(*cut).path2 = NULL;
	(*cut).tmp2 = NULL;
	(*cut).i = 1;
	read_map(&(cut)->map);
	apply_map_to_tun(&(cut)->map);
	cut->nb_path = nbr_path(&(cut)->map);
	nbr_rooms(&(cut)->map);
	build_first_reseau(&(cut)->reseau, &(cut)->map);
	while (cut->count <= cut->nb_path && g_end_affiche != 2)
	{
		build_reseau(&(cut)->reseau, &(cut)->map, cut->count);
		cut->count++;
	}
	cut->tmp = cut->map;
	cut->tmp4 = cut->reseau;
}

void	affiche_debut(t_cut_m *cut)
{
	ft_printf("\n[0;31;40m=========== START ============\n");
	while (cut->tmp4)
	{
		ft_printf("\n[0;36;40m---------------------- \n Parcours n %d :\n\n",
				cut->tmp4->choix);
		cut->tmp3 = cut->tmp4->path;
		while (cut->tmp3)
		{
			ft_printf("[0;36;40mSalle : [0;37;40m%s\n", cut->tmp3->name);
			cut->tmp3 = cut->tmp3->next;
		}
		cut->tmp4 = cut->tmp4->next;
	}
	ft_printf("\n");
	ft_printf("Il y a [0;35;40m%d [0;37;40mfourmis dans le labyrinthe\n",
			g_lem);
	cut->nb_path = calc_path_n(&(cut)->reseau);
	next_to_previous(&(cut)->reseau);
}

void	affiche_fin(t_cut_m *cut)
{
	while (g_end_affiche != 1)
	{
		avance_lem(&(cut)->reseau, &(cut)->i, cut->n_path);
		cut->n_path = 1;
		while (cut->n_path <= cut->nb_path)
		{
			affiche_path(cut->n_path, &(cut)->reseau);
			cut->n_path++;
		}
		ft_printf("\n");
		g_total++;
	}
	g_total = g_total - 2;
	ft_printf("[0;37;40mIl y a eu [0;35;40m%d [0;37;40mtours", g_total);
	ft_printf("[0;37;40mjusqu'a ce que toutes les fourmis arrivent\n\n");
	ft_printf("[0;31;40m============ END =============\n\n");
}

int		main(void)
{
	t_cut_m		cut;

	init_main(&cut);
	affiche_debut(&cut);
	affiche_fin(&cut);
	return (0);
}
