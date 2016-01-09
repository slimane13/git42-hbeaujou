/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:29:47 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/09 14:52:50 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		nbr_files(t_file **files)
{
	int 	tot;
	t_file	*tmp;

	tmp = *files;
	tot = 0;
	while (tmp)
	{
		tot++;
		tmp = tmp->next;
	}
	return (tot);
}

void	affiche_files(t_file **files, t_flag **flags)
{
//	t_file	*tmp;
//	int		test;

//	tmp = *files;
//	test = recup_flags(flags);
//	if (flags == 0)
		modif_names(files);
		affiche_files_acone(files);
}
