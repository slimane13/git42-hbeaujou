/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:12:09 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/13 16:38:55 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_putoption_aux(char op, t_option **t_op)
{
	if (op == 'R')
		(*t_op)->rec = 1;
	if (op == 'r')
		(*t_op)->rev = 1;
	if (op == 'a')
		(*t_op)->hide = 1;
	if (op == 'A')
		(*t_op)->sup_hide = 1;
	if (op == 'l')
		(*t_op)->format = 1;
	if (op == '1')
		(*t_op)->format = 0;
	if (op == 'G')
		(*t_op)->colors = 1;
	if (op == 'd')
		(*t_op)->listed = 1;
	if (op == 'p')
		(*t_op)->pipe = 1;
}

static void	ft_putoption(char op, t_option **t_op)
{
	ft_putoption_aux(op, t_op);
	if (op == 'U')
		(*t_op)->date = 2;
	if (op == 'T')
		(*t_op)->long_date = 1;
	if (op == 'g')
	{
		(*t_op)->uid = 0;
		(*t_op)->format = 1;
	}
	if (op == 't')
		(*t_op)->by = 2;
	if (op == 'S')
	{
		(*t_op)->by = 3;
		(*t_op)->prio_by = 3;
	}
	if (op == 'u')
		(*t_op)->date = 3;
	if (op == 'f')
	{
		(*t_op)->stop = 1;
		if (g_check != 'a')
			(*t_op)->hide = 1;
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
				g_check = 'a';
			ft_putoption(my_op[i], t_op);
			i++;
		}
	}
	return (0);
}
