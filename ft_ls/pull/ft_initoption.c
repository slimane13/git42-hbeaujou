/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initoption.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:52:08 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 22:51:27 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_initoption(t_option **t_op)
{
	(*t_op)->rec = NO_RECURSIVE;
	(*t_op)->rev = NO_REVERSE;
	(*t_op)->hide = NO_HIDE;
	(*t_op)->sup_hide = NO_SUP_HIDE;
	(*t_op)->by = BY_NAME;
	(*t_op)->prio_by = BY_NAME;
	(*t_op)->format = NO_LONG;
	(*t_op)->colors = NO_COLORS;
	(*t_op)->listed = NO_LISTED;
	(*t_op)->date = DATE_MODIF;
	(*t_op)->pipe = NO_PIPE;
	(*t_op)->stop = NO_STOP;
	(*t_op)->uid = UID;
	(*t_op)->long_date = NO_LONG_DATE;
}
