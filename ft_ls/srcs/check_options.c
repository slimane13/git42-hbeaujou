/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verrif_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 06:41:30 by bsautron          #+#    #+#             */
/*   Updated: 2016/01/12 12:07:47 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_putoption_aux(char op, t_option **t_op)
{
	if (op == 'R')
		(*t_op)->rec = RECURSIVE;
	if (op == 'r')
		(*t_op)->rev = REVERSE;
	if (op == 'a')
		(*t_op)->hide = HIDE;
	if (op == 'A')
		(*t_op)->sup_hide = SUP_HIDE;
	if (op == 'l')
		(*t_op)->format = LONG;
	if (op == '1')
		(*t_op)->format = NO_LONG;
	if (op == 'G')
		(*t_op)->colors = COLORS;
	if (op == 'd')
		(*t_op)->listed = LISTED;
	if (op == 'p')
		(*t_op)->pipe = PIPE;
}

static void	ft_putoption(char op, t_option **t_op)
{
	ft_putoption_aux(op, t_op);
	if (op == 'U')
		(*t_op)->date = DATE_CREATE;
	if (op == 'T')
		(*t_op)->long_date = LONG_DATE;
	if (op == 'g')
	{
		(*t_op)->uid = NO_UID;
		(*t_op)->format = LONG;
	}
	if (op == 't')
		(*t_op)->by = BY_TIME;
	if (op == 'S')
	{
		(*t_op)->by = BY_SIZE;
		(*t_op)->prio_by = BY_SIZE;
	}
	if (op == 'u')
		(*t_op)->date = DATE_ACCES;
	if (op == 'f')
	{
		(*t_op)->stop = STOP;
		if (check != 'a')
			(*t_op)->hide = HIDE;
	}
}

char		ft_check_option(char const *op, t_option **t_op)
{
	char	*options;
	char	*my_op;
	int		i;

	i = 0;
	if (op)
	{
		options = ft_strdup("larARSpTgudGfUt1");
		ft_strsort(options);
		my_op = strdup(&op[1]);
		while (my_op[i])
		{
			if (!ft_charcheck_in_str(my_op[i], options))
				return (my_op[i]);
			if (my_op[i] == 'f' && my_op[i + 1] == 'i')
				check = 'a';
			ft_putoption(my_op[i], t_op);
			i++;
		}
	}
	return (0);
}
