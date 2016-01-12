/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 03:49:02 by bsautron          #+#    #+#             */
/*   Updated: 2016/01/12 09:53:44 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_lstswap(t_dir **a, t_dir **b)
{
	t_dir	*temp;

	temp = ft_lstnew_ls((*a)->buf);
	temp->dossier = (*a)->dossier;
	temp->name = (*a)->name;
	temp->absolute = (*a)->absolute;
	temp->buf = (*a)->buf;
	temp->format = (*a)->format;
	(*a)->dossier = (*b)->dossier;
	(*a)->name = (*b)->name;
	(*a)->absolute = (*b)->absolute;
	(*a)->buf = (*b)->buf;
	(*a)->format = (*b)->format;
	(*b)->dossier = temp->dossier;
	(*b)->name = temp->name;
	(*b)->absolute = temp->absolute;
	(*b)->buf = temp->buf;
	(*b)->format = temp->format;
//	free(temp);
}
