/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnb_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsautron <bsautron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 05:51:57 by bsautron          #+#    #+#             */
/*   Updated: 2014/12/03 17:40:51 by bsautron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init(int *nb_out)
{
	nb_out[0] = 0;
	nb_out[1] = 0;
	nb_out[2] = 0;
}

void	ft_none(int *nb_out, t_option *op)
{
	if (op->listed == LISTED)
		nb_out[1] = 1;
	else
		nb_out[2] = 1;
}

int		*ft_getnb_out(char **argv, int argc, t_option *op)
{
	int		i;
	int		*nb_out;
	int		result;

	i = 0;
	nb_out = (int *)malloc(sizeof(int) * 3);
	ft_init(nb_out);
	if (argc)
	{
		while (i < argc)
		{
			result = ft_checkargv(argv[i], op);
			if (result == 1)
				nb_out[1]++;
			else if (result == 2)
				nb_out[2]++;
			else
				nb_out[0]++;
			i++;
		}
	}
	else
		ft_none(nb_out, op);
	return (nb_out);
}
