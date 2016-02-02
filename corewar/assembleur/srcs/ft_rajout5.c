/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rajout5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbeaujou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:50:06 by hbeaujou          #+#    #+#             */
/*   Updated: 2016/01/26 13:51:20 by hbeaujou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	test_no_params(t_tempo **vars)
{
	if ((*vars)->str2[(*vars)->j] == '\0')
	{
		ft_putstr_fd("Missing param\n", 2);
		exit(0);
	}
}

void	test_no_params_2(t_tempo **vars)
{
	if ((*vars)->str2[(*vars)->i] == '\0')
	{
		ft_putstr_fd("Missing param\n", 2);
		exit(0);
	}
}
